   #include <iostream>


using namespace std;

int main(){
    long long n, m, a;
    cin >> n >> m >> a;

    long long h = (n + a - 1) / a;
    long long v = (m + a - 1) / a;

    cout << h * v << endl;

}
   