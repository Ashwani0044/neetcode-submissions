class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);

        for(int k=0; k<s.length(); k++) {
            int ch = s[k]-'a';

            last[ch] = k;
        }

        vector<int> res;
        int i=0;

        while(i < s.length()) {
            int end = last[s[i]-'a'];

            for(int j=i; j<end; j++) {
                if(last[s[j]-'a'] > end) {
                    end = last[s[j]-'a'];
                }
            }

            res.push_back(end-i+1);
            i = end+1;

        }

        return res;
    }
};

// we have to calculate the size of the substring i can say in which all the characters should present of that particular substring..
// we need to store the last index of each character 
// can maintain a variable named prev from which we will start the checking of the string and will take the end as the last index of the first character in that string will traverse from the prev to end and if in between i got the character that is going out of the end then we have to change the end and at the end will return the new end and after storing the answer in the result vector, will set the prev = end