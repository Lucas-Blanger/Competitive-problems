#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string a,b;
        cin >> a >> b;

        string nova = "";
        int ta, tb;
        ta = a.size();
        tb = b.size();

        if(ta > tb){
            for(int j = 0, y=0; j < tb; j++){
                if(j != tb){
                    nova += a[j];
                    nova += b[j];
                }
            }
            nova += a.substr(tb);
        }else{
            for(int j = 0, y=0; j < ta; j++){
                if(j != ta){
                    nova += a[j];
                    nova += b[j];
                }
            }
            nova += b.substr(ta);
        }
        cout << nova << endl;
    }
}