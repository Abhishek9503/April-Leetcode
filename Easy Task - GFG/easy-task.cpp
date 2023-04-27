//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

vector<vector<int>> segment;
class Solution{
public:
    void bnado(int index,int left,int right,string s){
        if(left==right){
            segment[index][s[right]-'a']=1;
            return;
        }
        int mid = (left+right)/2;
        bnado(2*index+1,left,mid,s);
        bnado(2*index+2,mid+1,right,s);
        for(int i=0;i<26;i++){
            segment[index][i]=segment[2*index+1][i]+segment[2*index+2][i];
        }
    }
    void update(int index,int left,int right,int Uindex,char c,string s){
        if(Uindex<left or Uindex>right)return;
        segment[index][s[Uindex]-'a']--;
        segment[index][c-'a']++;
        if(left==right)return;
        int mid = (left+right)/2;
        update(2*index+1,left,mid,Uindex,c,s);
        update(2*index+2,mid+1,right,Uindex,c,s);
    }
    void nikaldo(int index,int left,int right,int s,int e,int temp[]){
        if(left>e or right<s)return;
        if(left>=s and right<=e){
            for(int i=0;i<26;i++){
                temp[i]+=segment[index][i];
            }
            return;
        }
        int mid = (left+right)/2;
        nikaldo(2*index+1,left,mid,s,e,temp);
        nikaldo(2*index+2,mid+1,right,s,e,temp);
    }
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        // Code here
        vector<char> ans;
        segment = vector<vector<int>> (4*n,vector<int>(26,0));
        bnado(0,0,n-1,s);
        for(int i=0;i<q;i++){
            if(queries[i][0]=="1"){
                int Uindex = stoi(queries[i][1]);
                char c = queries[i][2][0];
                update(0,0,n-1,Uindex,c,s);
                s[Uindex]=c;
            }
            else{
                int s = stoi(queries[i][1]);
                int e = stoi(queries[i][2]);
                int k = stoi(queries[i][3]);
                int temp[26]={0};
                nikaldo(0,0,n-1,s,e,temp);
                int i;
                for(i=25;i>=0;i--){
                    k-=temp[i];
                    if(k<=0)break;
                }
                ans.push_back('a'+i);
            }
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
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends