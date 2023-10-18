class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> q;
        for (int n: nums)
            q.push(n);
        while (k --) {
            long long t = q.top();
            q.pop();
            ans += t;
            q.push((int)(t + 2)/3);
        }
        return ans;
    }
};