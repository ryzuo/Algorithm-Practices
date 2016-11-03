/*
 * Problem 1
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ids(2, -1);
       int i=0;
       int len = nums.size();
       for(auto num : nums) {
           for(int j = i+1; j < len; ++j) {
	       std::cout << "num: " << num << ", nums[j]: " << nums[j] << std::endl;
               if(target == (num + nums[j])) {
                   std::cout << "i: " << i << ", j: " << j << std::endl;
                   ids[0] = i;
                   ids[1] = j;
                   break;
	       }
	   }

	   if((ids[0] != -1) && (ids[1] != -1)) {
               break;
	   } else {
	       i++;
	   }
       }

       std::cout << ids[0] << ", " << ids[1] << std::endl;
       return ids;
    }
};

int main(int argc, char** argv) {
    int array[] = {1,3,7,2,9,5};
    int target = 9;
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    Solution solution;
    solution.twoSum(nums, target);
    return 0;
}
