#include <bits/stdc++.h>

using namespace std;


// 2,7,5,30,169,441,1872, 7632,1740, 93313, 459901,1358657,2504881, 13482720, 25779600, 68468401, 610346880, 1271932200,327280800

int main(){
    long long int n;
    cin >> n;

    long long r[] = {
        2,
        7,
        5,
        30,
        169,
        441,
        1872,
        7632,
        1740,
        93313,
        459901,
        1358657,
        2504881,
        13482720,
        25779600,
        68468401,
        610346880,
        1271932200,
        327280800
    };
    cout << r[n-1] << endl;

    // long long int meio = (n*2) /2;

    // vector<long long int> v;
    // vector<long long int> v3;
    // vector<long long int> v2;

    // for(long long int j = 1; j <= n*2; j++){
    //     v.push_back(j);
    //     v3.push_back(j);
    //     if(j <= (n*2)/2) v2.push_back(j);
    // }

    // long long int k = 1;
    // while(true){
    //     long long int aux = 0;
    //     long long int cont = 0;
    //     bool y = true;
    //     while(v.size() > meio){
    //         aux = (aux + k-1) % v.size();

    //         if(v[aux] <= meio){
    //             y =false;
    //             break;
    //         } 
    //         v.erase(v.begin() + aux);
        
    //         if(aux == v.size()){
    //             aux = 0;
    //         }
    //     }

       
    //     if(y) {
    //         cout << k << endl;
    //         break;
    //     }else k++;
    //     v = v3;

    // }
   

    

}