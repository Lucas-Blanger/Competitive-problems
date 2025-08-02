#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        int total = 0;

        for (int i = 0; i < k; ++i) {
            int tomadas;
            cin >> tomadas;
            total += tomadas - 1; 
        }

        total += 1; 
        cout << total << endl;
    }


}
