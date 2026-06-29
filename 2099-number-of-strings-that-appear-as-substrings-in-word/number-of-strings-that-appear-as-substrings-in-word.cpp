class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (string str : patterns) {
            if (word.contains(str))
                cnt++;
        }
        return cnt;
    }
};