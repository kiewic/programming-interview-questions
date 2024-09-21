class Solution {
    public int searchInsert(int[] nums, int target) {
        int index = 0;
        int length = nums.length;
        while (index < length) {
            if (nums[index] == target) {
                return index;
            }
            if (nums[index] > target) {
                return index;
            }
            index++;
        }
        return index;
    }
}

/*
2 4 6 8 10 12 14 16 18 20 22
length = 11
(end - start) / 2 + start = x
(10 - 0) / 2 + 0 = 5
(10 - 5) / 2 + 5 = 8
(8 - 5) / 2 + 5 = 6
(8 - 6) / 2 + 6 = 7
*/
