//https://leetcode.com/problems/3sum/
//this is the classic follow up to two sum. 


//this is the first solution using a for loop and implementing two sum technique.
class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        const int target = 0;

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
                for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
                    if (j - 1 > i  && nums[j] == nums[j - 1]) {  // Skip duplicated.
                        ++j;
                    } else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicated.
                        --k;
                    } else {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target) {  // Should decrease sum.
                            --k;
                        } else if (sum < target) {  // Should increase sum.
                            ++j;
                        } else {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            ++j, --k;
                        }
                    }
                }
            }
        }

        return ans;
    }
};


//second solution is pretty similar except their is target sum, and duplicates are allowed
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
	
  // Write your code here.
	vector<vector<int>> ans;
	//solution, should be O(n^2), one for loop, and two pointers.
	sort(array.begin(), array.end()); // two pointers only work for sorted array. 
	int n = array.size();
	for(int i = 0; i < n; i++)
	{
		//apply two pointers...
		int st = i+1;
		int end = n-1;
		while(st < end) {
			int currentSum = array[i] + array[st] + array[end];
			if(currentSum == targetSum) {
				//ok good, we found one triplet, but there could be more
				//and no duplicates, so move both pointers is the only way.
				ans.push_back({array[i], array[st], array[end]});
				st++;
				end--;
			}
			else if(currentSum < targetSum) {
				// this means that the smallest pointer is too small.
				st++;
			}
			else {
				//biggest pointer is too big.
				end--;
			}
		}
		
		
	}
	return ans;
}


