class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int minIdx = min_element(begin(nums), end(nums)) - begin(nums),
            maxIdx = max_element(begin(nums), end(nums)) - begin(nums);
        int leftIdx = min(minIdx, maxIdx);
        int rightIdx = max(minIdx, maxIdx);
        return min({leftIdx + 1 + n - rightIdx, rightIdx + 1, n - leftIdx});
    }
};