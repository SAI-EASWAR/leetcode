class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s = "";
        int n = sentence.length(), space = 0;
        for(int i=0;i<n;i++){
            if(sentence[i] == ' '){
                if(s.find(searchWord) == 0){
                    return space + 1;
                }
                s = "";
                space++;
            }
            else
            s+=sentence[i];
        }
        if(s.find(searchWord) == 0){
            return space + 1;
        }
        return -1;
    }
};