#include <iostream>
#include <string>

using namespace std;

int main() {
    string frase;
    while (getline(cin, frase)) {
        size_t pos = frase.find(',');
        cout << frase.substr(0, pos) << endl;
        cout << frase.substr(pos + 1) << endl;
    }

}
