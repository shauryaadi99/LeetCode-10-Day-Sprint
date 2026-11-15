class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, even = 1, odd = 0, sum = 0;
        // for any odd number the number of even numbers on its left
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                ans = (ans + odd) % M;
                even++;
            } else {
                ans = (ans + even) % M;
                odd++;
            }
        }
        return ans;
    }
};