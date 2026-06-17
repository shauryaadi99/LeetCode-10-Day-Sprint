class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;
        for (int j = 0; j < n; j++) {
            int leftSmaller = 0, rightSmaller = 0, leftGreater = 0,
                rightGreater = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j])
                    leftSmaller++;
                else
                    leftGreater++;
            }
            for (int i = n - 1; i > j; i--) {
                if (rating[i] < rating[j])
                    rightSmaller++;
                else
                    rightGreater++;
            }
            ans += leftSmaller * rightGreater;
            ans += leftGreater * rightSmaller;
        }
        return ans;
    }
};