class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int[] digits = new int[10];
        int end = 0;
        while (x > 0) {
            digits[end++] = x % 10;
            x = x / 10;
        }
        
        int start = 0;
        end--;
        while (start < end) {
            if (digits[start++] != digits[end--]) {
                return false;                
            }
        }
        
        return true;
    }
}
