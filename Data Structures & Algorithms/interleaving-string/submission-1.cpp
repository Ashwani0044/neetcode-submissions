class Solution {
private:
    vector<vector<int>> memo;

public:
    bool dfs(string& s1, string& s2, string& s3,
             int i, int j, int k) {

        if (k == s3.size())
            return true;

        if (memo[i][j] != -1)
            return memo[i][j];

        bool takeS1 = false, takeS2 = false;

        if (i < s1.size() && s1[i] == s3[k])
            takeS1 = dfs(s1, s2, s3, i + 1, j, k + 1);

        if (j < s2.size() && s2[j] == s3[k])
            takeS2 = dfs(s1, s2, s3, i, j + 1, k + 1);

        return memo[i][j] = takeS1 || takeS2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        memo.assign(s1.size() + 1,
                    vector<int>(s2.size() + 1, -1));

        return dfs(s1, s2, s3, 0, 0, 0);
    }
};