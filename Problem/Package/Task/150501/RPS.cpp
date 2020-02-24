#include <bits/stdc++.h>
using namespace std;
int kq,cd,y[2001];
char m[2001][2001];
int in[2001],out[2001];
vector <int> ruler[2001];
vector <int> large,q;
void inp()
{
    cin >> cd;
    for (int i = 1 ; i <=cd ; i++)
        for (int e = 1 ; e <= cd ; e++) cin >> m[i][e];
}
void check(int h)
{
    for (int i = 1 ; i <= cd ; i++)
    {
        if (m[h][i] == '1')
        {
            for (int e = 1 ; e <= cd ; e++)
            {
                if (m[i][e] == '1' && m[e][h] == '1') {kq++ ; return;}
            }
        }
    }
}

void trau()
{
    for (int i = 1 ; i <= cd ; i++)
    {
        check(i);
    }
    cout << kq;
}
main()
{
    freopen("RPS.INP","r",stdin);
    freopen("RPS.OUT","w",stdout);
    inp();
    if (cd <= 200) trau();
}
