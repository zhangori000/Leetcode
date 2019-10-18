/* things I elarned fromt hsi:
first, min function can only compare two intgers. But min function can also return the min of a list)
so make sure t do do main({1, 2, 3, 4, 5}) WITH THOSE BRACKETS

second I also learned that a - 'a' = 0 and b- 'a' = 1


*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[300];
        memset(cnt, 0, sizeof(cnt));
        string letters = "balon";
        for(auto c : text)
        {
            ++cnt[c];
           
        }
        
         return min({cnt[letters[0]], cnt[letters[1]], cnt[letters[2]]/2, cnt[letters[3]]/2, cnt[letters[4]]});
    }
};
