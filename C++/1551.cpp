#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
   int n;
   cin >> n;
   cin.ignore();

   for(int i = 0; i < n; i++){
      string texto;
      getline(cin, texto);
      
      string letras = "";
        for(int j = 0; j < texto.size(); j++){
            if(isalpha(texto[j])) letras += tolower(texto[j]);
        }

        int cont = 0;
        vector<bool> aux(26,false);
        for(int j = 0; j < letras.size(); j++){
            if(letras[j] == 'a' && aux[0] == false){
                cont++; 
                aux[0] = true;
            } else if(letras[j] == 'b' && aux[1] == false){
                cont++; 
                aux[1] = true;
            } else if(letras[j] == 'c' && aux[2] == false){
                cont++; 
                aux[2] = true;
            } else if(letras[j] == 'd' && aux[3] == false){
                cont++;  
                aux[3] = true;
            } else if(letras[j] == 'e' && aux[4] == false){
                cont++;  
                aux[4] = true;   
            } else if(letras[j] == 'f' && aux[5] == false){
                cont++;  
                aux[5] = true;   
            } else if(letras[j] == 'g' && aux[6] == false){
                cont++;  
                aux[6] = true;   
            } else if(letras[j] == 'h' && aux[7] == false){
                cont++;  
                aux[7] = true;   
            } else if(letras[j] == 'i' && aux[8] == false){
                cont++;  
                aux[8] = true;   
            } else if(letras[j] == 'j' && aux[9] == false){
                cont++;  
                aux[9] = true;   
            } else if(letras[j] == 'k' && aux[10] == false){
                cont++;  
                aux[10] = true;   
            } else if(letras[j] == 'l' && aux[11] == false){
                cont++;  
                aux[11] = true;   
            }  else if(letras[j] == 'm' && aux[12] == false){
                cont++;  
                aux[12] = true;   
            }  else if(letras[j] == 'n' && aux[13] == false){
                cont++;  
                aux[13] = true;   
            }  else if(letras[j] == 'o' && aux[14] == false){
                cont++;  
                aux[14] = true;   
            }  else if(letras[j] == 'p' && aux[15] == false){
                cont++;  
                aux[15] = true;   
            }  else if(letras[j] == 'q' && aux[16] == false){
                cont++;  
                aux[16] = true;   
            }  else if(letras[j] == 'r' && aux[17] == false){
                cont++;  
                aux[17] = true;   
            }  else if(letras[j] == 's' && aux[18] == false){
                cont++;  
                aux[18] = true;   
            }  else if(letras[j] == 't' && aux[19] == false){
                cont++;  
                aux[19] = true;   
            }  else if(letras[j] == 'u' && aux[20] == false){
                cont++;  
                aux[20] = true;   
            }  else if(letras[j] == 'v' && aux[21] == false){
                cont++;  
                aux[21] = true;   
            } else if(letras[j] == 'w' && aux[22] == false){
                cont++;  
                aux[22] = true;  
            }else if(letras[j] == 'x' && aux[23] == false){
                cont++;  
                aux[23] = true;   
            }else if(letras[j] == 'y' && aux[24] == false){
                cont++;  
                aux[24] = true;   
            }else if(letras[j] == 'z' && aux[25] == false){
                cont++;  
                aux[25] = true;   
            }
        }

        if(cont == 26) cout << "frase completa" << endl;
        else if(cont >= 13) cout << "frase quase completa" << endl;
        else cout << "frase mal elaborada" << endl;
   



   }
}