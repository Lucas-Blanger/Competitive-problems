#include <iostream>

using namespace std;

int main() {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num <= 1) {
            cout << num << " nao eh primo" << endl;
        } else {
            int divisores = 0; 
            for (int j = 2; j < num; j++) {
                if (num % j == 0) {
                    divisores++;  
                    break;  
                }
            }

            if (divisores == 0) {
                cout << num << " eh primo" << endl; 
            } else {
                cout << num << " nao eh primo" << endl;  
            }
        }
    }
}
