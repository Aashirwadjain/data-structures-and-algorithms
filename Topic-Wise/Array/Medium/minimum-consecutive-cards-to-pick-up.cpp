// Problem Statement: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

class Solution {
public:
    int minimumCardPickup(vector<int> &arr) {
        map<int, int> frequency;

        int i = 0, j = 0;
        int ans = INT_MAX;
        int n = arr.size();

        while (j < n) {
            frequency[arr[j]]++;
            while (frequency[arr[j]] == 2) {
                ans = min(ans, j - i + 1);
                frequency[arr[i]]--;
                i++;
            }
            j++;
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};