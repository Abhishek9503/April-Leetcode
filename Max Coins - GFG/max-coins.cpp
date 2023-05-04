//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
                sort(ranges.begin(),ranges.end());
        vector<int> temp(n);
        temp[n-1]=ranges[n-1][2];
        for(int i=n-2;i>=0;i--)temp[i]=max(temp[i+1],ranges[i][2]);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int sum = ranges[i][2];
            int low = i+1,high=n-1,mid,t=0;
            while(low<=high){
                mid=(low+high)/2;
                if(ranges[mid][0]>=ranges[i][1]){
                    high=mid-1;
                    t=temp[mid];
                }
                else low=mid+1;
            }
            sum+=t;
            ans=max(ans,sum);
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends