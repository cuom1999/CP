#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 51, 60) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll n = Rand(100000, 100000);
        ll MAXA = 5000;
        inp << n << "\n";
        FOR (i, 1, n) {
            inp << Rand(1, MAXA) << " ";
        }
        inp << "\n";
        FOR (i, 1, n) {
            inp << Rand(1, MAXA) << " ";
        }
    }
    
    
    return 0;
}