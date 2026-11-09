class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);

        // Count frequencies for the initial window
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        // If the initial windows match, a permutation is found
        if (s1_count == s2_count) return true;

        // Slide the window across s2
        int m = s1.length();
        for (int i = m; i < s2.length(); i++) {
            // Add the new character to the window (entering from right)
            s2_count[s2[i] - 'a']++;
            // Remove the oldest character from the window (leaving from left)
            s2_count[s2[i - m] - 'a']--;

            // Check if the current window matches s1's frequency
            if (s1_count == s2_count) return true;
        }

        return false;
    }
};
