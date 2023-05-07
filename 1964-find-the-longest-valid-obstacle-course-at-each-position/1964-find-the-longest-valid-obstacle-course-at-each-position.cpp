class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
//         int n = nums.size();
//         vector<int> t(n, 1);
        
//         for(int i = 0; i<n; i++) {
//             for(int j = 0; j<i; j++) {
//                 if(nums[j] <= nums[i]) {
//                     t[i] = max(t[i], t[j]+1);
                    
//                 }
//             }
//         }
        
//         return t;
        
        
        
           int n = obstacles.size();
        vector<int> result(n, 1);
        vector<int> LIS;

        
        for(int i = 0; i<n; i++) {
            
            int idx = upper_bound(begin(LIS), end(LIS), obstacles[i]) - begin(LIS);
            
            if(idx == LIS.size()) {
                LIS.push_back(obstacles[i]);
            } else {
                LIS[idx] = obstacles[i];
            }
            
            result[i] = idx+1;
            
        }
        
        return result;
    }
};