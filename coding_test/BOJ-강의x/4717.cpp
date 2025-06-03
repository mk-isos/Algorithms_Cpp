#include <bits/stdc++.h>
using namespace std;

struct Circle
{
    double x, y, r;
};

bool inside(double px, double py, const Circle &c)
{
    double dx = px - c.x;
    double dy = py - c.y;
    return dx * dx + dy * dy <= c.r * c.r;
}

int main()
{
    cout << fixed << setprecision(2);
    int N;
    while (cin >> N && N != 0)
    {
        vector<Circle> circles(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        Circle metro = circles[0]; // 도심 영역
        vector<Circle> towers(circles.begin() + 1, circles.end());

        int total = 0, covered = 0;
        mt19937 rng(42); // 고정된 난수 생성기 (재현성 위해)
        uniform_real_distribution<double> distX(metro.x - metro.r, metro.x + metro.r);
        uniform_real_distribution<double> distY(metro.y - metro.r, metro.y + metro.r);

        const int SAMPLES = 1000000;
        for (int i = 0; i < SAMPLES; ++i)
        {
            double px = distX(rng), py = distY(rng);
            if (!inside(px, py, metro))
                continue;
            ++total;

            for (auto &t : towers)
            {
                if (inside(px, py, t))
                {
                    ++covered;
                    break;
                }
            }
        }

        if (total == 0)
            cout << "0.00\n";
        else
            cout << (double)covered / total << '\n';
    }
    return 0;
}
