class Solution {
    // 用于重载sort函数,(将cmp函数定义为类成员函数，需要将cmp函数在类中定义为static)
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<std::string, int> words;
        for (const auto& word : positive_feedback) {
            words[word] = 3;
        }
        for (const auto& word : negative_feedback) {
            words[word] = -1;
        }


        int n = report.size();
        // first:该学生的分数，second：该学生的编号
        vector<pair<int, int>> scores;
        for (int i = 0; i < n; i ++) {
            // 分割出单词
            stringstream ss;
            ss << report[i];
            string w;
            int sco = 0;
            while (ss >> w) {
                if (words.count(w)) {
                    sco += words[w];
                }
            }
            scores.push_back({sco, student_id[i]});
        }
        sort(scores.begin(), scores.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < k; i ++)
            ans.push_back(scores[i].second);
        return ans;
    }
};