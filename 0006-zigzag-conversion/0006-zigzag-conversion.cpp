class Solution {
public:
    string convert(string s, int numRows) {

        int n = s.length();

        if(numRows == 1 || n <= numRows)
            return s;

        string ans;
        ans.reserve(n);

        int cycle = 2 * (numRows - 1);

        // First row
        for(int i = 0; i < n; i += cycle)
        {
            ans.push_back(s[i]);
        }

        // Middle rows
        for(int row = 1; row < numRows - 1; row++)
        {
            for(int i = row; i < n; i += cycle)
            {
                ans.push_back(s[i]);

                int diagonal = i + cycle - 2 * row;

                if(diagonal < n)
                    ans.push_back(s[diagonal]);
            }
        }

        // Last row
        for(int i = numRows - 1; i < n; i += cycle)
        {
            ans.push_back(s[i]);
        }

        return ans;
    }
};