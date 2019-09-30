//link
//https://leetcode.com/contest/weekly-contest-156/problems/unique-number-of-occurrences/
/* 
Given an array of integers arr, write a function that returns true 
if and only if the number of occurrences of each value in the array is unique.
*/

bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cnt; //map is commonly used to count occurences
        unordered_map<int, bool> store; //however map is also used to check the existence of something O(1) time. So why not combine the two?
        
        for(int i = 0; i < arr.size(); i++)
        {
            cnt[arr[i]]++;
        }
        
        map<int, int>:: iterator i;
        for(i = cnt.begin(); i != cnt.end(); i++)
        {
            if(store.count(i->second))
            {
                return false;
            }
            store[i->second] = true;
        }
        
        return true;
    }
