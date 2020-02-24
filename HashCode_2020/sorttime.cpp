#include <bits/stdc++.h>

using namespace std;

string subtasks[6] = {"a_example.txt", "b_read_on.txt",
                      "c_incunabula.txt", "d_tough_choices.txt",
                      "e_so_many_books.txt", "f_libraries_of_the_world.txt"};

string output(int index) {
    char c = (char) (index + 'a');
    string res = "output_";
    res += c;
    res += ".txt";
    return res;
}   

int score[100005];

struct Lib {
    int signupTime;
    int booksPerDay;
    vector<int> books;
} lib[100005];

int main() {
    int sub = 3;
    freopen(subtasks[sub].c_str(), "r", stdin);
    freopen(output(sub).c_str(), "w", stdout);
    ios::sync_with_stdio(0);

    int nBooks, nLibs, nDays;
    cin >> nBooks >> nLibs >> nDays;
    for (int i = 0; i < nBooks; i++) {
        cin >> score[i];
    }

    for (int i = 0; i < nLibs; i++) {
        int numBooks;
        cin >> numBooks >> lib[i].signupTime >> lib[i].booksPerDay;
        for (int j = 1; j <= numBooks; j++) {
            int x;
            cin >> x;
            lib[i].books.push_back(x);
        }
    }

    // end of input

    vector<bool> scanned(nBooks), signedUp(nLibs);

    // res: {libIndex, {score, book}}
    vector<pair<int, vector<pair<int, int>>>> res;

    int curDay = 0;
    int totalScore = 0;

    while (curDay < nDays) {
        vector<int> libScore(nLibs);
        vector<pair<int, int>> toScan[100005];

        int remainTime = nDays - curDay;
        int maxScore = 1e9; 
        int index = -1;

        for (int i = 0; i < nLibs; i++) {
            if (signedUp[i] || lib[i].signupTime >= remainTime) continue;
            int booksCanScan = (remainTime - lib[i].signupTime) * lib[i].booksPerDay;
            for (auto j: lib[i].books) {
                if (!scanned[j]) {
                    toScan[i].push_back({score[j], j});
                }
            }
            sort(toScan[i].begin(), toScan[i].end());
            reverse(toScan[i].begin(), toScan[i].end());
            while (toScan[i].size() > booksCanScan) {
                toScan[i].pop_back();
            }

            for (auto j: toScan[i]) {
                libScore[i] += j.first;
            }

            if (maxScore > lib[i].signupTime) {
                maxScore = lib[i].signupTime;
                index = i;
            }
        }

        if (index == -1) break;

        curDay += lib[index].signupTime;
        totalScore += libScore[index];
        signedUp[index] = 1;
        res.push_back({index, toScan[index]});
        for (auto j: toScan[index]) {
            scanned[j.second] = 1;
        }
    }

    cout << totalScore << endl;
    cout << res.size() << "\n";
    for (auto i: res) {
        cout << i.first << " " << i.second.size() << "\n";
        for (auto j: i.second) {
            cout << j.second << " ";
        }
        cout << "\n";
    }


    return 0;
}