class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        vector<vector<int>> t(n + 1, vector<int>(k + 1));
        
        for(int i = 1; i<= n; i++) {
            
            for(int coins = 0; coins <= k; coins++) {
                
                int sum = 0;
                for(int currCoins = 0; currCoins <= min((int)piles[i - 1].size(), coins); currCoins++) {
                    
                    if(currCoins > 0)
                        sum += piles[i-1][currCoins-1];
                    
                    t[i][coins] = max(t[i][coins], sum + t[i-1][coins - currCoins]);
                    
                }
                
                
            }
            
        }
        
        return t[n][k];
        
    }
};
