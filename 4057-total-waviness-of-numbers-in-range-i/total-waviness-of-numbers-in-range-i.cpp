class Solution {
public:
    int waveness_count(int x) {
        bool prev = false, next = true;
        int wave = 0;
        string s1 = to_string(x);
        for (int i = 1; i < s1.size() - 1; i++) {
            int nxt = s1[i + 1] - '0', curr = s1[i] - '0',
                prv = s1[i - 1] - '0';
            if ((curr > prv && curr > nxt) || (curr < prv && curr < nxt))
            wave++;
        }
        return wave;
    }
    int totalWaviness(int num1, int num2) {
        if (num1 < 100 && num2 < 100 || num2 < 100)
            return 0;
        if (num1 < 100) {
            num1 = num1 + (100 - num1);
        }
        int sum = 0;
        for (int i = num1; i <= num2; i++) {
            sum += waveness_count(i);
        }
        return sum;
    }
};