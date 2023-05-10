//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   
        // Code here
         int totalCuts(int N,int K,vector<int> &A){
        // Code here
        int left[N],right[N];
        left[0]=A[0];
        for(int i=1;i<N;i++){
            left[i]=max(left[i-1],A[i]);
        }
        right[N-1]=A[N-1];
        for(int i=N-2;i>=0;i--){
            right[i]=min(right[i+1],A[i]);
        }
        int ans=0;
        for(int i=1;i<N;i++){
            if(left[i-1]+right[i]>=K)ans++;
        }
        return ans;
         }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends