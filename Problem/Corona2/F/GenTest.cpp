#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 41, 50) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll t = Rand(100, 100);
        inp << t << '\n';
        FOR (i, 1, t) {
            inp << Rand(-1000000, 1000000);
        }
    }
    
    
    return 0;
}