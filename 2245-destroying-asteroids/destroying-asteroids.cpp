class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        map<int, int> freq;
        long long masss = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            freq[asteroids[i]]++;
        }
        for (auto x : freq) {
            if (masss < x.first)
                return false;
            // if (x.first < masss) {
                masss += 1LL * x.second * x.first;
            // }
        }
        return true;
    }
};