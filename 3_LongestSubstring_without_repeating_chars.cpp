class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size = s.size();
        if(size < 2)
        {return size;}

        int subStringLen = 1;
        int maxLen = 1;
        int i = 0;
        int j = 1;
        unordered_set<char> us;
        us.insert(s[i]);
        while(j < size)
        {
            //if s[j] present in the map
            if(us.find(s[j]) != us.end())
            {
                //move i until the previous occurance of s[j], while removing elements from map
                while(s[i] != s[j])
                {
                    us.erase(s[i]);
                    i++;
                    subStringLen--;
                }

                //remove previous occurance of s[j] too
                us.erase(s[i]);

                //set i to next to that occurance
                i++;

                //put s[j] into map too
                us.insert(s[j]);
            }
            else
            {
                //put s[j] in set, increment max;
                us.insert(s[j]);
                subStringLen++;
                maxLen = max(maxLen, subStringLen);
            }
            j++;
        }
        return maxLen;
    }
};