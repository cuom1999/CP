#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int ALPHABET_SIZE=26;

class Trie{
private:
    struct node{
        node *children [ALPHABET_SIZE];
        node *parent;
        bool IsEndOfWord;
        bool IsLeaf;
        node (){
            parent=NULL;
            FOR (i,0,25) children[i]=NULL;
            IsEndOfWord=0;
            IsLeaf=1;
        }
    };
    node *Root=new node();
public:
    void insert(string key){
        node *Current_Node=Root;
        for (int i=0; i<key.size(); i++){
            int index=key[i]-'a';
            Current_Node->IsLeaf=0;
            if (Current_Node->children[index]==NULL) {
                Current_Node->children[index]=new node();
                Current_Node->children[index]->parent=Current_Node;
            }
            Current_Node=Current_Node->children[index];
        }
        Current_Node->IsEndOfWord=1;
        Current_Node->IsLeaf=1;
    }
    bool find(string key) {
        node *Current_Node=Root;
        for (int i=0; i<key.size(); i++){
            int index=key[i]-'a';
            if (Current_Node->children[index]==NULL) return 0;
            else Current_Node=Current_Node->children[index];
        }
        if (Current_Node==NULL) return 0;
        return Current_Node->IsEndOfWord;
    }
    void clear(){
        Root=new node();
    }
    void erase (string key){
        node *Current_Node=Root;
        for (int i=0; i<key.size(); i++){
            int index=key[i]-'a';
            if (Current_Node->children[index]==NULL) return ;
            else Current_Node=Current_Node->children[index];
        }
        if (Current_Node==NULL) return ;
        if (!Current_Node->IsEndOfWord) return;
        Current_Node->IsEndOfWord=0;
        while (Current_Node->IsLeaf && Current_Node!=Root){
            node * cmp=Current_Node;
            Current_Node=Current_Node->parent;
            cmp=NULL;
        }
    }
};

Trie S;
string s;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    cin>>n;
    FOR (i,1,n) {
        cin>>s;
        S.insert(s);
    }
    ll m;
    cin>>m;
    FOR (i,1,m) {
        cin>>s;
        if (!S.find(s)) cout<<s<<" ";
    }
    cout<<endl;
    cin>>n;
    FOR (i,1,n) {cin>>s;S.erase(s);}
    cin>>n;
    FOR (i,1,n){
        cin>>s;
        S.erase(s);
    }

    return 0;
}
