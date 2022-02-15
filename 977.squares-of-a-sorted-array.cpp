class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        int right=n-1,left=0,pointer=n-1;
        while(left<=right){
            if (abs(nums[right])>abs(nums[left])){
                result[pointer--]=nums[right]*nums[right];
                right--;
            }
            if (abs(nums[left])>=abs(nums[right])){
                result[pointer--]=nums[left]*nums[left];
                left++;
            }
        }
        return result;
    }
};
