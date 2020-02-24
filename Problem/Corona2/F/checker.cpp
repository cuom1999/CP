#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll MAXA = 1e6;
int test;
int curN;

void WA(const string&s) {
    cout << "Test " << test << " (n = " << curN << "): " << s << endl;
    exit(1);
}

ll calc(ll a, ll b, ll c) {
    return a * a * a + b * b * b + c * c * c - 3 * a * b * c;
}

bool hasSol(int n) {
    if (n % 3) return 1;
    return (n % 9 == 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    vector<long long> query;
    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;
        query.push_back(x);
    }
    
    cin.ignore();  
    string tmp;
    getline(cin, tmp);

    for (int i = 0; i < t; i++) {
        curN = query[i];
        test++;
        string line;
        getline(cin, line);
        stringstream ss(line);
        
        if (line == "LN") {
            if (!hasSol(query[i])) {
                continue;
            }
            else {
                WA("Test nay co (a, b, c) thoa man");
            }
        }
        
        long long a, b, c;
        try {
            ss >> a >> b >> c;
            if (abs(a) > MAXA || abs(b) > MAXA || abs(c) > MAXA) {
                WA("a, b, c qua lon");
            }
            if (calc(a, b, c) != query[i]) {
                WA("Bieu thuc khong bang n");
            }
            continue;
        }
        catch(const std::exception& e) {
            WA("Sai format");
        }
    }
    return 0;
}