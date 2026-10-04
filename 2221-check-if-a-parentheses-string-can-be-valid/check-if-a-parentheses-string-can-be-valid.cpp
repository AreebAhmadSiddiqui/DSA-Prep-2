class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if (n % 2)
            return false;

        int low = 0, high = 0;

        for (int i = 0; i < n; i++) {

            if (locked[i] == '0') { // wild card like 678
            
                // Can choose '(' or ')'
                low--;
                high++;
            }
            else {
                if (s[i] == '(') {
                    low++;
                    high++;
                }
                else {
                    low--;
                    high--;
                }
            }

            if (high < 0)
                return false;

            low = max(0, low);
        }

        return low == 0;
    }
};