class Solution
{
public:
    string reverseWords(string s)
    {
        string output = "";
        string tempStr="";
        for (char e : s)
        {
            
            if (e == ' ')
            {
                output += tempStr + ' ';
                tempStr = "";
            }
            else
            {
                tempStr = e + tempStr;
            }
        }
        output += tempStr;
        return output;
    }
};
