class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map1[26]={0};
        int map2[26]={0};
        if (s1.size()>s2.size()) return false;
        int count=26;
        for (int i=0;i<s1.size();i++){
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
            if (map1[s1[i]-'a'] != map2[s1[i]-'a']) count--;
            else if (s1[i]!=s2[i]){
                count++;
            }
            if (map1[s2[i] - 'a'] != map2[s2[i] - 'a'])
                count--;
            else if (s1[i] != s2[i])
            {
                count++;
            }
        }
        //ab ncba
        for (int i = 0; i < s2.size() - s1.size(); i++)
        {
            int right = s2[i + s1.size()] - 'a';
            int left = s2[i] - 'a';
            if (count == 26)
                return true;
            map2[right]++;
            if (map2[right] == map1[right])
                count++;
            else if (map2[right] == map1[right] + 1)
                count--;
            map2[left]--;
            if (map2[left] == map1[left])
                count++;
            else if (map2[left] == map1[left] - 1)
                count--;
        }
        return count == 26;
    }
};
