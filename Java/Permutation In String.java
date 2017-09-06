public class Solution {
	public boolean checkAllZeros(HashMap<Character, Integer> hmap, String tmp) {
		HashMap<Character, Integer> hmap2 = new HashMap<Character, Integer>();
		hmap2.putAll(hmap);
		for (int i = 0; i < tmp.length(); i++) {
			int value = hmap2.get(tmp.charAt(i));
			if (value != 0) {
				hmap2.put(tmp.charAt(i), value - 1);
			}
		}
		for (char letter = 'a'; letter <= 'z'; letter++) {
			if (hmap2.get(letter) != 0) return false; 
		}
		return true;
	}
 
	public boolean checkInclusion(String s1, String s2) {
        HashMap<Character, Integer> hmap = new HashMap<Character, Integer>();
       	for (char letter = 'a'; letter <= 'z'; letter++) {
			hmap.put(letter, 0);
		}
        for (int i = 0; i < s1.length(); i++) {
            if (hmap.get(s1.charAt(i)) == 0) {
                hmap.put(s1.charAt(i), 1);
            } else {
            	int value = hmap.get(s1.charAt(i));
                hmap.put(s1.charAt(i), value + 1);
            }
        }  
       	int length = s1.length();
       	for (int i = 0; i <= s2.length() - length; i++) {
       		String tmp = s2.substring(i, i + length);
       		if (checkAllZeros(hmap, tmp)) return true; 
       	}
       	return false;
    }
}