class Solution {
public:
    int n,m;
    int mem[501][501];
    // int mem[501];
    // int mem2[501];
    // int rec(int i,vector<int> &nums1, vector<int> &hash){
    //     cout<<i<<" "<<n<<" "<<m<<endl;
    //     if(i>=n || i>=m) return 0;
    //     if(mem[i] != -1) return mem[i];
    //     // int k = 0;
    //     if(hash[nums1[i]] >= i) mem[i] = 1+rec(hash[nums1[i]]+1, nums1, hash);
    //     mem[i] = max(mem[i], rec(i+1, nums1, hash));
    //     return mem[i];
    //     // return mem[i] = max(1+rec(1+hash[nums1[i]], nums1, hash), rec(i+1, nums1, hash));
    // }

    int rec(int i, int j, vector<int> &nums1, vector<int> &nums2){
        if(i<=0 || j<=0) return 0;
        if(mem[i][j] != -1) return mem[i][j];

        if(nums1[i-1] == nums2[j-1]) mem[i][j] = 1+rec(i-1, j-1, nums1, nums2);
        else mem[i][j] = max(rec(i, j-1, nums1, nums2), rec(i-1, j, nums1, nums2));
        
        return mem[i][j];
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        memset(mem, -1, sizeof(mem));
        // memset(mem2, -1, sizeof(mem2));

        // vector<int> hash(2e3+1);
        // for(int i = 0; i<m; i++) hash[nums2[i]] = i;

        // int ans = 0;
        // for(int i = 0;  i<n; i++){

        // }
        // return max(rec(0, nums1, hash), rec(0, nums1, ));
        return rec(n, m, nums1, nums2);
    }
};