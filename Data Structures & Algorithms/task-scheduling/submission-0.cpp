class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) freq[task - 'A']++;

        int max_freq = *max_element(freq.begin(), freq.end());
        int max_count = 0;
        for (int count : freq) {
            if (count == max_freq) max_count++;
        }

        int intervals = (max_freq - 1) * (n + 1) + max_count;
        return max((int)tasks.size(), intervals);
    }
};

// between identical tasks there must be n cycles which can either be a process or idleness
// and we need minimum cycles needed ofc
// can store the frequency of every process in the heap
// and need to traverse it 
// say heap contains 3, 1, 1 and n = 3
// so, 2, 0, 0, idle, 1, idle, idle, idle, 0