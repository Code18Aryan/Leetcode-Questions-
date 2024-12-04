#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool checkValid(string s1 , string s2){
         
         int n = s2.size();
         int left = 0;
         int right = 0;

         while( right < n){
              
             if(s1[left++] != s2[right++]) return false;
         }

         return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {

        vector<string> words;

        stringstream ss(sentence);

        string word;

        while( ss >> word){
             
              words.push_back(word);
        }

        int n = words.size();

        for(int i=0; i<n; i++){
             
             if(checkValid(words[i],searchWord)) return i+1;
        }

        return -1;
        
    }
};

int main() {
    
    Solution leetcode;
	
	string sentence = "i love eating burger", searchWord = "burg";
	string s1 = "this problem is an easy problem", s2 = "pro";
	
	cout<<leetcode.isPrefixOfWord(sentence,searchWord)<<endl;
	cout<<leetcode.isPrefixOfWord(s1,s2)<<endl;

}
