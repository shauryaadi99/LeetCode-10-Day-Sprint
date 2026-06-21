class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size(), L = 0, R = 0, U = 0, D = 0,K=0;

        for (int i = 0; i < n; i++) {
            if (moves[i] == 'L')
                L++;
            else if (moves[i] == 'R')
                R++;
            else if (moves[i] == 'U')
                U++;
            else if (moves[i] == 'D')
                D++;
            else
                K++;
        }
        return abs(abs(R - L) + abs(U - D) + K);
    }
};