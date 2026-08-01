class Solution {
public:
    vector<int> nums;
    int t[21][21];
    int solve(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j)
            return nums[i];
        if (t[i][j] != -1)
            return t[i][j];

        int take_i = nums[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
        int take_j = nums[j] + min(solve(i + 1, j - 1), solve(i, j - 2));
        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        this->nums = nums;
        int tot = accumulate(begin(nums), end(nums), 0);
        memset(t, -1, sizeof(t));
        int p1 = solve(0, nums.size() - 1);
        return p1 >= (tot - p1);
    }
};