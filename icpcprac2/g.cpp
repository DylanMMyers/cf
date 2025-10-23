#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
// Get-Content t.txt | .\g.exe

ld dist(ld x1, ld x2, ld y1, ld y2) {
    return ((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

ld dot(ld leftx, ld rightx, ld lefty, ld righty, ld xanchor, ld yanchor) {
    ld v1x = xanchor - leftx, v1y = yanchor - lefty;
    ld v2x = xanchor - rightx, v2y = yanchor - righty;
    return (v2x * v1x) + (v2y * v1y);
}

ld slope(ld x1, ld x2, ld y1, ld y2) {
    if (x2 - x1 == 0.0) return numeric_limits<ld>::max();
    return (y2 - y1) / (x2 - x1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<ld, ld>> points(4);
    for (int i = 0; i < 4; i++) {
        cin >> points[i].first >> points[i].second;
    }
    vector<ld> sides(4);
    for (int i = 0; i < 4; i++) {
        sides[i] = dist((ld)points[i].first, (ld)points[(i + 1) % 4].first, (ld)points[i].second, (ld)points[(i + 1) % 4].second);
    }
    vector<ld> dots(4);
    for (int i = 0; i < 4; i++) {
        ld leftidx = i - 1;
        if (leftidx == -1) leftidx = 3;
        dots[i] = dot(points[leftidx].first, points[(i + 1) % 4].first, points[leftidx].second, points[(i + 1) % 4].second, points[i].first, points[i].second);
    }
    vector<ld> slopes(4);
    for (int i = 0; i < 4; i++) {
        slopes[i] = slope(points[i].first, points[(i + 1) % 4].first, points[i].second, points[(i + 1) % 4].second);
    }
    bool p1 = (abs(slopes[0]) == abs(slopes[2])), p2 = (abs(slopes[1]) == abs(slopes[3]));
    bool sym = false;
    for (int i = 0; i < 4; i++) {
        // for each anchor, check if
        int lu = i - 1, lb = i - 2, ru = i, rd = (i + 1) % 4;
        if (lu == -1) lu = 3;
        if (lb == -1) lb = 3;
        if (lb == -2) lb = 2;
        if (dots[lu] == dots[rd] && sides[lu] == sides[ru] && sides[lb] == sides[rd]) sym = true;
    }
    bool sideequal = (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3] && sides[3] == sides[0]);
    bool dotsum = true;
    for (int i = 0; i < 4; i++) {
        if (dots[i] != 0) dotsum = false;
    }
    if (sideequal && dotsum) {
        cout << "square";
    }
    else if (dotsum) {
        cout << "rectangle";
    }
    else if (sideequal) {
        cout << "rhombus";
    }
    else if (p1 && p2) {
        cout << "paraldelogram";
    }
    else if (p1 || p2) {
        cout << "trapezium";
    }
    else if (sym) {
        cout << "kite";
    }
    else {
        cout << "none";
    }
}