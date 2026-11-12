class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> fr;
        for (int h : hand) fr[h]++;

        while (!fr.empty()) {
            int start = fr.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                int curr = start + i;
                if (fr.find(curr) == fr.end()) {
                    return false;
                }
                fr[curr]--;
                if (fr[curr] == 0) {
                    fr.erase(curr);
                }
            }
        }
        return true;
    }
};
