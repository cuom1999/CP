#include "lib.h"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    compile();
    FOR (i, 1, 80) {
        genOut(i);
    }
    
    
    return 0;
}