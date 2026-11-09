class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f(26, 0);

        for(auto& s : s1) f[s-'a']++;

        int k = s1.length();

        for(int i=0; i<s2.length(); i++) {
            f[s2[i]-'a']--;

            if(f[s2[i]-'a'] == 0) k--;
            else k = s1.length();

            if(k == 0) return true;
        } 

        return false;
    }
};
