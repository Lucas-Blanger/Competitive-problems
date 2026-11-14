
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(true){
        cin >> n;
        if(n == 0) break;

        vector<int> aux;

        int r = 0;
        int l = 0;
      
        for(int i = 0;i < n;i++){
            int v, q;
            cin >> v >> q;
            if(q >= 2){
                l += (q / 2) * 2;
            }
            
        }


        cout << l / 4 << endl;
    }

}
