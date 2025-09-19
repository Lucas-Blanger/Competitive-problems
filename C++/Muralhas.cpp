#include <bits/stdc++.h>
using namespace std;



int main() {
 int n,k;
 cin >> n >> k;

 vector<int> mu(n);
 vector<int> mu2(n);
 for(int i = 0; i < n; i++){
    cin >> mu[i];
 }

 int maior = 0;
 for(int i = n-1; i >= 0; i--){
    for(int p = 0; p < n; p++){
        mu2[p] = mu[p];
    }

    int temp = k;

    for(int j = i; j >= 0; j--){
        mu2[j] = mu[j] + temp;
        temp--;
        if(temp == 0) break;
    }

    int menor = *min_element(mu2.begin(), mu2.end());

    if(maior < menor) maior = menor;


 }
 cout << maior << endl;

}
