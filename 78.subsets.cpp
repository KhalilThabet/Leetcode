class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> output;
        vector<int> temp;
        int n = nums.size();
        for (int i = pow(2, n); i < pow(2, n + 1); i++)
        {
            string bitmask = std::bitset<11>(i).to_string();
            reverse(bitmask.begin(), bitmask.end());
            temp.clear();
            for (int j = 0; j < n; j++)
                if (bitmask[j] == '1')
                    temp.push_back(nums[j]);
            output.push_back(temp);
        }
        return output;
    }
};
