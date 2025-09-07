# Gfg problem link --> https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution {
  public:
    int knapsackHelper(int n, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(n==0 || W==0){
            return 0;
        }
        if(dp[n][W] != -1) return dp[n][W];
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1] + knapsackHelper(n-1, W-wt[n-1], val, wt, dp), knapsackHelper(n-1, W, val, wt, dp));
        }else{
            return dp[n][W] = knapsackHelper(n-1, W, val, wt, dp);
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return knapsackHelper(n, W, val, wt, dp);
    }
};
