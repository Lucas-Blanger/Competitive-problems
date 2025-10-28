#include <bits/stdc++.h>

using namespace std;


int main(){
    string cutoff, num;
    while (cin >> num >> cutoff){
        if(num[0] == '.'){
            string nnum = "";
            nnum += '0';
            for(int i = 0; i < num.size(); i++){
                nnum += num[i];
            }
            num = nnum;
        }


        string fraq = "0.";

        int p = num.find('.');

        for(int i = p+1; i < num.size(); i++){
            fraq += num[i];
        }
        double dnum, dc, aux;

        aux = stod(fraq);

        dnum = stod(num);
        dc = stod(cutoff);

        int r;

        if(dc < aux){
            r = ceil(dnum);

        }else{
            r = floor(dnum);

        }

        cout << r << endl;
        
    }
    
}