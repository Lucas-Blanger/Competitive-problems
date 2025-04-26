#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,c=0,r=0,s=0, total;
    double pc,pr,ps;
    cin >> n;

    for(int i = 0; i< n;i++){
        int q;
        char t;
        cin >> q >> t;

        if(t == 'C'){
            c += q;
        }
        if(t == 'R'){
            r += q;
        }
        if(t == 'S'){
            s += q;
        }

    }

    total = c + r + s;

    pc = (100.0 * c) / total;
    pr = (100.0 * r) / total;
    ps = (100.0 * s) / total;

    cout << "Total: " << total << " cobaias" << endl;

    cout << "Total de coelhos: " << c  << endl;
    cout << "Total de ratos: " << r  << endl;
    cout << "Total de sapos: " << s  << endl;

    cout << fixed << setprecision(2);

    cout << "Percentual de coelhos: " << pc << " %" << endl;
    cout << "Percentual de ratos: " << pr << " %" << endl;
    cout << "Percentual de sapos: " << ps << " %" << endl;

}