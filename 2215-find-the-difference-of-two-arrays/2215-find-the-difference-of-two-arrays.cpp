class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> set1;
        vector<vector<int>> ans;
        unordered_set<int> set2;
        for(int i=0;i<nums1.size();i++){
            set1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            set1.erase(nums2[i]);
            set2.insert(nums2[i]);
        }
        vector<int> ans1;
        for(auto it:set1){
            ans1.push_back(it);
        }
        ans.push_back(ans1);
        ans1.clear();
        for(int i=0;i<nums1.size();i++){
            set2.erase(nums1[i]);
        }
        for(auto it:set2){
            ans1.push_back(it);
        }
        ans.push_back(ans1);
        return ans;
    }
};