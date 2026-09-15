class Solution {
    public void reverseString(char[] s) {
        int n = s.length;
        StringBuilder sb= new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            sb.append(s[i]);
        }
        int i=0;
        for(char ch:s){
            s[i] = sb.charAt(i++);
        }
    }
}