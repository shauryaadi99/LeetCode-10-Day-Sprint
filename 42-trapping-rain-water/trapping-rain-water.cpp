class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, rightmax = 0, leftmax = 0;
        int totalWater = 0;
        while (left < right) {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if (leftmax < rightmax) {
                totalWater += leftmax - height[left];
                left++;
            } else {
                totalWater += rightmax - height[right];
                right--;
            }
        }
        return totalWater;
    }
};