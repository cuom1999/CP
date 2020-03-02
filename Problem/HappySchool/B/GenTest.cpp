#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 31, 35) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll n = Rand(1, 5);
        inp << n << "\n";
        FOR (i, 1, n) {
            ll m = Rand(1, 100000);
            inp << m << "\n";
            FOR (j, 1, m) {
                inp << Rand(1, 10) << " ";
            }
        }
    }
    
    
    return 0;
}