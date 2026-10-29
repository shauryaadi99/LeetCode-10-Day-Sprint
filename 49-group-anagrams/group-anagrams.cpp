class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector < vector<string>>res;
        for (string s : strs) {
            vector<int> freq(26, 0);
            for (char ch : s) {
                freq[ch - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += '#';
                key += freq[i];
            }
            mp[key].push_back(s);
        }
        for (auto it : mp)
            res.push_back(it.second);
        return res;
    }
};