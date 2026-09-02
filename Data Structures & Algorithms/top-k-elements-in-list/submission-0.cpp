class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // min heap
        unordered_map<int, int> frequencies;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(int num : nums){
            frequencies[num] ++;
        }

        for(auto& [num, freq] : frequencies){
            minHeap.push({freq, num});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> answer;
        while(!minHeap.empty()){
            answer.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return answer;
    }
};
