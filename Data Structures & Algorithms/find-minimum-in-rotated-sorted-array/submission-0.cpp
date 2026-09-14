class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[right] < nums[mid]){
                left = mid + 1;
            } else if (left == right){
                return nums[left];
            } else{
                right = mid;
            }
        }
        return 0;
    }
};
