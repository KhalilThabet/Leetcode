class Solution
{
public:
    int compare(string s, char c, int &index)
    {
        for (int i = 0; i < s.size(); i++)
        {   char a;
            a=s.substr(i,1)[0];
            if (a == c)
            {
                index = i;
                return 1;
            }
        }
        return 0;
    }
    int lengthOfLongestSubstring(string s)
    {
        int longest = 0;
        string rep = "";
        for (char e : s)
        {
            int index = -1;
            if (compare(rep, e, index))
            {
                rep = rep.substr(index+1, rep.size() +1- index) + e;
            }
            else
            {
                rep += e;
                if (longest < rep.size())
                    longest = rep.size();
            }
        }
        return longest;
    }
};
