#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;

int n, res;
string s;
vector<int> ke[maxn];
bool b[maxn][maxn], dd[maxn];

bool check(int i, int j, int k)
{
    if((b[i][j] && b[j][k] && b[k][i]) || (b[i][k] && b[k][j] && b[j][i]))
    {
        dd[i] = true;
        dd[j] = true;
        dd[k] = true;
        return true;
    }
    return false;
}

void legendary_buffalo()
{
    for(int i = 1; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
           for(int k = j + 1; k <= n; k++)
                check(i,j,k);
    for(int i = 1; i <= n; i++) if(dd[i]) res++;
    cout << res;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("RPS.inp","r",stdin); freopen("RPS.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int  j = 0; j < s.size(); j++)
            if(s[j] == '1') b[i][j + 1] =true;
    }
    legendary_buffalo();
}
