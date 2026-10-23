class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, area = 0, best = 0;
        while (l < r) {
            int ht = min(height[l], height[r]);
            int bdth = r - l ;
            area = ht * bdth;
            best = max(best, area);
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return best;
    }
};
