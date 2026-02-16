#include <bits/stdc++.h>


using namespace std;

int main() {

    int nc;
    cin >> nc;

    int casos = 0;

    for(int i = 0; i < nc; i++){
        int n, k;
        cin >> n >> k;
        casos++;

        vector<int> v;

        for(int j = 1; j <= n; j ++){
            v.push_back(j);
        }

        int aux = 0;
        int cont = 0;
        while(v.size() > 1){
            aux = (aux + k-1) % v.size();


            v.erase(v.begin() + aux);
            if(aux == v.size()) aux = 0;

        }

        cout << "Case " << casos << ": " << v[0] << endl;



    }

    


   
}
