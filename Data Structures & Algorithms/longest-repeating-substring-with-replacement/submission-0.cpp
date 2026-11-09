class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxf = 0;
        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.length(); j++) {
            count[s[j] - 'A']++;
            maxf = max(maxf, count[s[j] - 'A']);

            if ((j - i + 1) - maxf > k) {
                count[s[i] - 'A']--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
