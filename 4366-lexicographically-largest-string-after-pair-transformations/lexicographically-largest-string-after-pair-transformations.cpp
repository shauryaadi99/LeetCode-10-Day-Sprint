class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for (int x : nums) {
            string str;
            int power = 1;
            int letter = 0;
            while (power * 2 <= x) {
                power *= 2;
                letter++;
            }

            while (x > 0) {
                if (power <= x) {
                    if (letter == 26) {
                        str += "zz";
                    } else {
                        str.push_back('a' + letter);
                    }
                    x -= power;
                }
                power /= 2;
                letter--;
            }
            ans.push_back(str);
        }
        return ans;
    }
};