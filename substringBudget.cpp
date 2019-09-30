/*
https://leetcode.com/contest/weekly-contest-156/problems/get-equal-substrings-within-budget/
description found above
two solutions, brute force (n^2) or sliding window o(n);
*/
// brute force
    int equalSubstring(string s, string t, int maxCost) {
      
        vector<int> costs;
        for(int i = 0; i < s.length(); i++)
        {
            int c = abs(s[i] - t[i]);
            costs.push_back(c);
        }
        int originalMaxCost = maxCost;
        int maxLength = 0;
        for(int i = 0; i < s.length(); i++)
        {
            maxCost = originalMaxCost;
            

            int j = i;
            while(j < s.length())
            {
                maxCost -= costs[j];
                if(maxCost >= 0)
                {
                    j++;
                }
                else
                {
                    
                    if( j-i > maxLength){
                        maxLength = j-i;
                    }
                    break;
                }
            }
            if(j-i > maxLength)
            {
                maxLength = j-i;
            }
        }
        
        return maxLength;
      
    }
    
    
    
// sliding window
int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        
        
        while(i < s.length()){
            maxCost-=abs(s[i]-t[i]);
            i++; 
            
            if(maxCost < 0) //thats a problem lol
            {
                maxCost+=abs(s[j]-t[j]);
                j++;
            }
            
            /* the if case for when the maxCost goes negative is after the i increment.
            [a1, a2, a3, a4, a5]...
             j        i                 lets say our i pointer has reached that value. 
            what that means is that the max length SO FAR is 2. And... we COULD move the j pointer...
            one to the right, and examine something like this (where i stays put): 
             [a1, a2, a3, a4, a5]...
                  j    i                
                  
            however, this is useless since we already determined the maxLength is 2, why would we even bother     checking
            for some substring whose length is 1? Therefore, the i++ at the super beginning is absolutely necessary
            because we want to ensure that i pointer always moves. 
            */
            
        }
        return i-j;
    }
