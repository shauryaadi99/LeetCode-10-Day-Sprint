class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), cnt = 0;
        sort(begin(intervals), end(intervals));
        for (int i = 0; i < n; i++) {
            int xi = intervals[i][0], yi = intervals[i][1];

            for (int j = i + 1; j < n; j++) {
                int x = intervals[j][0], y = intervals[j][1];
                if (xi <= y && x <= yi)
                    cnt++;
            }
        }
        return cnt;
    }
};