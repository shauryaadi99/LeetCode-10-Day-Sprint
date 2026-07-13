class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        vector<int> ans;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
        q.push(7);
        q.push(8);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            int lastDigit = num % 10 + 1;
            if (lastDigit-1 == 9)
                continue;
            num = num * 10 + lastDigit;
            if (num >= low && num <= high) {
                ans.push_back(num);
            }
            if (num <= high)
                q.push(num);
        }
        return ans;
    }
};