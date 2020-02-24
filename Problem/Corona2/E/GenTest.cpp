#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 21, 40) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll n = Rand(1, 20000);
        ll m = Rand(1, 20);
        inp << n << " " << m << "\n";
        FOR (i, 1, n) {
            FOR (j, 1, m) {
                inp << Rand(0, 1);
            }
            inp << "\n";
        }
    }
    
    
    return 0;
}