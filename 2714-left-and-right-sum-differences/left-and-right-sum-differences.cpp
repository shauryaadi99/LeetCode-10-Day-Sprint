class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0), leftsum = 0,
            rightsum = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            rightsum = sum - (leftsum + nums[i]);
            int res = abs(leftsum - rightsum);
            ans.push_back(res);
            leftsum += nums[i];
        }
        return ans;
    }
};