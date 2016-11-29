/*
 * Time: 1:30hrs
 * TEST CASES:
 * 1234567890123456789 * 9876543210987654321 = 12193263113702179522374638011112635269
 * 53 * 82 = 4346
 * 99 * 99 = 9801
 * 00000 * 00000 = 0
 * 12345 * 000 = 0
 * 00000 * 98765 = 0
 * 99999999999999999999999999999 * 12345678901234567890 = 1234567890123456788999999999987654321098765432110
 * 12193263113702179522374638011112635269 * 12193263113702179522374638011112635269 = 148675665359970170107242319736897034190713620276063953863305906621822702361
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    string prodbignum(string anum, string bnum) {
        vector<int> a(anum.length());
        vector<int> b(bnum.length());  
          
        for (int i=anum.length()-1, j=0; i>=0; i--, j++) {
            a[j] = anum[i] - '0';
        }

        for (int i=bnum.length()-1, j=0; i>=0; i--, j++) {
            b[j] = bnum[i] - '0';
        }
        
        std::vector<int> c(anum.length()+bnum.length()+1);
        int startidx = 0;
        int k = 0;
        for (int j=0; j<b.size(); j++) {
            k = startidx;
            int prodcarry = 0;
            int sumcarry = 0;
            for (int i=0; i<a.size(); i++) {

                int product = a[i] * b[j] + prodcarry;
                int remainder = product % 10;
                prodcarry = product / 10;
                int sum = c[k] + remainder + sumcarry;
                c[k++] = sum % 10;
                sumcarry = sum / 10;
                
                if ((i == a.size()-1) && (prodcarry + sumcarry > 0)) {
                    sum = prodcarry + sumcarry;
                    c[k++] = sum % 10;
                    int finalcarry = sum / 10; // might always be '0'
                    if (finalcarry > 0) {
                        c[k++] = finalcarry;
                    }                        
                }
            }
            startidx++;
        }
        
        stringstream ssc;
        for (int i=k-1; i>=0; i--) {
            ssc << c[i];
        }
        ssc << '\0';
        return ssc.str();
    }
};

int main() {
    string a, b;
    
    cin >> a;
    cin >> b;
    
    Solution sol;
    cout << a << " * " << b << " = " << sol.prodbignum(a, b) << endl;
}
