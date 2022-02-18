class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size()-1;
        int counter=n;
        while (counter>=0){
            s.push_back(s[counter--]);
        }
        s=vector<char>(s.begin()+n+1,s.end());
    }
};
