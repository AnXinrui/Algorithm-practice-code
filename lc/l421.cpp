const int N = 26 * 2e5 + 10;
class Solution {
    int trie[N][2]{}, cnt = 0;

    void insert(int x) {
        int p = 0;
        for (int i = 30; ~i; i --) {
            int u = x >> i & 1;
            if (!trie[p][u])
                trie[p][u] = ++ cnt;
            p = trie[p][u];
        }
    }

    int query(int x) {
        int p = 0, res = 0;
        for (int i = 30; ~i; i --) {
            int u = x >> i & 1;
            if (trie[p][!u])
                res = res * 2 + !u,
                p = trie[p][!u];
            else
                res = res * 2 + u,
                p = trie[p][u];
        }
        return res;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int &x: nums)
            insert(x),
            ans = max(ans, x ^ query(x));
        return ans;
    }
};




/************************************************************/

class Trie {
private:
    Trie* son[2] = {nullptr};
public:
    Trie(){}
    void insert(int x) {
        Trie* root = this;
        for (int i = 30; ~i; i --) {
            int u = x >> i & 1;
            if (!root -> son[u])
                root -> son[u] = new Trie();
            root = root -> son[u];
        }
    }

    int query(int x) {
        Trie* root = this;
        int res = 0;
        for (int i = 30; ~i; i --) {
            int u = x >> i & 1;
            if (root -> son[!u])   
                root = root->son[!u],
                res = res * 2 + !u;
            else
                root = root -> son[u],
                res = res * 2 + u;
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie{};
        int ans = 0;
        for (int num: nums) 
        {
            trie.insert(num);
            ans = max(ans, num ^ trie.query(num));
        }
        return ans;
    }
}; 
