class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int heighest=-1;
        int sec_heighest;
        
        while(stones.size()>1)
        {
            sort(stones.begin(),stones.end());
            
            int a = stones.back(); stones.pop_back();
            int b = stones.back(); stones.pop_back();

            stones.push_back(abs(a-b));
        
        }

       
        return stones[0];
    }     
};
