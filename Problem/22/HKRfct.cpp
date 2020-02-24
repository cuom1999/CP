
/*
 * Complete the 'optimalBalancedCosts' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER numTests
 *  2. STRING_ARRAY parentheses
 *  3. 2D_INTEGER_ARRAY costs
 */

long costUseOnlyLast3Operations(long numC, long numO, long costDelOpen[3], long costDelClose[3], long costAdd_A_Pair) {
    if (numO < 0 || numC < 0 || (numO + numC) % 2) return 1e18;
    long res = 1e18;

    //num6 = 0
    if (numO >= numC) {
        res = min(res, costAdd_A_Pair * numC + costDelOpen[2] * (numO - numC) / 2);
    } 

    //num7 = 0
    if (numO <= numC) {
        res = min(res, costAdd_A_Pair * numO + costDelClose[2] * (numC - numO) / 2);
    } 

    long num5 = numO % 2;

    numC -= num5;
    numO -= num5;

    res = min(res, num5 * costAdd_A_Pair + costDelOpen[2] * (numO / 2) + costDelClose[2] * (numC / 2));
    return res;
}

//solve for each testcase
long optimalCost(string parentheses, vector<int> costs) { 
    long costDelOpen[3], costDelClose[3]; // min cost to del i open/close parenthesis once (i = 1, 2)
    vector<char> parenStack; // stack that use to remove unnecessary parenthesis (one that has already paired)

    //remove unnecessary parentheses

    for (int i = 0; i < parentheses.length(); i++) {
        if (parentheses[i] == '(') {
            parenStack.push_back(parentheses[i]);
        } 
        else {
            if (!parenStack.size() || parenStack.back() == ')') {
                parenStack.push_back(parentheses[i]);
            }
            else {
                parenStack.pop_back();
            }
        }
    }


    long numOpen = 0, numClose = 0;

    for (int i = 0; i < parenStack.size(); i++) {
        if (parenStack[i] == ')') numClose++;
        else numOpen++;
    }

    //calculate min cost to del 1 or 2 parentheses once

    costDelClose[1] = min(costs[2], costs[3]);
    costDelOpen[1] = min(costs[2], costs[4]);

    costDelClose[2] = min((long)costs[1], costDelClose[1] * 2); //only apply if there are at least 2 close paren
    costDelOpen[2] = min((long)costs[0], costDelOpen[1] * 2);

    /*
        x close, y open
        Observation: (x, y) -> (x - 1, y), (x, y - 1), (x - 1, y + 1), (x + 1, y - 1)
                                (x - 1, y - 1), (x - 2, y), (x, y - 2)
        The first four can be used at most once
        In the last three, there's at least one that never be used or (x - 1, y - 1) can be used exactly once. 
    */

    long res = 1e18;

    for (int num1 = 0; num1 <= 1; num1++) {
        for (int num2 = 0; num2 <= 1; num2++) {
            for (int num3 = 0; num3 <= 1; num3++) {
                for (int num4 = 0; num4 <= 1; num4++) {

                            /*num_i is the number of times the i-th operation being used. 
                                        (in above 7 operations, not the ones in problem statement) */

                    long tmpClose = -num1 + -num3 + num4;
                    long tmpOpen = -num2 + num3 + -num4;
                    tmpClose = tmpClose + numClose;
                    tmpOpen = tmpOpen + numOpen;

                    long tmpCost = num1 * costDelClose[1] + num2 * costDelOpen[1] + num3 * costs[1] + num4 * costs[0];
                    res = min(res, costUseOnlyLast3Operations(tmpClose, tmpOpen, costDelOpen, costDelClose, costs[5]) + tmpCost);
                }
            }
        }
    }

    return res;
}

vector<long> optimalBalancedCosts(int numTests, vector<string> parentheses, vector<vector<int>> costs) {
    vector<long> result;
    for (int i = 0; i < numTests; i++) {
        result.push_back(optimalCost(parentheses[i], costs[i]));
    }
    return result;
}
