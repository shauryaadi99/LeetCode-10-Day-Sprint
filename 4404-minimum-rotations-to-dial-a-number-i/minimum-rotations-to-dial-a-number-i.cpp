class Solution {
public:
    int minRotations(string s) {
        int i = 0, sum = 0;

        for (char ch : s) {
            int num = ch - '0';
            int a = abs(i - num);
            int b = abs(10 - a);
            sum += min(a, b);
            i = num;
        }
        return sum;
    }
};