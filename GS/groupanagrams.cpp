// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& slist) {
        //first approach: O(n*k) time, O(n*k) space
        vector<vector<string> > ans;
        map<map<char, int>, vector<string>> m;
        for(string s : slist) {
            map<char, int> freq;
            for(char ch : s) {
                freq[ch]++;
            }
            if(m.find(freq) != m.end()) {
                m[freq].push_back(s);
            }
            else {
                vector<string> newv;
                newv.push_back(s);
                m[freq] = newv;
            }
        }
        for(auto s : m) {
            ans.push_back(s.second);
        }

        //Second approach: O(n*k*logk) time, O(n*k) space
        // unordered_map<string, vector<string>> m;
        // for(string s : slist) {
        //     string temp = s;
        //     sort(s.begin(), s.end());
        //     m[s].push_back(temp);
        // }
        // for(auto s : m) {
        //     ans.push_back(s.second);
        // }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends