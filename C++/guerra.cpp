#include <iostream>
#include <cmath>
using namespace std;

bool check_reflection(int z_start, int z_dir, int z_target, int t) {
    int z_at_t = z_start + t * z_dir;
    if (z_dir == 0) return z_start == z_target;
    // O número de vezes que cruza o plano z = 0
    int reflections = abs(z_at_t / (2 * abs(z_dir)));
    // Verificar se a bolinha passa pelo ponto alvo após as reflexões
    if (reflections % 2 == 0) {
        return (z_at_t - z_target) % (2 * abs(z_dir)) == 0;
    } else {
        return (z_at_t + z_target) % (2 * abs(z_dir)) == 0;
    }
}

int main() {
    int Xb, Yb, Zb;
    int Xd, Yd, Zd;
    int Xp, Yp, Zp;

    cin >> Xb >> Yb >> Zb;
    cin >> Xd >> Yd >> Zd;
    cin >> Xp >> Yp >> Zp;

    // Verificar divisões por zero e se a direção é válida
    if (Xd == 0 && (Xp - Xb) != 0) {
        cout << "Nem tenta!" << endl;
        return 0;
    }
    if (Yd == 0 && (Yp - Yb) != 0) {
        cout << "Nem tenta!" << endl;
        return 0;
    }

    int t_x = Xd != 0 ? (Xp - Xb) / Xd : 0;
    int t_y = Yd != 0 ? (Yp - Yb) / Yd : 0;

    // Verificar se os tempos são inteiros e iguais
    if ((Xd != 0 && (Xp - Xb) % Xd != 0) || (Yd != 0 && (Yp - Yb) % Yd != 0) || t_x != t_y) {
        cout << "Nem tenta!" << endl;
        return 0;
    }

    int t = t_x; // Pode ser t_y também, pois t_x == t_y

    // Verificar a coordenada Z considerando as reflexões
    if (check_reflection(Zb, Zd, Zp, t)) {
        cout << "Vai que eh tua!" << endl;
    } else {
        cout << "Nem tenta!" << endl;
    }

    return 0;
}
