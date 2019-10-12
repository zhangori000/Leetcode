string removeDuplicates(string s, int k) {
        vector<pair<int, char> > Stack = {{0, '#'}}; // if this first arugment is zero, then the string() function won't count it. 
        
        for(char c: s)
        {
            if(Stack.back().second == c)
            {
                if(++Stack.back().first == k)
                {
                    Stack.pop_back();
                }
            }
            else
            {
                Stack.push_back({1, c});
            }
        }
        string res;
        for(auto & c: Stack)
        {
            res+= string(c.first, c.second);
        }
        return res;
         
