// C++ implementation of  
// the above approach  
#include<bits/stdc++.h> 
using namespace std; 
  
int main() 
{  
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    
    int t;
    cin >> t;
    for(int z = 1; z <= t; z++) {    
        cin >> s;

        int n = s.length(); 
        char S[] = {'0', '1'}; 
        int k = 2; 
          
        // To store the indices  
        // of the characters  
        vector<int> w; 
        for (int i = 0; i < n; i++) {
            w.push_back(s[i] - '0');
        }          

        // Loop till w is not empty      
        while(w.size() > 0) 
        { 
            int m = w.size(); 
            
            // Repeating w to get a  
            // n-length string 
            while(w.size() < n) 
            { 
                w.push_back(w[w.size() - m]); 
            } 
          
            // Removing the last character  
            // as long it is equal to  
            // the largest character in S  
            while(w.size() > 0 && w[w.size() - 1] == k - 1) 
            { 
                w.pop_back(); 
            }

            // Incrementing the last character 
            if (!w.size()) {
                cout << "\n";
                break;
            }
            
            w[w.size()-1]++; 
            if(w.size() == n) 
            { 
                string str; 
                for(int i = 0; i < w.size(); i++) 
                { 
                    str += S[w[i]]; 
                } 
                cout << str << "\n";
                break; 
            } 
        }

    }
    return 0; 
} 