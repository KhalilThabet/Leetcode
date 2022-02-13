#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {

        stack<int> storage;
        int count = 0;
        for (auto e : s)
        {
            if (e == '[' || e == '(' || e == '{')
            {
                storage.push(e);
                count++;
            }
            else if (!storage.empty() && (storage.top() == '(' && e == ')' || storage.top() == '[' && e == ']' || storage.top() == '{' && e == '}'))
            {
                count--;
                storage.pop();
            }
            else
                return false;
        }
        if (count == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution S;
    cout << S.isValid("([)]") << endl;
    cout << S.isValid("([{})]") << endl;
    cout << S.isValid("([{}])") << endl;
    cout << S.isValid("]") << endl;
    cout << S.isValid("(((") << endl;
    cout << S.isValid("([])") << endl;
}
