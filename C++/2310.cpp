#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    int totalSa = 0, totalBlok = 0, totalAta = 0;
    int suSa = 0, suBlok = 0, suAta = 0;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int su,b, a;
        cin >> su >> b >> a;
        totalSa += su;
        totalBlok += b;
        totalAta += a;

        cin >> su >> b >> a;
        suSa += su;
        suBlok += b;
        suAta += a;
    }

    cout << fixed << setprecision(2);

    cout << "Pontos de Saque: " << double(suSa * 100.0)/ totalSa << " %." << endl;
    cout << "Pontos de Bloqueio: " << double(suBlok * 100.0)/ totalBlok << " %."<< endl;
    cout << "Pontos de Ataque: " << double(suAta * 100.0)/ totalAta<< " %."<< endl;



}