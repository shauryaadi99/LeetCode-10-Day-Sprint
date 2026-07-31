class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size(), press = 0;
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        sort(begin(freq), end(freq), greater<int>());
        for (int i = 0; i < 26; i++) {
            press += (i / 8 + 1) * freq[i];
        }
        return press;

        for (char ch : word) {
            freq[ch]++;
        }
        for (auto it : freq) {
        }
    }
};