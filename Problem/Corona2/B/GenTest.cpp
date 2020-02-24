#include "lib.h"

typedef pair<int, int> II;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 51, 60) {
        ofstream inp = inpFile(i);
        // write using to file inp
        int cnt[4];
        FOR (i, 1, 3) {
            cnt[i] = Rand(6, 6);
            inp << cnt[i] << " ";
        }
        inp << "\n";

        FOR (i, 1, 3) {
            vector<II> v;
            FOR (j, 1, 6) {
                v.pb({j, Rand(1, 20)});
            }

            shuffle(all(v), gen);
            FOR (j, 0, cnt[i] - 1) {
                inp << v[j].first << " " << v[j].second << "\n";
            }
        }
    }
    
    
    return 0;
}