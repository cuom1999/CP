// this judge is only used for C++
// please write yourself another judge for another language

#include <bits/stdc++.h>
using namespace std;

const string SOL = "solution";
const string CHECKER = "checker";

int numTest = 5;

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


int main()
{
    srand(time(NULL));
    // compile to get the exe file of human solution
    // system(("g++ " + SOL + ".cpp -o " + SOL).c_str());
    // compile the checker
    // system(("g++ " + CHECKER + ".cpp -o " + CHECKER).c_str());
    for (int testID = 1; testID <= numTest; testID++) {

        // some statements to convert testID to string
        string testID_str;
        testID_str = "test";
        testID_str += numToStr(testID);

        // run solution with each testcase
        system((SOL + " < testcases/" + testID_str + ".in > team_outputs/sol" + testID_str + ".out").c_str());
        // check with each testcase
        if (system((CHECKER + " testcases/" + testID_str + ".in testcases/" + testID_str + ".out feedback/ " + testID_str + " < team_outputs/sol" + testID_str + ".out" ).c_str()) == 43) {
            cout << "Test " << testID << ": Wrong Answer"<< endl;
            // return 0;
        }
        else {
            cout << "Test " << testID << ": Accepted" << endl;
        }
    }
    return 0;
}
