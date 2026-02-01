#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    while(cin >> a >> b >> c){
        

        double p = (a + b + c) / 2.0;

        double area = sqrt(p * (p - a) * (p - b) * (p - c));

        double r = area / p;
        double areaIns = M_PI * r * r;

        double rCirc = (a * b * c) / (4.0 * area);
        double circu = M_PI * rCirc * rCirc;

        double amarelas = circu - area;
        double azuis = area - areaIns;
        double vermelhas = areaIns;

        cout << fixed << setprecision(4);
        cout << amarelas << " " << azuis << " " << vermelhas << endl;

    }
    

}
