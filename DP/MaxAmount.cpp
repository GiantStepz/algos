//LC 198. House Robber

class Solution {
public:
    //DFS + memoization - Top-down
    vector<int> cache;
    int robTopDown(vector<int>& nums) {
        cache.assign(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int n) {
        if(n >= nums.size()) return 0;
        if(cache[n] != -1) return cache[n];
        return cache[n] = max(dfs(nums, n + 1), nums[n] + dfs(nums, n + 2)); 
    }

    //Bottom-up
    int robBottomUp(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }

    //Space Optimized
    int robOpt(vector<int>& nums) {
        int rob1 = 0, rob2 = 0, temp = 0;

        for(int num : nums) {
            temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};
