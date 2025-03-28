#include <iostream>

using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;

    if(s1 == "vertebrado"){
        if(s2 == "ave"){
            if(s3 == "carnivoro"){
                cout << "aguia" << endl;
            } else { //onivoro
                cout << "pomba" << endl;
            }
        } else { //mamifero
            if(s3 == "onivoro"){
                cout << "homem" << endl;
            } else { //herbivoro
                cout << "vaca" << endl;
            }
        }
    } else{ //invertebrado
        if(s2 == "inseto"){
            if(s3 == "hematofago"){
                cout << "pulga" << endl;
            } else { //herbivoro
                cout << "lagarta" << endl;
            }
        } else { //anelideo
            if(s3 == "hematofago"){
                cout << "sanguessuga" << endl;
            } else { //onivoro
                cout << "minhoca" << endl;
            }
        }

    }

}


