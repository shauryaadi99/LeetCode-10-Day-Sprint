class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        vector<char> v = {'b', 'a', 'l', 'o', 'n'};
        int L = 0, O = 0, mini = INT_MAX;

        for (char ch : text)
            freq[ch]++;

        for (char ch : v) {

            if (ch == 'l' || ch == 'o')
                mini = min(mini, (freq[ch]) / 2);
            else
                mini = min(mini, freq[ch]);
        }
        // if (L >= (2 * mini) && O >= (2 * mini))
        return mini;
        // return -1;
    }
};