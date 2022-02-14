#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int middle;
        while (start<=end){
            middle= start+(end-start)/2;
            if (target > nums[middle]){
                start=middle+1;
            }
            else if (target<nums[middle]){
                end=middle-1;
            }
            else{
                return middle;
            }

        }
        return -1;
    }
};
int main(){
    vector<int> v ={-1,0,3,5,9,12};
    vector<int> v1={5};
    Solution S;
    cout<<S.search(v1,5)<<endl;
    return 0;
}
