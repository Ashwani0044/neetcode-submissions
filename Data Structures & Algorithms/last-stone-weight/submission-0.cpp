class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;

        for(auto& n : stones) heap.push(n);

        while(true) {
            if(heap.size() < 2) break;

            int a = heap.top(); heap.pop();
            int b = heap.top(); heap.pop();

            int diff = abs(a-b);

            if(diff!=0) heap.push(diff); 
        } 

        return heap.empty()?0:heap.top();
    } 
};
