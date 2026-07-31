class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target)
             return mid;
            if(nums[mid] > nums[n-1]){   // Part 1
               if(nums[mid] < target)
                low = mid + 1;
               else{      // nums[mid] > target
                  if(nums[0] > target)
                   low = mid + 1;
                  else
                   high = mid - 1;
               }
            }    // Part 1 end
            else{   // Part 2
               if(nums[mid] > target)
                high = mid - 1;
               else{    // nums[mid] < target
                 if(nums[n-1] < target)
                  high = mid - 1 ;
                 else
                  low = mid + 1;
               }
            }    // Part 2 end
        }
        return -1;
    }
};