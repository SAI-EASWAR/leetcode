class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0, n = str1.size(), m = str2.size();

        while(i < n and j < m){
            
            if((str1[i]-'a' == str2[j]-'a') || (str1[i]-'a'+1)%26 == str2[j]-'a')
            j++;

            i++;
        }

        if(j==m)
        return true;

        return false;
    }
};