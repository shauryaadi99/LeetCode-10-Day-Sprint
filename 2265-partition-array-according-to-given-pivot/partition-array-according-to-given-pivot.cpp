class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> less, greater, ans;
        
        int eq = 0;
        for (int x : nums) {
            if (x == pivot) {
                eq++;
            } else if (x < pivot) {
                less.push_back(x);
            } else {
                greater.push_back(x);
            }
        }
        for (int x : less) {
            ans.push_back(x);
        }
        while (eq--) {
            ans.push_back(pivot);
        }
        for (int x : greater) {
            ans.push_back(x);
        }
        return ans;
    }
};