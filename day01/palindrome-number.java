class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        String text = String.valueOf(x);
        int start = 0;
        int end = text.length() - 1;
        while (start < end) {
            if (text.charAt(start++) != text.charAt(end--)) {
                return false;
            }
        }
        
        return true;
    }
}
