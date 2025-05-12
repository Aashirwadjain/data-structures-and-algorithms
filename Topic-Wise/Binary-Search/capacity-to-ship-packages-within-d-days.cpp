// Problem Statement: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
    public:
        bool possibleToShip(vector<int>& weights, int days, int capacity) {
            int load = 0;
            int countDays = 0;
            for(int i = 0; i < weights.size(); i++) {
                if(load + weights[i] > capacity) {
                    countDays++;
                    load = weights[i];
                }
                else    load += weights[i];
            }
            if(load != 0) {
                countDays++;
                load = 0;
            }
            return countDays <= days;
        }
        int shipWithinDays(vector<int>& weights, int days) {
    
            int maxWeight = INT_MIN;
            int sumOfWeights = 0;
            for(int i = 0; i < weights.size(); i++) {
                maxWeight = max(weights[i], maxWeight);
                sumOfWeights += weights[i];
            }
    
            int low = maxWeight;
            int high = sumOfWeights;
            int ans = sumOfWeights;
    
            while(low <= high) {
                int mid = (low + high) / 2;
                if(possibleToShip(weights, days, mid)) {
                    ans = mid;
                    high = mid - 1;
                }
                else    low = mid + 1;
            }
    
            return ans;
        }
};