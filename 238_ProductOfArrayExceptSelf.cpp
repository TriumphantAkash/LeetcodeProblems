class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        vector<int> ret;
        int zeroCount = 0;
        //calculate product of all elements except first
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != 0){
                prod = prod*nums[i];
            }
            else
            {
                zeroCount++;
            }
        }
        if(!zeroCount)
        {
            ret.push_back(prod);
            for(int i = 1; i < nums.size(); i++)
            {
                prod = prod/nums[i];
                prod = prod * nums[i-1];
                ret.push_back(prod);
            }
        }
        else
        {
            prod = prod*nums[0];
            if(zeroCount == 1)
            {
                    for(int i = 0; i < nums.size();i++)
                    {
                        if(nums[i] == 0)
                        {ret.push_back(prod);}
                        else
                        {ret.push_back(0);}
                    }
            }
            else
            {
                for(int i = 0; i < nums.size();i++)
                    {
                        ret.push_back(0);
                    }
            }
        }

        return ret;
    }
};