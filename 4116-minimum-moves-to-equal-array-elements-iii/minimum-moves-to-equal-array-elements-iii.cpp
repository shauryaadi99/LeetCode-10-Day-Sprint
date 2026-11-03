class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        // nth_element(begin(nums), begin(nums) + n / 2, end(nums));
        int maxi = *max_element(begin(nums), end(nums));
        int mid = nums[n / 2];
        long long moves = 0;
        for (int i = 0; i < n; i++) {
            moves += abs(nums[i] - maxi);
        }
        return moves;
    }
};