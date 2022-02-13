// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;
class Solution {
public:
    vector<string> output;
    void helper(int n,string s,int i ,int j){
        if (i==n && j==n){
            output.push_back(s);
            return;
        }
        if (i>n || j>n) return;
        if (j>i) return;
        helper(n,s+'(',i+1,j);
        helper(n,s+')',i,j+1);
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        helper(n,s,0,0);
        return output;
    }
};

// int main(){
//     Solution S;
//     for (auto e : S.generateParenthesis(4)) cout<<e<<endl;
// }
