// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
		int CountWays(string s){
		    // Code here
		    int n = s.size();
		    int m = 1e9+7;
            vector<int> dp(n+1, 0);
            dp[0] = 1;
            for(int i = 1; i <= n; i++) {
                char ch = s[i-1];
                if(ch - '0' >= 1 && ch - '0' <= 9) {
                    dp[i] = dp[i - 1];
                }
                if(i - 1 >= 1) {
                    if(s[i-2] == '0') continue;
                    string ch12 = "";
                    ch12.push_back(s[i-2]);
                    ch12.push_back(ch);
                    // cout << "ch12=" << s[i-2] << " " << ch << " " << ch12 << " ";
                    if(ch12 >= "10" && ch12 <= "26") {
                        dp[i] += dp[i - 2];
                    }
                }
                // cout << dp[i] << " ";
                dp[i] %= m;
            }
            return dp[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends