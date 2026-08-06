class Solution {
public:
    // function to store the product of the digits of num
    int ProductOfDig(int num) {
        int prod = 1, d;
        while (num) {
            d = num % 10;
            prod *= d;
            num /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            int prodOfDigits = ProductOfDig(n);
            if (prodOfDigits % t == 0)
                return n;
            n++;
        }
        return -1;
    }
};