class Solution {
    long long f(int n)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i ++)
            ans *= i;
        return ans;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i ++)
            for (int j = i + 1; j < nums.size(); j ++) {
                int k = nums[i] * nums[j];
                
                ++ mp[k];
            }
        for (auto i: mp)    
            if (i.second >= 2) {
                int k = i.second;
                ans += f(k)/f(2)/f(k-2);
            }
        return ans * 8;
    }
};