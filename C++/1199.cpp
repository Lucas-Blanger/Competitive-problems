#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector> 

using namespace std;

string decToHexa(int n)
{
    string ans = "";
  
    while (n != 0) {
        int rem = n % 16;
        char ch;

        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
        
        ans += ch;
        n = n / 16;
    }

    int i = 0, j = ans.size() - 1;
    while (i <= j) {
        swap(ans[i], ans[j]);
        i++;
        j--;
    }
    
    return ans;
}

string hexadecimalToDecimal(string hexVal)
{
    int len = hexVal.size();
    int base = 1;
    int dec_val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;
            base = base * 16;
        } else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;
            base = base * 16;
        }
    }
    return to_string(dec_val);
}

int main(){
    string num;
    int num2, x;
    
    while (true) {
        num = "";
        num2 = 0;
        cin >> num;

        if (num[0] == '-') {
            break;
        }

        if (num.find("0x") == 0 || num.find("x", 1) != string::npos) {  
            cout << "0x" + hexadecimalToDecimal(num) << endl;
        } else {
            num2 = stoi(num);  
            cout << decToHexa(num2) << endl;
        }
    }
    
    return 0;
}