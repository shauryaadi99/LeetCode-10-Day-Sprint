class Solution {
public:
    bool checkDivisibility(int n) {
        long long prod = 1, sum = 0;
        int n1 = n;
        while (n) {
            int d = n % 10;
            prod *= d;
            sum += d;
            n /= 10;
        }
        return (n1 % (prod + sum)==0);
    }
};