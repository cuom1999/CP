#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 31, 50) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll k = Rand(1, 40);
        ll n = Rand(1, 100 / k) * k;        
        inp << n << " " << k << "\n";
    }
    
    
    return 0;
}