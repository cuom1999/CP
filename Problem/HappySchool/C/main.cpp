#include <iostream>
using namespace std;
int hang , cot , f[300][30] ;
char a[501][501] , b[501][501];
int main()
{
    cin >> hang >> cot;
    for (int i = 1 ; i <= hang ; i++)
    {
        for (int e = 1 ; e <= cot ; e++)
        {
            cin >> a[i][e];
            f[a[i][e]][1]++;
        }
    }
    for (int i = 1 ; i <= hang ; i++)
    {
        for (int e = 1 ; e <= cot ; e++)
        {
            cin >> b[i][e];
            f[b[i][e]][2]++;
        }
    }
    int result = 0;
    for (int i = 'a' ; i <= 'z' ; i++)
    {
        result += max(0 , f[i][1] - f[i][2]);
    }
    cout << result;
}