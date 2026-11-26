class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        if(digits[n-1] < 9) {
            digits[n-1]++;
            return digits;
        }

        int x = n-1;

        while(x >= 0 && digits[x] == 9) {
            digits[x] = 0;
            x--;
        }

        if (x == -1) {
            digits.resize(n + 1, 0);
            digits[0] = 1;
        } else {
            digits[x]++;
        }

        return digits;
    }
};
