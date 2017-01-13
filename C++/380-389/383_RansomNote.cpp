class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int length_ransomNote = ransomNote.length();
        int length_magazine = magazine.length();
        if (length_ransomNote > length_magazine) {
            return false;
        }
        map<char, int> hashTable_ransomNote;
        map<char, int> hashTable_magazine;
        for (int i = 0; i < length_ransomNote; i++) {
            if (hashTable_ransomNote.find(ransomNote[i]) == hashTable_ransomNote.end()) {
                hashTable_ransomNote[ransomNote[i]] = 1;
            } else {
                hashTable_ransomNote[ransomNote[i]] += 1;
            }
        }
        for (int i = 0; i < length_magazine; i++) {
            if (hashTable_magazine.find(magazine[i]) == hashTable_magazine.end()) {
                hashTable_magazine[magazine[i]] = 1;
            } else {
                hashTable_magazine[magazine[i]] += 1;
            }
        }
        for (int i = 0; i < length_ransomNote; i++) {
            if (hashTable_magazine.find(ransomNote[i]) == hashTable_magazine.end()) {
                return false;
            }
            if (hashTable_magazine[ransomNote[i]] < hashTable_ransomNote[ransomNote[i]]) {
                return false;
            }
        }
        return true;
    }
};