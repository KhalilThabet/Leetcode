class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> temp;
        vector<int> output;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (temp.find(numbers[i]) != temp.end())
            {
                output.push_back(temp[numbers[i]]+1);
                output.push_back(i+1);
            }
            temp[target - numbers[i]] = i;
        }
        return output;
    }
};
