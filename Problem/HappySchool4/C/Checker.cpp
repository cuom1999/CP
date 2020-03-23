#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

bool check(vector<string> &out, vector<string> &ans) {
    if (out.size() < ans.size()) {
        cerr << "Not enough numbers/words" << endl;
        return 1;
    }
    else if (out.size() > ans.size()) {
        cerr << "Too many numbers/words" << endl;
        return 1;
    }

    for (int i = 0; i < out.size(); i++) {
        if (out[i] != ans[i]) {
            cerr << "Different at position " << i + 1 << endl;
            cerr << "Expected " << ans[i] << ", found " << out[i] << endl;
            return 1;
        }
    }
    return 0;
}

// use: Checker <ansDirectory> <outDirectory>
int main(int argc, char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    if (argc != 3) {
        cerr << "Format: Checker <ansDirectory> <outDirectory>" << endl;
        return 0;
    }

    ifstream ansFile(argv[1]);
    ifstream outFile(argv[2]);

    string s;
    vector<string> out, ans;
    while (outFile >> s) {
        out.push_back(s);
    }
    while (ansFile >> s) {
        ans.push_back(s);
    }

    return check(out, ans);
}