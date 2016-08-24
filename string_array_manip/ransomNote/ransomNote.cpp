class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, char> countOfLettersMap; 
        
        for(int i = 0; i < ransomNote.size(); i++) {
            if(countOfLettersMap.find(ransomNote[i]) == countOfLettersMap.end()) {
                countOfLettersMap[ransomNote[i]] = 0; 
            }
            
            countOfLettersMap[ransomNote[i]]++; 
        }
        
        for(int i = 0; i < magazine.size(); i++) {
            if(countOfLettersMap.find(magazine[i]) != countOfLettersMap.end()) {
                if(countOfLettersMap[magazine[i]] == 1) {
                    countOfLettersMap.erase(magazine[i]); 
                } else {
                    countOfLettersMap[magazine[i]]--; 
                }
            }
        }
        
        return !countOfLettersMap.size(); 
    }
};