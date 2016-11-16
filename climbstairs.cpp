/*
 * Davis has 's' staircases in his house and he likes to climb each 
 * staircase 1, 2, or 3 steps at a time. Being a very precocious child,
 * he wonders how many ways there are to reach the top of the staircase.
 * Given the respective heights for each of the 's' staircases in 
 * his house, find and print the number of ways he can climb each 
 * staircase on a new line.
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

class Solution {
public:
    int climbStairsDP(int n) {
        
        if (n < 0)
            return 0;
        else if (n <= 1)
            return 1;
            
        vector<int> steps(n+1);

        steps[0] = 1;
        steps[1] = 1;
        steps[2] = 2;

        // just like fibonacci
        for (int i=3; i<=n; i++) {
            steps[i] = steps[i-1] + steps[i-2] + steps[i-3];
        }
        return steps[n];
    }
};


int main(){
    Solution sol;
    
    int s;
    cin >> s;
    vector<int> n(s);
    for(int a0 = 0; a0 < s; a0++){
        cin >> n[a0];

    }
    
    for(int a0 = 0; a0 < s; a0++){
        cout << sol.climbStairsDP(n[a0]) << endl;
    }
    return 0;
}
