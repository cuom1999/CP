#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define pi pair<int , int>
inline long double dist(pi p1 , pi p2)
{
    long double x1 = p1.first , y1 = p1.second;
    long double x2 = p2.first , y2 = p2.second;
    return sqrt((x2-x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
inline int area(pi p1 , pi p2 , pi p3)
{
    long double p = (dist(p1 , p2) + dist(p2 , p3) + dist(p3 , p1)) / 2.0;
    return round(2*sqrt(p * (p - dist(p1 , p2)) * (p - dist(p2 , p3)) * (p - dist(p3 , p1))));
}
int main()
{   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    pi p1 , p2;
    p1 = pi(min(x1 , x2) , min(y1 , y2));
    p2 = pi(max(x1 , x2) , max(y1 , y2));

    pi p3 , p4 , p5 , p6;

    cin >> p3.first >> p3.second >> p4.first >> p4.second >> p5.first >> p5.second;

    cin >> p6.first >> p6.second;

    int r;
    cin >> r;
    long double k = r;

    long long kq = 0;
    for (int i = -1000 ; i <= 1000 ; i++)
    {
        for (int e = -1000 ; e <= 1000 ; e++)
        {
            if (i >= p1.first && i <=p2.first && e >= p1.second && e <= p2.second)
            {
                kq++;
            }
            else
            {
                int A = area(p3 , p4 , p5);
                pi spp = pi(i , e);
                if (abs(area(spp , p3 , p4) + area(spp , p4 , p5) + area(spp , p5 , p3) - A) <= 0.000000001)
                {
                    kq++;
                }
                else
                {
                    if (dist(spp ,  p6) <= k)
                    {
                        kq++;
                    }
                }
            }
        }
    }
    cout << kq;
}