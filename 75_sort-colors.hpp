#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;  // 指向0的右边界
        int right = nums.size() - 1;  // 指向2的左边界
        int curr = 0;  // 当前处理的位置
        
        while (curr <= right) {
            if (nums[curr] == 0) {
                // 当前元素是0，与left位置交换，left和curr都前进
                swap(nums[curr], nums[left]);
                left++;
                curr++;
            } else if (nums[curr] == 2) {
                // 当前元素是2，与right位置交换，right后退，curr不动
                swap(nums[curr], nums[right]);
                right--;
                // 注意：curr不前进，因为交换过来的元素还没有处理
            } else {
                // 当前元素是1，直接前进
                curr++;
            }
        }
    }
};
