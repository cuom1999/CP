#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();

    FOR (i, 1, 30) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        inp << Rand(1, 10) << " " << Rand(1, 10) << "\n"; 
    }
    
    
    return 0;
}