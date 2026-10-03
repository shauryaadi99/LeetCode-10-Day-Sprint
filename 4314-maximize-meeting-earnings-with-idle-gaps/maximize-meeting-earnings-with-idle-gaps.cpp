class Solution {
public:
    int n;
    vector<long long> dp;
    long long fn(vector<vector<int>>& v,int i) {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long dont=fn(v,i+1);
        int idx=lower_bound(v.begin()+i+1,v.end(),v[i][1],
            [](const vector<int>& a,int x) {
                return a[0]<x;
            })-v.begin();
        long long take=v[i][0]+v[i][2]+max(0LL,fn(v,idx)-v[i][1]);
        return dp[i]=max(take,dont);
    }

    long long maxEarnings(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        n=v.size();
        dp.assign(n,-1);
        fn(v,0);
        long long mx=0;
        for(int i=0;i<n;i++) {
            int idx=lower_bound(v.begin()+i+1,v.end(),v[i][1],
                [](const vector<int>& a,int x) {
                    return a[0]<x;
                })-v.begin();
            mx=max(mx,(long long)v[i][2]);
            mx=max(mx,v[i][2]-v[i][1]+fn(v,idx));
        }
        return mx;
    }
};