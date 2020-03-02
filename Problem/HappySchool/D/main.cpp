#include <iostream>
#include <algorithm>
using namespace std;
int cd , a[200001] , c[200001] , b[200001];
void update(int x , int y)
{
    while (x < 200001)
    {
        b[x] = max(b[x] , y);
        x += x & (-x);
    }
}
int get(int x)
{
    int kq = 0;
    while (x > 0)
    {
        kq = max(kq , b[x]);
        x -= x & (-x);
    }
    return kq;
}
int main()
{
    int kq = 0;
    cin >> cd;
    for (int i = 1 ; i <= cd ; i++)
    {
        cin >> a[i];
    }
    for (int i = 1 ; i <= cd ; i++)
    {
        cin >> c[i];
        if (a[i] >= c[i])
        {
            kq++;
        }
    }
    
    for (int i = 1 ; i <= cd ; i++)
    {

        if (a[i] < c[i])
        {
            if (get(a[i]) >= c[i])
            {
                kq++;
                break;
            }
        }
        update(c[i] , a[i]);
    }
    cout << kq;
}