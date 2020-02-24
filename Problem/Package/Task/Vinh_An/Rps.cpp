#include <bits/stdc++.h>
using namespace std;

class Game{
public:
    vector <int> ip1,ip2;
    int win=0,lose=0;
    bool Check(){
        return (win<=0||lose<=0);
    }
};

const int maxn=2001;
bool C[maxn];
Game A[maxn];
int n,dem;

void solve(){
    for(int i=1;i<=n;i++){
        if(A[i].Check()&&C[i]==0){
            deque <int> H;
            H.push_back(i);
            C[i]=1;
            dem--;
            while(!H.empty()){
                int k=H.front();

                int L;
                L=A[k].win-1;
                for(int j=0;j<=L;j++){
                    int  h=A[k].ip1[j];
                    if(C[h]==0){
                        A[h].lose--;
                        if(A[h].Check()){
                            H.push_back(h);
                            C[h]=1;
                            dem--;
                        }
                    }
                }

                L=A[k].lose-1;
                for(int j=0;j<=L;j++){
                    int h=A[k].ip2[j];
                    if(C[h]==0){
                        A[h].win--;
                        if(A[h].Check()){
                            H.push_back(h);
                            C[h]=1;
                            dem--;
                        }
                    }
                }
                H.pop_front();
            }
        }
    }
}

int main(){
    freopen("Rps.inp","r",stdin);
    freopen("Rps.out","w",stdout);
    cin>>n;
    dem=n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        s=' '+s;
        for(int j=1;j<=n;j++){
            if(s[j]=='1'){
                A[i].ip1.push_back(j);
                A[i].win++;
            }else{
                if(i!=j){A[i].ip2.push_back(j);
                A[i].lose++;}
            }
        }
    }
    solve();
    cout<<dem;
}
