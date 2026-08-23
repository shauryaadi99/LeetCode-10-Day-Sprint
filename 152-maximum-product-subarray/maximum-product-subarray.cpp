class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0], currMin = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            if (x < 0)
                swap(currMax, currMin);
            currMax = max(x, x * currMax);
            currMin = min(x, x * currMin);
            ans = max(ans, currMax);
        }
        return ans;
    }
};