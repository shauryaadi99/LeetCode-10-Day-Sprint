class Solution {
public:
int t[501][501];
    int solve(int i, int j, string& word1, string& word2) {
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;
        
        if(t[i][j]!=-1)
        return t[i][j];

        if (word1[i] == word2[j])
            return t[i][j] = solve(i - 1, j - 1, word1, word2);
        
        // word1 ---> word2
        int del = 1 + solve(i - 1, j, word1, word2);
        int insert = 1 + solve(i, j - 1, word1, word2);
        int replace = 1 + solve(i - 1, j - 1, word1, word2);

        return t[i][j] = min({del, insert, replace});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(t,-1,sizeof(t));
        return solve(n - 1, m - 1, word1, word2);
    }
};