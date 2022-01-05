// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  int count = 1;
  char ch = s[0];
  string ans = "";
  for(int i = 1; i < s.size(); i++) {
      if(s[i] == s[i - 1]) {
          count++;
      }
      else {
          ans += ch + to_string(count);
          count = 1;
          ch = s[i];
      }
  }
  ans += ch + to_string(count);
  return ans;
}     
 
