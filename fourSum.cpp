// this problem combines techniques of 3 sum, and 3 sum combines techniques of two sum. Interesting problem



//solution 1 O(n^3). 
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int len = nums.size();
        for(int i=0; i < len-3; i++) //this outer for loop is essentially the only new thing, sadly it makes it O(n^3).
        {
            if(i!=0 && nums[i] == nums[i-1])//prevents duplicates and also out of bounds error
            {
                continue;
            }
            for(int j = i+1; j < len-2; j++)
            {
                if(j!=i+1 && nums[j] == nums[j-1]) 
                {
                    continue;
                }
                int left = j+1;
                int right = len-1;
                while(left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target)
                    {
                        left++;
                    }
                    else if(sum > target)
                    {
                        right--;
                    }
                    else 
                    {
                        vector<int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[left]);
                        quad.push_back(nums[right]);
                        ans.push_back(quad);
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1])
                        {
                            left++;
                        }
                        while(left < right&& nums[right] == nums[right+1])
                        {
                            right--;
                        }
                    }
                    
                }
            }
        }
        return ans;
    }
};


//solution 2 avg case is O(n^2), worst case O(n^3) //for DISTINCT integers.

#include <vector>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > fourNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	vector<vector<int>> ans;
	unordered_map<int, vector<vector<int>>> hash;
	int size = array.size();
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i+1; j < size; j++) 
		{
			int pair = array[i] + array[j];
			int diff = targetSum - pair;
			//check if the diff is in hash if it is good.
			if(hash.count(diff)) 
			{
				for(auto pairInDiff: hash[diff]) 
				{
					pairInDiff.insert(pairInDiff.end(), array[i]);
					pairInDiff.insert(pairInDiff.end(), array[j]);
					ans.push_back(pairInDiff);
				}
			}
		}
		for(int k = 0; k < i; k++) 
		{
			int sumToHash = array[k] + array[i];
			if(hash.count(sumToHash)) 
			{
					hash[sumToHash].push_back({array[k], array[i]});
			}
			else
			{
				hash[sumToHash] = {{array[k], array[i]}};
			}
		}
	}
	
	return ans;
	
}

