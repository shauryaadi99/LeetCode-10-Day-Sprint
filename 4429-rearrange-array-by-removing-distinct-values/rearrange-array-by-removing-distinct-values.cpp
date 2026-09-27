class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;

        map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        while (res.size() != nums.size()) {

            for (auto it = freq.begin(); it != freq.end();) {

                res.push_back(it->first);
                it->second--;

                if (it->second == 0)
                    it = freq.erase(it);
                else
                    it++;
            }
        }

        return res;
    }
};