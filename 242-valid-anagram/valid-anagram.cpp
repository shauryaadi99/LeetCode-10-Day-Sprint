class Solution {
public:
    bool isAnagram(string s, string t) {
        // int n = s.size();
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        for (char ch : t) {
            freq[ch]--;
        }
        for (auto it : freq) {
            if (it.second > 0)
                return false;
        }
        return true;
    }
};