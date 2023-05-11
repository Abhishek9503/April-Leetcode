//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int ans=0,n=s.size();
        for(int i=0;i<n/2;i++){
                if (s[i] =='?' && s[n-1-i]!='?'){
                    s[i]=s[n-1-i];
                }
                else if (s[n-1-i] =='?' && s[i]!='?'){
                    s[n-1-i]=s[i];
                }
                else if(s[i]!=s[n-1-i] && s[i]!='?' && s[n-1-i]!='?'){
                    return -1;
                }
        }
        char prevChar='.';
        for(int i=0;i<n/2;i++){
            if(s[i]!='?'){
                if(prevChar=='.'){
                    prevChar=s[i];
                }
                else if(s[i]!=prevChar){
                    ans+=abs(s[i]-prevChar);
                }
                prevChar=s[i];
            }
        }
        return ans*2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends