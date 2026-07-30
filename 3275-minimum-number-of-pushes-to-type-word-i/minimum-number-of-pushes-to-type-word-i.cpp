class Solution {
public:
    int minimumPushes(string word) {
        int sz = word.size();

        if (sz <= 8)
            return sz;

        int cost = 8;
        sz -= 8;

        if (sz <= 8) {
            cost += sz * 2;
        } else if (sz <= 16) {
            cost += 8 * 2 + (sz - 8) * 3;
        } else {
            cost += 8 * 2 + 8 * 3 + (sz - 16) * 4;
        }

        return cost;
    }
};