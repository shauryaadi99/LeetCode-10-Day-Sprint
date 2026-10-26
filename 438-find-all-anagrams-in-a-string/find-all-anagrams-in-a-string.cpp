class Solution {
public:
    string s;
    string p;
    bool checkAnagram(int idx) {
        int window = p.size();
        vector<int> freq(26, 0);
        for (int i = idx; i < idx + window && i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < p.size(); i++) {
            freq[p[i] - 'a']--;
        }
        for (auto it : freq)
            if (it != 0)
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        this->s = s;
        this->p = p;
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            if (checkAnagram(i))
                res.push_back(i);
        }
        return res;
    }
};