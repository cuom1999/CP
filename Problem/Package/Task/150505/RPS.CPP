#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int limit=2*1e3+1000;
vector<int>connect[limit];
vector<int>reconnect[limit];
int n;
bool bigger[limit][limit];
char a[limit][limit];
void in()
{
    scanf("%d\n",&n);
    for (int y=1;y<=n;y++)
    {
        for (int x=1;x<=n;x++)
        {
            scanf("%c",&a[x][y]);
            if (a[x][y]=='1') connect[y].push_back(x),bigger[y][x]=true,bigger[x][y]=false;
            else if (x!=y) reconnect[y].push_back(x),bigger[y][x]=false,bigger[x][y]=true;
        }
        scanf("\n");
    }
    //cout<<a[2][3]<<endl;
}
bool illegal(int x)
{
    //cout<<"CHECKING "<<x<<endl;
    for (int i=0;i<connect[x].size();i++)
        for (int j=0;j<reconnect[x].size();j++)
        {
            int First=connect[x][i];
            int Second=reconnect[x][j];
            //cout<<First<<" vs "<<Second<<endl;
            if (bigger[First][Second]) return false;
        }
    //cout<<"OUT "<<endl;
    return true;
}
void so()
{
    int res=n;
    for (int i=1;i<=n;i++) res-=illegal(i);
    printf("%d",res);
}
int main()
{
    freopen("rps.inp","r",stdin);
    freopen("rps.out","w",stdout);
    in();
    so();
}
