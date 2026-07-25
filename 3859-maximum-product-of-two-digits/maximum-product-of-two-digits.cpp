class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(begin(s),end(s));
        int a = s[s.size()-1]-'0',b  = s[s.size()-2]-'0';
        return (int)(a*b);
    }
};