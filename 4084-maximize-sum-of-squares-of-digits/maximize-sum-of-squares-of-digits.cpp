class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // int n = num.size();
        if (sum > 9 * num)
            return "";
        int dig = num;
        string ans = "";
        while (num--) {
            int d = min(9, sum);
            ans += char('0' + d);
            sum -= d;
        }
        return ans;
    }
};