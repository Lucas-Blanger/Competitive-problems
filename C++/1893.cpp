#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if (a > b || a == b){

		if (b >= 97)
			cout << "cheia" << endl;
		else if (b <= 96 && b >= 3)
			cout << "minguante" << endl;
		else
			cout << "nova" << endl;

	}
	else{

		if (b <= 2)
			cout << "nova" << endl;
		else if (b <= 96)
			cout << "crescente" << endl;
		else if (b <= 100)
			cout << "cheia" << endl;
	}
}