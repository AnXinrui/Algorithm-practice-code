class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> st;
        for (int num: nums) {
            ++ st[num];
        }
        vector<int> ans;
        for (auto i: st) {
            if (i.second == 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};
