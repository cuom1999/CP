#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
long long l,r;
int t;
bool dx[1501];
vector<int>v;
template <typename T> inline void read(T &x){
    char c;bool nega=false;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-'){
        nega=1;
        c=getchar();
    }

    x=c-48;
    while(isdigit(c=getchar()))x=x*10+c-48;

    if(nega)x=-x;
}
bool kt(long long x)
{
   int y=0;
   while(x>0)
   {
      y+=(x%10)*(x%10);
      x/=10;
   }
   if(dx[y]) return false;
   if(y==1) return true;
   dx[y]=1;
   v.push_back(y);
   kt(y);
}
int main()
{
    freopen("pearl.inp","r",stdin);
    freopen("pearl.out","w",stdout);
    read(t);
    while(t--)
    {
       read(l);read(r);
       int dem=0;
       for(long long i=l;i<=r;i++)
         {
            if(!kt(i))
            dem++;
            for(int j:v) dx[j]=0;
            v.clear();
         }
      cout<<dem<<'\n';
    }

}
