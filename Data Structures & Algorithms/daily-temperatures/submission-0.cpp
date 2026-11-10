class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<int> st;

        for(int i=0; i<temperatures.size(); i++) {
            int curr = temperatures[i];

            while(!st.empty() && (temperatures[st.top()] < curr)) {
                int x = st.top();
                st.pop();
                answer[x] = i-x;
            }

            st.push(i);
        }

        return answer;
    }
};
