class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(begin(nums), begin(nums) + n / 2, end(nums));
        int mid = nums[n / 2];
        int moves = 0;
        for (int i = 0; i < n / 2; i++) {
            moves += abs(mid - nums[i]);
            moves += abs(mid - nums[n - 1 - i]);
        }
        return moves;
    }
};