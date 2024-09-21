class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        int length = nums.length;
        for (int i = 0; i < length; i++)
        {
            if (k == 0 || nums[k - 1] != nums[i]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
}
