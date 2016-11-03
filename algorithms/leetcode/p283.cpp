/* ***
 *  * Move Zeroes
 *   * Given an array nums, write a function to move all 0's to the end of it
 *    * while maintaining the relative order of the non-zero elements.
 *    */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            cout << "Origin Array: " << endl;
            for(auto num : nums)
            {
                cout << num << " ";
            }
            cout << endl;

            int len = nums.size();
            int j = 0;

            for(int i=0; i < len; ++i)
            {
                if(nums[i] != 0)
                {
                    nums[j++] = nums[i];
                }
            }

            for(; j < len; ++j)
            {
                nums[j] = 0;
            }

            cout << "Modified Array: " << endl;
            for(auto num : nums)
            {
                cout << num << " ";
            }
            cout << endl;
        }
};

int main(int argc, char** argv)
{
    int array[] = {0,1,0,3,16,12,0,9};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    Solution solution;
    solution.moveZeroes(nums);
    return 0;
}

