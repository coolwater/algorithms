/*
Check out the resources on the page's right side to learn more about strings. 
The video tutorial is by Gayle Laakmann McDowell, author of the best-selling 
interview book Cracking the Coding Interview.

Alice is taking a cryptography class and finding anagrams to be very useful. 
We consider two strings to be anagrams of each other if the first string's 
letters can be rearranged to form the second string. In other words, both 
strings must contain the same exact letters in the same exact frequency 
For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where 
encryption is dependent on the minimum number of character deletions required 
to make the two strings anagrams. Can you help her find this number?

Given two strings, a and b, that may or may not be of the same length, 
determine the minimum number of character deletions required to make a 
and b anagrams. Any characters can be deleted from either of the strings.

Input Format

The first line contains a single string, . 
The second line contains a single string, .

Constraints

* 1 <= a, b <= 10^4
* It is guaranteed that a and b consist of lowercase English alphabetic 
  letters (i.e., a through z).

Output Format

Print a single integer denoting the number of characters you must delete to 
make the two strings anagrams of each other.

Sample Input

cde
abc

Sample Output

4
Explanation

We delete the following characters from our two strings to turn them into anagrams of each other:

* Remove d and e from cde to get c.
* Remove a and b from abc to get c.

We must delete 4 characters to make both strings anagrams, so we print 4 on a new line.

Submissions: 13817
Max Score: 25
Difficulty: Easy
Rate This Challenge:
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
	
	int ndeletes = 0;
    unordered_map<char,int> anagram;
    char *achars = &a[0];
    char *bchars = &b[0];
   
    // count up characters in this first string into a hashmap
    for (int i=0; i<a.length(); i++) {
        anagram[a[i]] += 1;
    }
   
    // count down characters from the character count hashmap from first string 
    for (int i=0; i<b.length(); i++) {
        anagram[b[i]] -= 1;
    }
   
    // count the characters to be deleted from both strings 
    for (auto ch : anagram) {
        ndeletes += abs(ch.second);
    }
    
    return ndeletes;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}