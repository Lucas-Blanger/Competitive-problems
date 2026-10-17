#include <bits/stdc++.h>


using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long h, x,y;

    cin >> h >> x >> y;

    long long dist = abs(h-12);

    long long d = min(dist, 12 - dist);

    bool ex = (x >= d) && ((x-d) % 2 ==0);
    bool ey = (y >= d) && ((y-d) % 2 ==0);

    if(ey && ex) cout << "SIM\n";
    else cout << "NAO\n";

}