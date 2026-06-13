class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        char ch = 'z';
        string ans = "";
        int sum=0;
        vector<char> res(26);
        for (int i = 0; i < 26; i++) {
            res[i] = ch;
            ch--;
        }
        for (auto word : words) {
            sum=0;
            for (int i = 0; i < word.size(); i++) {
                sum += weights[word[i] - 'a'];
            }
            sum = sum % 26;
            ans += res[sum];
        }
        return ans;
    }
};