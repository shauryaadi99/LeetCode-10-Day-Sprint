class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0,maxi=0;
        for(auto& x:gain){
            sum+=x;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};