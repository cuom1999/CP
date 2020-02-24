#include <bits/stdc++.h>
using namespace std;
ifstream fi("rps.inp");
ofstream fo("rps.out");

int n, res;
char ch[2001][2001];
void sub1()
{
    res = 0;
    for(int i = 1; i <= n; i++)
    {
        bool ok = false;
        for(int j = 1; j <= n; j++)
        {
            if(j != i)
            {
                for(int k = 1; k <= n; k++)
                {
                    if(k != j && k != i)
                    {
                        if((ch[i][j] == '1' || ch[j][i] == '0') && (ch[j][k] == '1' || ch[k][j] == '0') && (ch[k][i] == '1' || ch[i][k] == '0'))
                        {
                            ok = true;
                            break;
                        }
                    }
                }
                if(ok) break;
            }
        }
        if(ok) res++;
    }
    fo << res << endl;
}

bool dx[20001];
int sl = 0;
vector<int> ke[20001];
bool ok = false;
void sub2()
{
    for(int i = 1; i <= n; i++)
    {
        bool ok = false;
        for(int j = 0; j < ke[i].size(); j++)
        {
            int k = ke[i][j];
            for(int k1 = 0; k1 < ke[k].size(); k1++)
            {
                int k2 = ke[k][k1];
                for(int k3 = 0; k3 < ke[k2].size(); k3++)
                {
                    if(ke[k2][k3] == i)
                    {
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) break;
        }
        if(ok) res++;
    }
    fo << res;
}

int main()
{
    fi >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) fi >> ch[i][j];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(ch[i][j] == '1' && i != j)
            {
                ke[i].push_back(j);
            }
        }
    }
    if(n <= 200) sub1();
    else sub2();
}
