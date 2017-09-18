class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        if (s == "") return true;
        boolean[] canWordBreak = new boolean[s.length() + 1];
        canWordBreak[0] = true;
        int maxLength = getMaxLength(wordDict);
        for (int i = 1; i <= s.length(); i++) {
            canWordBreak[i] = false;
            for (int j = 1; j <= maxLength && j <= i; j++) {
                if (!canWordBreak[i - j]) continue;
                String word = s.substring(i - j, i);
                if (wordDict.contains(word)) {
                    canWordBreak[i] = true;
                    break;
                }
            }
        }
        return canWordBreak[s.length()];
    }
    
    private int getMaxLength(List<String> words) {
        if (words == null || words.size() == 0) return 0;
        int maxLength = 0;
        for (String word : words) {
            maxLength = Math.max(maxLength, word.length());
        }
        return maxLength;
    }
}