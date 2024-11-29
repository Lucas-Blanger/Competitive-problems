#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Evento {
    int coordenada, tempo;
};

// Comparador para ordenar os eventos por tempo
bool compararPorTempo(const Evento& a, const Evento& b) {
    return a.tempo < b.tempo;
}

pair<int, int> calcularMaximoEventos(vector<Evento>& eventos, int velocidade) {
    // Ordenar os eventos pelo tempo
    sort(eventos.begin(), eventos.end(), compararPorTempo);
    int quantidadeEventos = eventos.size();

    // Vetores para armazenar o número máximo de eventos visitados
    vector<int> dpAPartirDeZero(quantidadeEventos, 0);
    vector<int> dpAPartirDeQualquerPonto(quantidadeEventos, 0);

    int maximoDeZero = 0;
    int maximoQualquerPonto = 0;

    for (int i = 0; i < quantidadeEventos; ++i) {
        int coordenadaAtual = eventos[i].coordenada;
        int tempoAtual = eventos[i].tempo;

        // Cenário: Começando de zero
        if (abs(coordenadaAtual) <= tempoAtual * velocidade) {
            dpAPartirDeZero[i] = 1;
        }

        // Cenário: Começando de qualquer ponto
        dpAPartirDeQualquerPonto[i] = 1;

        for (int j = 0; j < i; ++j) {
            int coordenadaAnterior = eventos[j].coordenada;
            int tempoAnterior = eventos[j].tempo;

            // Verificar se o evento atual é alcançável a partir do evento anterior
            if (tempoAtual >= tempoAnterior) {
                if (abs(coordenadaAtual - coordenadaAnterior) <= (tempoAtual - tempoAnterior) * velocidade) {
                    dpAPartirDeZero[i] = max(dpAPartirDeZero[i], dpAPartirDeZero[j] + 1);
                    dpAPartirDeQualquerPonto[i] = max(dpAPartirDeQualquerPonto[i], dpAPartirDeQualquerPonto[j] + 1);
                }
            }
        }

        // Atualizar os máximos encontrados
        maximoDeZero = max(maximoDeZero, dpAPartirDeZero[i]);
        maximoQualquerPonto = max(maximoQualquerPonto, dpAPartirDeQualquerPonto[i]);
    }

    return {maximoDeZero, maximoQualquerPonto};
}

int main() {
    int quantidadeEventos;
    cin >> quantidadeEventos;

    vector<Evento> eventos(quantidadeEventos);
    for (int i = 0; i < quantidadeEventos; ++i) {
        cin >> eventos[i].coordenada >> eventos[i].tempo;
    }

    int velocidadeMaxima;
    cin >> velocidadeMaxima;

    auto resultado = calcularMaximoEventos(eventos, velocidadeMaxima);
    cout << resultado.first << " " << resultado.second << endl;

    return 0;
}
