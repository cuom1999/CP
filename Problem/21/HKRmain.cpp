#include <bits/stdc++.h>

using namespace std;
double dp[1005][1005]; //dp[i][j]: percentage of strings of length i that have hashing value = j
    
vector<int> hashDistribution(int stringLen, int modulo, int baseHash) {
    
    vector<int> asciiValues;
    for (int i = 'a'; i <= 'z'; i++) {
        asciiValues.push_back(i);
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        asciiValues.push_back(i);
    }
    
    dp[0][0] = 100; //100%
    
    int curVal = 1;

    for (int i = 1; i <= stringLen; i++) {
        for (int c = 0; c < asciiValues.size(); c++) {
            int val = curVal * 1ll * asciiValues[c] % modulo; //curVal = pow(baseHash, i - 1)
            for (int j = 0; j <= modulo - 1; j++) {
                dp[i][j] += dp[i - 1][(j + modulo - val) % modulo] / 52.0; 
            }
        } 
        curVal = curVal * 1ll * baseHash % modulo; 
    }
    vector<int> result; //result[i] = number of strings that has HashVal = i
    

    for (int i = 0; i <= modulo - 1; i++) {
        result.push_back(dp[stringLen][i] * 1000000);
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, p, b;
    cin >> n >> p >> b;

    vector<int> res = hashDistribution(n, p, b);
    for (auto i: res) cout << i << endl;

    return 0;
}

