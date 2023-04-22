//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
       int BinarySearch(int key,int temp[],int n){
        int low=0,high=n-1,mid=0,index=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(temp[mid]==key){
                index=mid;
                high=mid-1;
            }
            else if(temp[mid]>key){
                high=mid-1;
            }
            else low=mid+1;
        }
        return index;
    }
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans(n);
        long long sum[n];
        int temp[n];
        for(int i=0;i<n;i++)temp[i]=arr[i];
        sort(temp,temp+n);
        sum[0]=temp[0];
        for(int i=1;i<n;i++)sum[i]=sum[i-1]+temp[i];
        for(int i=0;i<n;i++){
            int index = BinarySearch(arr[i],temp,n);
            ans[i] = sum[index]-arr[i];
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends