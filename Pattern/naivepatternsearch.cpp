/* Naive pattern search.
   Given a block of text and a pattern, write a function that returns 
   all occurances of pattern in the text.
*/

#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Function for naive search

void naivesearch(char* pattern, char* txt){
    // now we run two for loops comparing each and every character
    
    int M = strlen(pattern);
    int N = strlen(txt);

    // important to note that to check the last match the start index should be N-M
    // otherwise the pattern will jump outside the text

    for (int i = 0; i < N-M; i++){
        // looping over all the text blocks incrementally
        int j;
        for (j = 0; j < M; j++){
            if (txt[i + j] != pattern[j]){
                break;
            }
        }
        if (j == M){
            // this means all the characters matched till the end
            cout << "Pattern matched at index " << i << endl;
        }
        
    }

}

int main(){

    char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 

    naivesearch(pat, txt);
    return 0;
}