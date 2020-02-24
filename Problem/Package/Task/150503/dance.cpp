 #include<bits/stdc++.h>
 long long w,n,i,j,h,k,t,d,l,m,f[11][70007],p[11][30003];
 using namespace std;
 int main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("dance.inp","r",stdin);
    freopen("dance.out","w",stdout);
    cin>>n>>l>>m>>w;
    for(i=1;i<=m;i++) for(j=1;j<=n;j++) cin>>f[i][j];
    for(i=1;i<=m;i++) for(j=1;j<=l;j++) cin>>p[i][j];
    for(i=l;i<=n;i++)
    {
        h=0;
        for(t=1;t<=m;t++) for(j=1;j<=l;j++) h+=p[t][j]*f[t][i-l+j];
        if (h>w) d++;
    }
    cout<<d;
 }
