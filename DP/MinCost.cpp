// LC 746. Min Cost Climbing Stairs

class Solution {
public:
	
    //Top Down solution using dfs and memoization	
    vector<int> cache;
    int minCostClimbingStairsTopDown(vector<int>& cost) {
        cache.assign(cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int n) {
        if(n >= cost.size()) return 0;
        if(cache[n] != -1 ) return cache[n];
        return cache[n] = cost[n] + min(dfs(cost, n + 1), dfs(cost, n + 2));
    }

    //Bottom up solution	
    int minCostClimbingStairsBottomUp(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);

        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }

    //Space optimized solution
    int minCostClimbingStairsOpt(vector<int>& cost) {
        for(int i = cost.size() - 3; i >= 0; i--) {
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
    }
};
