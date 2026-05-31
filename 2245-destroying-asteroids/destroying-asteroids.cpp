class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long masss = mass;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (masss < asteroids[i]) {
                return false;
            }
            masss += asteroids[i];
        }
        return true;
    }
};