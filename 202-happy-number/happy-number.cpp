class Solution {
public:
    int sumOfSquare(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            sum += (d * d);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = sumOfSquare(n);

        while (slow != fast) {
            slow = sumOfSquare(slow);
            fast = sumOfSquare(sumOfSquare(fast));
        }
        return (slow == 1);
    }
};