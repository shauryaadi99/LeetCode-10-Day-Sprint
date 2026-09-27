class Solution {
public:
    vector<int> freq;
    bool isInvalidInterval(int x) {
        for (int i = 1; i <= 500; i++) {
            if (freq[i] == 0)
                continue;
            int other = x - i;
            // if x = a + b
            if (other >= 0 && other <= 500) {
                if (other == i && freq[i] >= 2)
                    return true;
                if (other != i && freq[other] > 0)
                    return true;
            }
            // if a + x = b
            int b = i + x;
            if (b >= 0 && b <= 500) {
                if (freq[b] > 0)
                    return true;
            }
        }
        return false;
    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        freq.resize(501, 0);
        int l = 0, r = 0, maxlength = 0;
        for (r = 0; r < n; r++) {
            int x = nums[r];
            while (l < r && isInvalidInterval(x)) {
                freq[nums[l]]--;
                l++;
            }
            freq[x]++;
            maxlength = max(maxlength, r - l + 1);
        }
        return maxlength;
    }
};