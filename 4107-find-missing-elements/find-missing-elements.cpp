class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> res;
        for (auto it : nums) {
            st.insert(it);
        }
        for (int i = nums[0]; i < nums[n - 1]; i++) {
            if (!st.count(i))
                res.push_back(i);
        }
        return res;
    }
};