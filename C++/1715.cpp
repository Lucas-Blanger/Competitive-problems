#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, y= 0;
    bool certo;
    cin >> n >> m;
    vector< vector<int> >v(n, vector<int>(m));
    for (int i=0; i<n; ++i)
    {
        certo = true;
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
        for (int j = 0; j < m; j++){
            if (v[i][j]==0){
                certo = false;
            }
    
        }
        if (certo)
            y++;
    }
    cout << y << endl;

}