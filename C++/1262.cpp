#include <iostream>
#include <string>

using namespace std;

int main() {
    string hist;

    int p;

    while (cin >> hist >> p) {
        int ciclos = 0;

        int i = 0;
        
        while (i < hist.size()) {
            if (hist[i] == 'W') {
                ciclos++;
                i++; 
            } else {
                int cont = 0;
                while (i < hist.size() && hist[i] == 'R') {
                    cont++;
                    i++;
                }
                ciclos += (cont + p - 1) / p; 
            }
        }
        cout << ciclos << endl;
    }

}
