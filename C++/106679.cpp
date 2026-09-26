#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   int n,m;
   cin >> n >> m;

    vector<string> mat(n);
    vector<string> cop(n);


   for(int i = 0; i < n; i++){
        string y;
        cin >> y;
        mat[i] = y;
        cop[i] = y;
    }

    int r = 1;
    
    bool aux = true;
    bool maisc = false;
    if(m > n || n > m) maisc = true;
    //cout << maisc << endl;

    // caso 2 90 direita
    if(maisc == false){
        for(int i = n-1; i >= 0; i--){
            for(int j = 0, k = 0; j < m; j++,k++){
                if(j >= n || i >= m){
                    aux = false;
                    break;
                }else{
                    mat[j][i] = cop[i][j];
                    if(mat[j][i] != cop[j][i]){
                    aux = false;
                        break;
                    }
                }
                
            }
        }
    }else{
        aux = false;
    }
    
    
    if(aux) {
        r++;
        
    }
    
    mat = cop;
    aux = true;
    
    // caso 3 90 esquerda
    if(maisc == false){
        for(int j = m - 1, l = 0; j >=0; j--,l++){
            for(int i = 0, k = 0; i < n; i++,k++){
                if(l >= n || k >= m){
                    aux = false;
                    break;
                }else{
                    mat[l][k] = cop[i][j];
                    if(mat[l][k] != cop[l][k]){
                        aux = false;
                        break;
                    }

                }
                
            }
        }
    }else{
        aux = false;
    }
    

    if(aux) {
        r++;
        //cout << "caso 3" << endl;
    }
    aux = true;
    
    mat = cop;
    // caso 4 ponta cabeça
    for(int i = n -1, l = 0; i >=0; i--,l++){
        for(int j = m- 1, k = 0; j >=0; j--,k++){
            mat[l][k] = cop[i][j];
            if(mat[l][k] != cop[l][k]){
                aux = false;
                break;
            }
        }
    }

    mat = cop;
    if(aux) {
        r++;
        //cout << "caso 4" << endl;
    }
    aux = true;
    
    
    // contrario
     for(int i = 0, l = 0; i < n; i++,l++){
        for(int j = m- 1, k = 0; j >=0; j--,k++){
            mat[l][k] = cop[i][j];
            if(mat[l][k] != cop[l][k]){
                aux = false;
                break;
            }
        }
    }
    
    mat = cop;
    if(aux) {
        r++;
        //cout << "caso 5" << endl;
    }
    aux = true;
    
    // caso 2 90 direita
    if(maisc == false){
        for(int i = m-1, l = 0; i >=0 ; i--, l++){
            for(int j = n-1, k = 0; j >=0; j--,k++){
                if(i >= n || j >= m || l >= n || k >= m){
                    aux = false;
                    break;
                }else{
                    mat[l][k] = cop[j][i];
                    if(mat[l][k] != cop[l][k]){
                        aux = false;
                        break;
                    }
                }
            }
        }
    }else{
        aux = false;
    }
    mat = cop;
     if(aux) {
        r++;
        //cout << "caso 6" << endl;
    }
    aux = true;
    
    // caso 3 90 esquerda
    if(maisc == false){
        for(int j = m - 1, l = 0; j >=0; j--,l++){
            for(int i = 0, k = 0; i < n; i++,k++){
                if(i >= n || j >= m || l >= n || k >= m){
                    aux = false;
                    break;
                }else{
                    mat[l][k] = cop[i][j];
                    if(mat[l][k] != cop[l][k]){
                        aux = false;
                        break;
                    }
                }
            }
        }
    }else{
        aux = false;
    }

    mat = cop;
    if(aux) {
        r++;
        //cout << "caso 7" << endl;
    }
    aux = true;
    
    // caso 4 ponta cabeça
    for(int i = n-1, l = 0; i >=0; i--,l++){
        for(int j = 0, k = 0; j < m; j++,k++){
            mat[l][k] = cop[i][j];
            if(mat[l][k] != cop[l][k]){
                aux = false;
                break;
            }
        }
    }
    
     if(aux) {
        r++;
        //cout << "caso 8" << endl;
    }
    aux = true;
    
    cout << r << endl;
    
   
   

}