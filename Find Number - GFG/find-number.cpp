//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
         long long ans=0;
        while(N){
            ans*=10;
            if(N%5==0){
                ans+=9;
                N/=5;
                N--;
            }
            else if(N%5==1){
                ans+=1;
                N/=5;
            }
            else if(N%5==2){
                ans+=3;
                N/=5;
            }
            else if(N%5==3){
                ans+=5;
                N/=5;
            }
            else{
                ans+=7;
                N/=5;
            }
        }
        long long temp = 0;
        while(ans){
            temp = temp*10+ans%10;
            ans/=10;
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends