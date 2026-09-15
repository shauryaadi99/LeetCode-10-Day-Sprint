class Solution {
    public String reverseVowels(String s) {
        int n = s.length();
        List<Character> list = new ArrayList<>();
        Set<Character> vow = new HashSet<>();
        vow.add('a');
        vow.add('e');
        vow.add('i');
        vow.add('o');
        vow.add('u');

        vow.add('A');
        vow.add('E');
        vow.add('I');
        vow.add('O');
        vow.add('U');

        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (vow.contains(ch)) {
                list.add(ch);
            }
        }
        Collections.reverse(list);
        int j = 0;
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (vow.contains(ch)) {
                sb.setCharAt(i, list.get(j++));
            }
        }
        return sb.toString();

    }
}