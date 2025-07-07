#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define muitlogrande unsigned long long

bool perfeito(muitlogrande int x){
    muitlogrande int s = sqrt(x);
    return s * s == x;
}

bool fib(muitlogrande int n){
    return perfeito(5 * n * n + 4) || perfeito(5 * n * n - 4);
}

int main(){
    muitlogrande int k, n;
    cin >> k;

    vector<muitlogrande int>v;

    for (int i = 0; i < 200000; i++){
        if (!fib(i+1)){
            v.push_back(i+1);
        }
            
        if (v.size() == k){
            break;
        }

    }

    cout << v[v.size()-1] << endl;


}