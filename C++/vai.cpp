#include <iostream>
using namespace std;

string vai_que_eh_tua(int Xb, int Yb, int Zb, int Xd, int Yd, int Zd, int Xp, int Yp, int Zp) {
    double t = -static_cast<double>(Zb) / Zd;
    if (t < 0) {
        return "Nem tenta!\n";
    }

    double Xi = Xb + t * Xd;
    double Yi = Yb + t * Yd;
    double Zi = Zb + t * Zd;

    double Xd_new = Xd;
    double Yd_new = Yd;
    double Zd_new = -Zd;

    if (Zd_new == 0) {
        return "Nem tenta!\n";
    }

    double t_new = (Zp - Zi) / Zd_new;

    double Xp_new = Xi + t_new * Xd_new;
    double Yp_new = Yi + t_new * Yd_new;

    if (Xp_new == Xp && Yp_new == Yp) {
        return "Vai que eh tua!\n";
    } else {
        return "Nem tenta!\n";
    }
}

int main() {
    int Xb, Yb, Zb;
    int Xd, Yd, Zd;
    int Xp, Yp, Zp;

    cin >> Xb >> Yb >> Zb;
    cin >> Xd >> Yd >> Zd;
    cin >> Xp >> Yp >> Zp;

    string resultado = vai_que_eh_tua(Xb, Yb, Zb, Xd, Yd, Zd, Xp, Yp, Zp);
    cout << resultado;

    return 0;
}
