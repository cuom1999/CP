#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forc(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int m,n,x,w,a[12][70001],b[12][30001],dem,tong;
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
void test()
{
   freopen("dance.inp","w",stdout);
   srand(time(NULL));
   n=10001,m=11,x=3000,w=1232456478;
   cout<<n<<" "<<x<<" "<<m<<" "<<w<<'\n';
   For(i,1,m)
   {
      For(j,1,n)
      cout<<rand()%101<<" ";
      cout<<'\n';
   }
   cout<<'\n';
   For(i,1,m)
   {
      For(j,1,x)
      cout<<rand()%101<<" ";
      cout<<'\n';
   }
}
void trau()
{
   dem=0;
   Forc(i,n-x+1,1)
   {
      int tong=0;
      For(p,1,m)
      {
         Forc(q,i+x-1,i)
         {
            tong+=b[p][q-i+1]*a[p][q];
            if(tong>w)
            {
               dem++;
               goto go;
            }
         }
      }
      go:;
   }
   cout<<dem;
}
void xl()
{
   read(n);read(x);read(m);read(w);
   For(i,1,m)
      For(j,1,n)
         read(a[i][j]);
    For(i,1,m)
      For(j,1,x)
         read(b[i][j]);
   trau();
}
int main()
{
    //test();
    freopen("dance.inp","r",stdin);
    freopen("dance.out","w",stdout);
    xl();


}
