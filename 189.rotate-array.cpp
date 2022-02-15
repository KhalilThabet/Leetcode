class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int left = 0;
        int right = nums.size() - 1;
        k %= nums.size();
        int x = nums.size() - k;
        while (x--)
        {
            nums.push_back(nums[left++]);
        }
        auto first = nums.begin() + left;
        auto last = nums.end();
        vector<int> temp(first, last);
        nums = temp;
        return;
    }
};
