#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const string FOLDER = "Data";
const string NAME = "BCTC";
const string SUFFIX_IN = "inp";
const string SUFFIX_OUT = "out";
const string CPP_NAME = "main";

string numToStr(int x) {
    string res;
    if (x < 10) {
        res = "0";
        res += (char) (x + '0');
    }
    else {
        res += (char) (x / 10 + '0');
        res += (char) (x % 10 + '0'); 
    }
    return res;
}

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r) {
    uniform_int_distribution<long long> rnd(l,r);
    return rnd(gen);
}

ofstream inpFile(int test) {
    return ofstream(FOLDER + "\\" + NAME + numToStr(test) + "." + SUFFIX_IN);
}

void delAllFiles() {
    system("del /f /s /q Data\\*");
}

void compile() {
    string cmd = "g++ -std=c++14 -Wl,--stack=268435456 -O2 "
                + CPP_NAME + ".cpp" + " -o " + CPP_NAME;
    system(cmd.c_str());
}

void genOut(int test) {
    string cmd = CPP_NAME + " <" + FOLDER + "\\" + NAME 
                + numToStr(test) + "." + SUFFIX_IN
                + ">" + FOLDER + "\\" + NAME 
                + numToStr(test) + "." + SUFFIX_OUT;
    system(cmd.c_str());
}