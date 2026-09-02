class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //hash set of array, check if n-1 is in set, if not start candidate
        unordered_set<int> seen(nums.begin(), nums.end());

        int max_seq = 0;
        for(int& num : nums){
            int candidate = 1;
            if(seen.find(num-1) == seen.end()){
                // we have a new potential start, try and find as many next members
                int i = 1;
                //while the next number is in the set, grow our candidate
                while(seen.find(num+i) != seen.end()){
                    candidate +=1;

                    i++;

                }
            max_seq = max(max_seq, candidate);
            }
        }
        return max_seq;
    }
};
