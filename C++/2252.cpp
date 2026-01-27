#include <bits/stdc++.h>


using namespace std;

int main(){
    int n, caso = 0;
    while(cin >> n){
        caso++;
        vector<pair<int, double>> v;
        for(int i = 0; i < 10; i++){
            double k;
            cin >> k;
            v.push_back(make_pair(i, k));
        }

        sort(v.begin(), v.end(), [](const pair<int,double> &a, const pair<int,double> &b){
            if(a.second == b.second){
                return a.first < b.first;
       
            }
            return a.second > b.second;
        });

        cout << "Caso " << caso << ": ";
        for(int i = 0; i < n; i++){
            cout << v[i].first;
        }
        cout << endl;



    }
   

}