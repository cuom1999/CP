#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 51, 60) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        inp << Rand(900000, 1000000);
    }
    
    
    return 0;
}