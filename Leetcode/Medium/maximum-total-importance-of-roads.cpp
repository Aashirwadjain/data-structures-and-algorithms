// Problem Statement: https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {

        vector<long long int> deg(n, 0);
        for (int i = 0; i < roads.size(); i++) {
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }

        sort(deg.begin(), deg.end());

        long long int ans = 0;
        for (long long int i = 1; i <= n; i++) {
            ans += (deg[i - 1] * i);
        }

        return ans;
    }
};