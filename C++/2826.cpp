#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    string string1, string2;

    vector<string>v;

    cin >> string1 >> string2;

    v.push_back(string1);

    v.push_back(string2);

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

}