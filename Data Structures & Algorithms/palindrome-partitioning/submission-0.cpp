class Solution {
public:
    bool pal(string &s, int i, int j) {

        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> ans;

    void solve(int i, string& s, vector<string>& curr) {
        if(i >= s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int j=i; j<s.length(); j++) {
            if(pal(s, i, j)) {
                curr.push_back(s.substr(i, j-i+1));
                solve(j+1, s, curr);
                curr.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(0, s, curr);
        return ans;
    }
};
