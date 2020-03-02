#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 81, 90) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll n = Rand(500, 500);
        ll m = Rand(500, 500);
        inp << n << " " << m << "\n";
        FOR (i, 1, n) {
            FOR (j, 1, m) {
                inp << (char) (Rand(0, 25) + 'a');
            }
            inp << "\n";
        }
        FOR (i, 1, n) {
            FOR (j, 1, m) {
                inp << (char) (Rand(0, 25) + 'a');
            }
            inp << "\n";
        }
    }
    
    
    return 0;
}