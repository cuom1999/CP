#include "lib.h"

void genOutput(int numTest) {
    compile();
    FOR (i, 1, numTest) {
        genOut(i);
    }
}

void validate(int numTest) {
    // Validate with brute
    compileChecker();
    compileBrute();
    FOR (i, 1, numTest) {
        runBrute(i);
        if (runChecker(i)) {
            cout << "\nWrong Answer at test " << i << endl;
            exit(0);
        }
    }
    cout << "ACCEPTED" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // genOutput(30);    
    validate(30);
    
    return 0;
}