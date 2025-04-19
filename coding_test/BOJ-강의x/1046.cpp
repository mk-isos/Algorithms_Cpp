#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long double ld;

int h, w, countWall = 0;
vector<string> box;
vector<pair<ld, ld>> p;
ld lightX, lightY;
int startX, startY;

void search(int x, int y, pair<ld, ld> pos, pair<int, ld> angle)
{
    if (x < 0 || x >= w || y < 0 || y >= h || box[y][x] == '#')
    {
        p.push_back(pos);
        return;
    }

    int x1 = (angle.first > 0) ? x + 1 : x - 1;
    int x2 = (angle.first > 0) ? x + 1 : x;
    int y1 = (angle.first * angle.second > 0) ? y + 1 : y - 1;
    int y2 = (angle.first * angle.second > 0) ? y + 1 : y;

    ld ynx = pos.second + (angle.second) * (x2 - pos.first);
    ld xny = pos.first + ((y2 - pos.second) / (angle.second));

    if (y + 1e-7 < ynx && ynx < y + 1 - 1e-7 && (xny < x - 1e-7 || xny > x + 1 + 1e-7))
    {
        pos = {x2, ynx};
        search(x1, y, pos, angle);
    }
    else if (x + 1e-7 < xny && xny < x + 1 - 1e-7 && (ynx < y - 1e-7 || ynx > y + 1 + 1e-7))
    {
        pos = {xny, y2};
        search(x, y1, pos, angle);
    }
    else
    {
        pos = {x2, y2};
        if (angle.second > 0 && (x1 < 0 || x1 >= w || box[y][x1] == '#'))
            p.push_back(pos);
        if (angle.second < 0 && (y1 < 0 || y1 >= h || box[y1][x] == '#'))
            p.push_back(pos);
        search(x1, y1, pos, angle);
        if (angle.second > 0 && (y1 < 0 || y1 >= h || box[y1][x] == '#'))
            p.push_back(pos);
        if (angle.second < 0 && (x1 < 0 || x1 >= w || box[y][x1] == '#'))
            p.push_back(pos);
    }
}

int main()
{
    FIO;
    cin >> h >> w;
    box.resize(h);

    for (int i = 0; i < h; ++i)
    {
        cin >> box[i];
        for (int j = 0; j < w; ++j)
        {
            if (box[i][j] == '*')
            {
                startX = j;
                startY = i;
                lightX = j + 0.5;
                lightY = i + 0.5;
            }
            if (box[i][j] == '#')
                countWall++;
        }
    }

    vector<pair<int, ld>> slopeList;

    for (int i = 0; i <= h; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            if (j == lightX)
                continue;
            int dir = (j - lightX > 0) ? 1 : -1;
            ld slope = (i - lightY) / (j - lightX);
            slopeList.emplace_back(dir, slope);
        }
    }

    sort(slopeList.begin(), slopeList.end());
    slopeList.erase(unique(slopeList.begin(), slopeList.end()), slopeList.end());

    for (auto slope : slopeList)
    {
        search(startX, startY, {lightX, lightY}, slope);
    }

    ld result = 0;
    int sz = p.size();
    for (int i = 0; i < sz; ++i)
    {
        int j = (i + 1) % sz;
        result += abs((lightX * p[i].second + p[i].first * p[j].second + p[j].first * lightY) -
                      (p[i].first * lightY + p[j].first * p[i].second + lightX * p[j].second)) /
                  2;
    }

    cout << fixed << setprecision(13) << (w * h - result - countWall) << '\n';
}
