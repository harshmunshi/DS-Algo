/*
KMP pattern searching algorithm.

Explanation: Let us assume the following configuration:
string: AABAACAADAABAABA
pattern: AABA

Naive search:

AABAACAADAABAABA
AABA

AABAACAADAABAABA
 AABA

AABAACAADAABAABA
  AABA

Hence for all N-M individial blocks we have iterate N times making the complexity O(N(N-M))

KMP Algorithm:

some observations here will help us steer effectively.

AABAACAADAABAABA
AABA == Match

slide by 1:
AABAACAADAABAABA
 AABA = mismatch at position 2, so we break off

However we see that if we now move the pattern by 1, it makes no sense because the first char is
A again so there SURE WILL BE A MISMATCH. So we move the pattern by 2 units.

AABAACAADAABAABA
   AABA

But how did the magical number 2 come?

References Here: https://medium.com/@giri_sh/string-matching-kmp-algorithm-27c182efa387
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void computeAuxilliary(char* pat, int* aux);

    void
    kmpsearch(char *pat, char *txt)
{
  int M = strlen(pat);
  int N = strlen(txt);

  // Initialize an array of size = pattern
  int aux[M];

  // Write a function to compute it
  computeAuxilliary(pat, aux);

  // assuming we have the aux ready we are good to go
  int i,j = 0;

  // If we are at the end of the txt we are done
  while( i < N){
    if (pat[j] == txt[i]){
      i++;
      j++;
    }

    // Assuming all matched
    if (j == M){
      cout << "Pattern found at " << i-j << endl;
      // Once we have found the pattern there is no need to move strictly by 1
      // we would like to 
      j = aux[j-1];
    }

    // Now assuming there is a mismatch
    else if (i < N && pat[j] != txt[i]){
      if (j != 0){
        j = aux[j-1];
      }

      else{
        i++;
      }
    }
  }
}

void computeAuxilliary(char* pat, int* aux){

  // The first element is always 0
  aux[0] = 0;

  int i = 1;
  int m = 0;

  while (i < strlen(pat))
  {
    if (aux[i] == aux[m]) {
      m += 1;
      aux[i] = m;
      i += 1;
    }

    else if (aux[i] != aux[m] && m != 0){
      m = aux[m-1];
    }

    else{
      aux[i] = 0;
      i += 1;
    }
  }
}


int main()
{
  char txt[] = "ABABDABACDABABCABAB";
  char pat[] = "ABABCABAB";
  kmpsearch(pat, txt);
  return 0;
}