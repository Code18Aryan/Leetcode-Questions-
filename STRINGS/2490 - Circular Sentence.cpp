#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {

        vector<string> words;
        stringstream ss(sentence);

        string word;

        while(ss >> word){

            words.push_back(word);
        }

        int n = words.size();

        if( n == 1){
             
            string temp = words[0];

            if(temp[0] != temp[temp.size()-1]) return false;

            else return true; 
        }


        if( n == 2){
             
              string str1 = words[0];
              string str2 = words[1];

              char ch1 = str1[0], ch2 = str1[str1.size()-1], ch3 = str2[0], ch4 = str2[str2.size()-1];

              if(ch1 != ch4 || ch3 != ch2) return false;

              else return true;
        }

        if(n == 3){

             string prev = words[0];
             string current = words[1];
             string next = words[2];

             char lastFirst = prev[0];
             char lastChar = prev[prev.size()-1];
             char currChar = current[0];
             char currLast = current[current.size()-1];
             char nextFirst = next[0];
             char nextLast = next[next.size()-1];

              if(lastChar != currChar || currLast != nextFirst || lastFirst != nextLast ) return false;
             
              
        }

        for(int i=1; i<n-1; i++){
             
             string prev = words[i-1];
             string current = words[i];
             string next = words[i+1];

             char lastChar = prev[prev.size()-1];
             char currChar = current[0];
             char currLast = current[current.size()-1];
             char nextFirst = next[0];
             

             if(lastChar != currChar || currLast != nextFirst) return false;
        }

        return true;
        
    }
};

int main() {
	

	Solution Leetcode;
	
	string str = "leetcode exercises sound delightful";
	string str2 = "eetcode";
	string str3 = "Leetcode is cool";
	
	cout<<Leetcode.isCircularSentence(str)<<endl;
	cout<<Leetcode.isCircularSentence(str2)<<endl;
	cout<<Leetcode.isCircularSentence(str3)<<endl;
	

}
