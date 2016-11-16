/*
 * Consider an array of n integers, A=[A0,A1,A2,...,An-1], where all but 
 * one of the integers occur in pairs. In other words, every element 
 * in  occurs exactly twice except for one unique element.
 * Given A, find and print the unique element.
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

int lonely_integer(vector < int > a) {
    int result = 0;

    /* The proof follows from properties of xor:
    ** a^b=b^a
    ** a^a=0
    ** a^0=a
    ** a^(b^c)=(a^b)^c

    The first one lets us reorder the numbers in any way without the xor being affected. 
    Then, we get the xor as (a^a)^(b^b)^(c^c)^...^(r^r)^s, which is 0^0^0^...^0^s=s.
    */
    
    for (auto num : a) {
        result = result ^ num;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << lonely_integer(a) << endl;
    return 0;
}
