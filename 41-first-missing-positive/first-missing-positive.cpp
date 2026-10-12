class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));
        set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        for (int i = min(mini, 0); i <= maxi; i++) {
            if (i > 0) {
                if (!st.count(i)) {
                    return i;
                }
            }
        }
        return (maxi + 1 <= 0 ? 1 : maxi + 1);
    }
};