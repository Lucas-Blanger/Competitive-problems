#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n, qbitsChange = 0, total=0;
    double taxa;
    string s,t;
    cin >> n;
    cin >> s;
    cin >> t;

    for(int i = 0; i < n;i++){
        if(s[i] == '*'){
            total++;
            if(t[i] != '*'){
                qbitsChange++;
            }
        } 
        
    }
     taxa = (double)qbitsChange / total;
    cout << fixed << setprecision(2);
    cout << taxa << endl;


    
}