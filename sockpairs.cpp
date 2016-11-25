/*
Related Algorithms: Sock Merchant
Link: https://www.hackerrank.com/challenges/sock-merchant


Problem Description

John's clothing store has a pile of n loose socks where each sock i is 
labeled with an integer, Ci, denoting its color. He wants to sell as many 
socks as possible, but his customers will only buy them in matching pairs. 
Two socks, i and j, are a single matching pair if Ci == Cj.


Given n and the color of each sock, how many pairs of socks can John sell?


Input Format

The first line contains an integer, n, denoting the number of socks. 
The second line contains n space-separated integers describing the 
respective values of C0,C1,C2,..., Cn-1.


Constraints

1 <= n <= 100
1 <= Ci <= 100


Output Format

Print the total number of matching pairs of socks that John can sell.


Solution
Given an array of sock colors, just instantiate a hashmap 
(unordered_map<string, int>), iterate over the array of socks colors, 
and keep adding the color to the hashmap and increment the count of 
number of times we have seen the sock color. Once we have bucketed all 
the socks based on the unique colors, now find how many pairs of socks 
of each color can be grouped, by dividing the count by 2 and using 
floor() method to give us whole sock pairs we can create 
{floor(color-count/2))}. LeetCode uses a color code instead of a string,
 as colors are represented in a computer system as a RGB value, 
 usually 8bit/16bit/32bit colors like 0xf0ab55, 0x0456cc, 0xda5f2d,...
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sockPairs(vector<int> colors) {
        unordered_map<int, int> sockmap;
        
        for (int i=0; i<colors.size(); i++) {
            sockmap[colors[i]] += 1;
        }
        
        int npairs = 0;
        for (auto sock : sockmap) {
            npairs += floor(sock.second/2);
        }
        return npairs;
    }
};

int main() {

    Solution sol;
    
    int n;
    
    cin >> n;
    vector<int> socks(n);

    for (int i = 0; i < n; i++)
       cin >> socks[i];
    
    cout << sol.sockPairs(socks) << endl;

    return 0;
}
