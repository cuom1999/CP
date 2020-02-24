#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 71, 80) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll n = Rand(90000, 100000);
        ll k = Rand(1, 20);
        inp << n << " " << k << endl;
    }
    
    
    return 0;
}