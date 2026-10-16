class Solution {
    public boolean isAnagram(String s, String t) {
        char[] ss = s.toCharArray();
        char[] tt = t.toCharArray();
        Arrays.sort(ss);
        Arrays.sort(tt);
        String s1 = new String(ss); 
        String t2 = new String(tt);

        boolean n = s1.equals(t2);
        return n; 
         }
}