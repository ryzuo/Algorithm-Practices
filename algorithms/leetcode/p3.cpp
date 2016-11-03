#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> v(256, -1);
            int occurrence = -1;
            int maxLen = 0;
            size_t len = s.size();
            for(int i=0; i<len; ++i) {
                if(v[s[i]] > occurrence) {
                    occurrence = v[s[i]];
                }
                v[s[i]] = i;
                maxLen = max(maxLen, i - occurrence);
            }

            return maxLen;
        }
};


int main(int argc, char** argv) {
    if(argc != 2) {
        cout << "Please enter the correct arguments." << endl;
        return 0;
    }

    string s(argv[1]);

    Solution sol;
    int maxLen = sol.lengthOfLongestSubstring(s);

    cout << "The max length is " << maxLen << endl;

    return 0;
}
