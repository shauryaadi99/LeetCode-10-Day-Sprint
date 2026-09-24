class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long n = intervals.size(), ans = 0;
        sort(begin(intervals), end(intervals));
        for (int i = 0; i < n; i++) {
            int low = i + 1, hi = n;
            int end = intervals[i][1];
            while (low < hi) {
                int mid = low + (hi - low) / 2;
                int x = intervals[mid][0], y = intervals[mid][1];
                if (x > end) {
                    hi = mid;
                } else {
                    low = mid + 1;
                }
            }
            ans += (low - i - 1);
        }
        return ans;
    }
};