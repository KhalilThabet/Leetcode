class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate;
        for (auto e:nums){
            if (count==0) candidate=e;
            if (candidate==e) count++;
            else count--;
        }
        return candidate;
    }
};
