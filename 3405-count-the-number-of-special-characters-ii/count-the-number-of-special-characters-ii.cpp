class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size(), cnt = 0;
        unordered_map<char, pair<int, int>> lower_upper;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (!lower_upper.count(ch))
                lower_upper[ch] = {-1, -1};
            if (isupper(ch)) {
                char lower = tolower(ch);
                if (lower_upper[lower].second == -1) {
                    lower_upper[lower].second = i;
                }
                continue;
            }
            lower_upper[ch].first = i;
        }
        for (auto& x : lower_upper) {
            int lastLower = x.second.first;
            int firstUpper = x.second.second;

            if (lastLower != -1 && firstUpper != -1 && lastLower < firstUpper) {
                cnt++;
            }
        }
        return cnt;
    }
};