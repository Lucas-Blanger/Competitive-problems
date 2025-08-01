    #include <iostream>
     
    using namespace std;
     
    int main(){
        int n;
        cin >> n;
     
        int k[n][n];
     
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> k[i][j];
            }
        }
     
     
        if( k[0][0] < k[0][n-1] && k[0][0] < k[n-1][n-1] && k[0][0] < k[n-1][0]){
            cout << 0 << endl;
        } else if(k[0][n-1] < k[0][0] && k[0][n-1] < k[n-1][n-1] && k[0][n-1] < k[n-1][0]){
            cout << 1 << endl;
        } else if(k[n-1][n-1] < k[0][0] && k[n-1][n-1] < k[0][n-1] && k[n-1][n-1] < k[n-1][0]){
            cout << 2 << endl;
        } else if(k[n-1][0] < k[0][0] && k[n-1][0] < k[0][n-1] && k[n-1][0] < k[n-1][n-1]){
            cout << 3 << endl;
        }
     
     
        
     
     
     
    }