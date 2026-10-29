class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string s1 = s;
            sort(begin(s), end(s));
            mp[s].push_back(s1);
        }
        vector<vector<string>> res;
        for (auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};