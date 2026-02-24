#include <bits/stdc++.h>

using namespace std;

double calcularArea(vector<int>& tiras, double h) {
    double area = 0;
    for(int comprimento : tiras) {
        if(comprimento > h) {
            area += (comprimento - h);
        }
    }
    
    return area;
}

int main() {
    int n, a;
    
    while(cin >> n >> a && (n || a)) {
        
        vector<int> tiras(n);
        int maxAltura = 0;
        double areaTotal = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> tiras[i];
            maxAltura = max(maxAltura, tiras[i]);
            areaTotal += tiras[i];
        }
        
        if(areaTotal < a) {
            cout << "-.-\n";
            continue;
        }
        
        if(areaTotal == a) {
            cout << ":D\n";
            continue;
        }
        
        double left = 0;
        double right = maxAltura;
        double h = 0;
        
        for(int iter = 0; iter < 100; iter++) {
            double mid = (left + right) / 2.0;
            double areaAtual = calcularArea(tiras, mid);
            
          
            if(areaAtual >= a) {
                h = mid;
                left = mid;
            }else {
                right = mid;
            }
        }
        
        cout << fixed << setprecision(4) << h << "\n";
    }
    
}
