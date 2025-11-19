#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    map<int, int> numbers;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers[num]++;
    }

    for(auto x: numbers){
        cout << x.first << " aparece " << x.second << " vez(es)" << endl;
    
    }
}