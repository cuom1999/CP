#include <bits/stdc++.h>

using namespace std;

const string FOLDER = "Data";
const string NAME = "SUBDIV";
const string SUFFIX_IN = "inp";
const string SUFFIX_OUT = "out";
const string CPP_NAME = "main";
const string BRUTE_NAME = "brute";
const string CHECKER = "Checker";
const string TMP_OUT = "tmp.txt";

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
    return ofstream(FOLDER + "/" + NAME + numToStr(test) + "." + SUFFIX_IN);
}

void delAllFiles() {
    string cmd = "rm /r /f " + FOLDER + "/*";
    system(cmd.c_str());
}

void compile() {
    string cmd = "ulimit -s 262144 && ulimit -v 1048576 && g++ -std=c++14 -O2 "
                + CPP_NAME + ".cpp" + " -o " + CPP_NAME;
    system(cmd.c_str());
}

string inpName(int test) {
    return FOLDER + "/" + NAME 
           + numToStr(test) + "." + SUFFIX_IN;
}

string outName(int test) {
    return FOLDER + "/" + NAME 
           + numToStr(test) + "." + SUFFIX_OUT;
}

void genOut(int test) {
    string cmd = "./" + CPP_NAME + " <" + inpName(test) 
                + ">" + outName(test);
    system(cmd.c_str());
}

void compileChecker() {
    string cmd = "g++ " + CHECKER + ".cpp -o " + CHECKER; 
    system(cmd.c_str());
}

void compileBrute() {
    string cmd = "g++ " + BRUTE_NAME + ".cpp -o " + BRUTE_NAME; 
    system(cmd.c_str());
}   

// output to tmp.txt
void runBrute(int test) {
    string cmd = "./" + BRUTE_NAME + " <" + inpName(test)
                + "> " + TMP_OUT;
    system(cmd.c_str());
}

// return 0 if correct, 1 if WA
bool runChecker(int test) {
    string cmd = "./" + CHECKER + " " + outName(test) + " " 
                + " " + TMP_OUT;
    return system(cmd.c_str());
}
