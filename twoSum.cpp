//two sum 
//hashmap O(n). 
//


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m; //number and the index
        
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if(m.count(diff))
            {
                return {m[diff],i};
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};
