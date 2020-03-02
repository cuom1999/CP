#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 4, 20) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll MAXA = i;
        ll n = Rand(1, i);
        ll a = Rand(1, MAXA);
        ll b = Rand(1, MAXA);
        inp << n << " " << a << " " << b << "\n";
        FOR (i, 1, n) {
            inp << Rand(-MAXA, MAXA) << " " << Rand(-MAXA, MAXA) << " ";
            inp << Rand(-MAXA, MAXA) << " " << Rand(-MAXA, MAXA) << "\n";
        }
    }
    
    
    return 0;
}