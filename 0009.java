class Solution {
    public boolean isPalindrome(int x) {
        String s = String.valueOf(x);
        String revS = new StringBuilder(s).reverse().toString();
        return s.compareTo(revS) == 0;
    }
}
