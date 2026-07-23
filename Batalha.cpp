#include "Batalha.hpp"
#include <iostream>
#include <vector>

using namespace std;

Batalha::Batalha(Personagem& personagemHeroi, Personagem& personagemVilao)
    :personagemHeroi(personagemHeroi), personagemVilao(personagemVilao) {

}

void Batalha::iniciar() {

    while(personagemHeroi.estaVivo() && personagemVilao.estaVivo()) {

        if(turno(personagemHeroi, personagemVilao)){
            break;
        }

        if(turno(personagemVilao, personagemHeroi)){
            break;
        }
    }

    cout << "Batalha encerrada!" << endl;

}

int Batalha::menu() {
    int escolha;

    do {
        cout << "\n[ 1 ] Atacar" << endl;
        cout << "[ 2 ] Defender" << endl;
        cin >> escolha;
    } while (escolha != 1 && escolha != 2);

    return escolha;

}

bool Batalha::turno(Personagem& atacante, Personagem& defensor) {
    int escolha = menu();

    if(escolha == 1){
        const vector<Habilidade>& habilidades = atacante.getHabilidades();
        int indice;

        do {
            cout << "\nEscolha uma habilidade:" << endl;
            for (int i = 0; i < (int)habilidades.size(); i++) {
                cout << i << " - " << habilidades[i].getNome() << endl;
            }
            cin >> indice;
        } while (indice < 0 || indice >= (int)habilidades.size()
                 || !atacante.manaSuficiente(habilidades[indice].getCustoMana()));
        
        atacante.atacar(defensor, habilidades[indice]);
        defensor.resetarDefesa();

    } else {
        atacante.defender();
    }

    return !defensor.estaVivo();
}

