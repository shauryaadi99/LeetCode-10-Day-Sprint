class Solution {
public:
    vector<pair<int, int>> mergeintervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<pair<int, int>> res;
        res.push_back({intervals[0][0], intervals[0][1]});
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back().second >= intervals[i][0]) {
                int s = res.back().first;
                int t = res.back().second;
                res.pop_back();
                res.push_back({s, max(t, intervals[i][1])});
            } else {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return res;
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long timeUnits = 0;
        vector<pair<int, int>> res = mergeintervals(intervals);
        for (auto& x : res) {
            timeUnits += (x.second - x.first + 1);
        }
        long long ans = ((brightness + 2) / 3) * timeUnits;
        return ans;
    }
};