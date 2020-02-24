#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
/*
 * Complete the 'numberOfPaths' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_CHARACTER_ARRAY maze as parameter.
 */


int numberOfPaths(vector<vector<char>> &maze) {
    cout << maze.size() << endl;
    return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
    string maze_rows_temp;
    getline(cin, maze_rows_temp);

    int maze_rows = stoi(ltrim(rtrim(maze_rows_temp)));

    string maze_columns_temp;
    getline(cin, maze_columns_temp);

    int maze_columns = stoi(ltrim(rtrim(maze_columns_temp)));

    vector<vector<char>> maze(maze_rows);
    for (int i = 0; i < maze_rows; i++) {
        maze[i].resize(maze_columns);

        string maze_row_temp_temp;
        getline(cin, maze_row_temp_temp);
        
        vector<string> maze_row_temp = split(rtrim(maze_row_temp_temp));

        for (int j = 0; j < maze_columns; j++) {
            char maze_row_item = maze_row_temp[j][0];

            maze[i][j] = maze_row_item;
            cout << i << " " << j << " " << maze_row_item << endl;
        }
    }


    int result = numberOfPaths(maze);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
