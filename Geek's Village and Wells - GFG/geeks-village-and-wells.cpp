//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:

// x,y -> (x-1,y), (x+1,y),(x,y-1),(x,y+1)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c)
{
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] == 'W')
            {
                q.push({i, j});
                vis[i][j] = true;
            }
            if (c[i][j] == 'W' || c[i][j] == '.' || c[i][j] == 'N')
            {
                dist[i][j] = 0;
            }
        }
    }
    int dis = 2;
    while (!q.empty())
    {
        int qsize = q.size();
        while (qsize--)
        {
            auto it = q.front();
            q.pop();
            int i = it.first, j = it.second;
            for (int k = 0; k < 4; k++)
            {
                int curri = i + dx[k], currj = j + dy[k];
                if (curri >= 0 && currj >= 0 && curri < n && currj < m && !vis[curri][currj] && c[curri][currj] != 'N')
                {
                    vis[curri][currj] = true;
                    q.push({curri, currj});
                    if (c[curri][currj] == 'H')
                    {
                        dist[curri][currj] = dis;
                    }
                }
            }
        }
        dis += 2;
    }
    return dist;
}
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends