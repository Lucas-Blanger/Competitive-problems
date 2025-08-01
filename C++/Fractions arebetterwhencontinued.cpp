    #include <iostream>
    using namespace std;
     
    int main() {
        int n;
        cin >> n;
     
        long long num = 1; 
        long long den = 1; 
     
        for (int i = 1; i < n; ++i) {
            long long temp = num;
            num = den;
            den = temp + den;
        }
     
        cout << den << endl; 
     
    }