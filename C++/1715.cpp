#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m,n;
    cin >> n >> m;
    vector<vector<int>> jog(n, vector<int>(m,0)); 

    int cont = 0;
    for(int i = 0; i < n;i++){
        bool pass = true;
        for(int j = 0; j < m; j++){
            cin >> jog[i][j];
            if(jog[i][j] == 0) pass = false;
        }
        if(pass) cont++;
    }

    cout << cont << endl;

}