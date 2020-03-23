#include "lib.h"

bool isComp[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // delAllFiles();
    FOR (i, 2, 1000000) {
        FOR (j, 2, 1000000 / i) {
            isComp[i * j] = 1;
        }
    }
    vector<int> prime;
    FOR (i, 2, 1000000) {
        if (!isComp[i]) prime.pb(i);
    }

    FOR (i, 81, 90) {
        ofstream inp = inpFile(i);
        if (i >= 85) {
            ll u = Rand(900000, 1000000);
            FOR (i, 1, u) {
                inp << 0;
            }
            inp << "\n" << Rand(1, 1e6) << "\n";
        }
        else {
            FOR (i, 1, 1000000) {
                if (Rand(0, 1)) {
                    inp << 0;
                }
                else {
                    inp << Rand(0, 9);
                }
            }
            inp << "\n " << Rand(1, 1e6);
        }
    }
    return 0;

    FOR (i, 3, 80) {
        ofstream inp = inpFile(i);
        // write using to file inp <<
        ll n, p;
        if (i <= 10) {
            n = Rand(1, 15);
            p = Rand(1, 25);
        }
        else if (i <= 20) {
            n = Rand(1, 5000);
            p = Rand(1, 1000000);
        }
        else if (i <= 40) {
            n = Rand(1, 1000000);
            p = Rand(1, 1000000);
        }
        else if (i <= 60) {
            n = Rand(1, 1000000);
            ll u = Rand(1, 6);
            p = 1;
            FOR (i, 1, u) p *= 10;
            p *= Rand(1, 1000000 / p);
        }
        else if (i <= 70) {
            n = Rand(900000, 1000000);
            ll u = Rand(1, 6);
            p = 1;
            FOR (i, 1, u) p *= 10;
            p *= Rand(1, 1000000 / p);
        }
        else {
            n = Rand(900000, 1000000);
            ll u = Rand(1, 3);
            p = 1;
            FOR (i, 1, u) p *= 10;
            p *= Rand(1, 1000000 / p);    
        }
        
        FOR (i, 1, n) {
            inp << Rand(0, 9);
        }
        inp << "\n";
        inp << p << "\n";
    }
    
    
    return 0;
}