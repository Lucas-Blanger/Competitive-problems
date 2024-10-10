#include <iostream>
#include <vector>
#include <map>

int main() {
    int C, N;
    while (std::cin >> C >> N) {
        std::vector<int> estacionamento(C, 0);
        std::map<int, int> veiculos;
        int faturamentoTotal = 0;

        for (int i = 0; i < N; ++i) {
            char tipoEvento;
            std::cin >> tipoEvento;

            if (tipoEvento == 'C') {
                int placa, comprimento;
                std::cin >> placa >> comprimento;

                bool estacionado = false;
                for (int j = 0; j <= C - comprimento; ++j) {
                    bool espacoDisponivel = true;
                    for (int k = j; k < j + comprimento; ++k) {
                        if (estacionamento[k] != 0) {
                            espacoDisponivel = false;
                            break;
                        }
                    }

                    if (espacoDisponivel) {
                        for (int k = j; k < j + comprimento; ++k) {
                            estacionamento[k] = placa;
                        }
                        veiculos[placa] = comprimento;
                        faturamentoTotal += 10;
                        estacionado = true;
                        break;
                    }
                }

            } else if (tipoEvento == 'S') {
                int placa;
                std::cin >> placa;

                int comprimento = veiculos[placa];
                for (int j = 0; j < C; ++j) {
                    if (estacionamento[j] == placa) {
                        estacionamento[j] = 0;
                    }
                }
            }
        }

        std::cout << faturamentoTotal << std::endl;
    }

    return 0;
}
