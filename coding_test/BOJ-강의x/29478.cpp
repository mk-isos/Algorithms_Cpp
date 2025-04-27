// 맛있는 케이크

// 못풀겠음

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct Point
{
    double x, y;
    Point operator-(const Point &p) const { return {x - p.x, y - p.y}; }
    Point operator+(const Point &p) const { return {x + p.x, y + p.y}; }
    Point operator*(double k) const { return {x * k, y * k}; }
};

int main()
{
    FIO;
    int N, M;
    cin >> N >> M;

    vector<Point> poly(M);
    for (int i = 0; i < M; i++)
    {
        cin >> poly[i].x >> poly[i].y;
    }

    Point origin = poly[0];

    if (N == 2)
    {
        cout << "3\n";
        cout << origin.x << " " << origin.y << "\n";
        cout << poly[1].x << " " << poly[1].y << "\n";
        if (M > 3)
        {
            cout << poly[M / 2].x << " " << poly[M / 2].y << "\n";
        }
        else
        {
            cout << poly[2].x << " " << poly[2].y << "\n";
        }
        cout << "3\n";
        cout << origin.x << " " << origin.y << "\n";
        if (M > 3)
        {
            cout << poly[M / 2].x << " " << poly[M / 2].y << "\n";
        }
        else
        {
            cout << poly[2].x << " " << poly[2].y << "\n";
        }
        cout << poly[M - 1].x << " " << poly[M - 1].y << "\n";
        return 0;
    }

    if (N == 3)
    {
        cout << "3\n";
        cout << origin.x << " " << origin.y << "\n";
        cout << poly[1].x << " " << poly[1].y << "\n";
        cout << poly[M / 3].x << " " << poly[M / 3].y << "\n";
        cout << "3\n";
        cout << origin.x << " " << origin.y << "\n";
        cout << poly[M / 3].x << " " << poly[M / 3].y << "\n";
        cout << poly[2 * M / 3].x << " " << poly[2 * M / 3].y << "\n";
        cout << "3\n";
        cout << origin.x << " " << origin.y << "\n";
        cout << poly[2 * M / 3].x << " " << poly[2 * M / 3].y << "\n";
        cout << poly[M - 1].x << " " << poly[M - 1].y << "\n";
        return 0;
    }

    int verticesPerPiece = (M - 1) / N;
    int remainder = (M - 1) % N;

    int currentVertex = 1;
    for (int i = 0; i < N; i++)
    {
        int pieceVertices = verticesPerPiece + (i < remainder ? 1 : 0);
        int endVertex = currentVertex + pieceVertices;
        if (endVertex > M)
            endVertex = M;

        cout << pieceVertices + 1 << "\n";
        cout << origin.x << " " << origin.y << "\n";

        for (int j = currentVertex; j < endVertex; j++)
        {
            cout << poly[j].x << " " << poly[j].y << "\n";
        }

        currentVertex = endVertex;
    }

    return 0;
}
