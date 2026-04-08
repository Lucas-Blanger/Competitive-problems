#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cn1, cd1,cv1;
    int cn2, cd2,cv2;
    cin >> cn1 >> cd1 >> cv1;
    cin >> cn2 >> cd2 >> cv2;

    double t1 = double(cd1) / cv1;
    double t2 = double(cd2) / cv2;

    if(t1 < t2) cout << cn1 << endl;
    else cout << cn2 << endl;
}