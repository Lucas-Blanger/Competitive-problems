#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;
    while(cin >> n){
        multiset<int> ms;

        for(int i = 0; i < n;i++){
            int x,y;
            cin >> x  >> y;
            for(int j = x; j <= y; j++){
                ms.insert(j);
            }
        }

        int num;
        cin >> num;
        auto it1 = ms.lower_bound(num);
        auto it2 = ms.upper_bound(num);

        if(ms.count(num) == 0) cout << num << " not found" << endl;
        else{
            cout << num << " found from " << distance(ms.begin(), it1) << " to " << (distance(ms.begin(), it2)-1) << endl;
        }
    }
}