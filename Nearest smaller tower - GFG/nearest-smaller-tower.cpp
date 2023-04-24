//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> nearestSmallerTower(vector<int> a) {
        int i, n=a.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for(i=n-1;i>=0;i--) {
            while(st.size() && a[st.top()]>=a[i]) st.pop();
            ans[i]=(st.size())?st.top():-1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(i=0;i<n;i++) {
            while(st.size() && a[st.top()]>=a[i]) st.pop();
            if(st.size()) {
                if(ans[i]==-1) ans[i]=st.top();
                else {
                    int index=st.top();
                    if((i-index)<(ans[i]-i)) ans[i]=index;
                    else if((i-index)==(ans[i]-i)) {
                        if(a[index]<=a[ans[i]]) ans[i]=index;
                    }
                }
            }
            st.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends