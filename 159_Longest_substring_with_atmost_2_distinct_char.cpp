class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = 1;
        int maxLen = 1;
        int i = 0;
        int j = 1;
        unordered_map<int, int> um;
        unordered_map<int, int>::iterator itr;
        um.insert({s[i], 1});
        while(j < s.size())
        {
            if(um.size() == 2 && um.find(s[j]) == um.end())
            {
                while(um.size() == 2)
                {
                    itr = um.find(s[i]);
                    itr->second--;
                    if(itr->second == 0)
                    {um.erase(itr);}
                    len--;
                    i++;
                }
                j--;
            }
            else
            {
                itr = um.find(s[j]);
                if(itr == um.end())
                {um.insert({s[j], 1});}
                else
                {itr->second++;}
                len++;
                maxLen = max(len, maxLen);
            }

            j++;
        }
        return maxLen;    
    }
};