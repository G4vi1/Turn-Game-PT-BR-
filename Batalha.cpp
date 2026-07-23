#include "Batalha.hpp"
#include <iostream>
#include <vector>

using namespace std;

Batalha::Batalha(Personagem& personagemHeroi, Personagem& personagemVilao)
    :personagemHeroi(personagemHeroi), personagemVilao(personagemVilao) {

}

string Batalha::desenharBarra(double atual, double maximo, char simbolo) {
    
    const int tamanhoBarra = 20;
    int barrasPreenchidas = (atual / maximo) * tamanhoBarra;
    string barra = "[";

    for (int i = 0; i < barrasPreenchidas; i++) {
        barra += simbolo;
    }

    for (int i = barrasPreenchidas; i < tamanhoBarra; i++) {
        barra += " ";
    }

    barra += "]";

    return barra;

}

void Batalha::mostrarStatus() {

    //Getters para pegar os nomes, vidas/vidaMax e manas/manaMax dos personagens
    
    string nomeHeroi = personagemHeroi.getNome();
    string nomeVilao = personagemVilao.getNome();

    double vidaHeroi = personagemHeroi.getVida();
    double vidaMaxHeroi = personagemHeroi.getVidaMax();

    double vidaVilao = personagemVilao.getVida();
    double vidaMaxVilao = personagemVilao.getVidaMax();

    double manaHeroi = personagemHeroi.getMana();
    double manaMaxHeroi = personagemHeroi.getManaMax();

    double manaVilao = personagemVilao.getMana();
    double manaMaxVilao = personagemVilao.getManaMax();

    //Impressão do status dos personagens

    cout << "\n========== STATUS DA BATALHA ==========\n\n"

     << nomeHeroi << "\n"
     << "HP "
     << desenharBarra(vidaHeroi, vidaMaxHeroi, '=')
     << " " << vidaHeroi << "\n"
     << "MP "
     << desenharBarra(manaHeroi, manaMaxHeroi, '*')
     << " " << manaHeroi << "\n\n"

     << nomeVilao << "\n"
     << "HP "
     << desenharBarra(vidaVilao, vidaMaxVilao, '=')
     << " " << vidaVilao << "\n"
     << "MP "
     << desenharBarra(manaVilao, manaMaxVilao, '*')
     << " " << manaVilao << "\n\n"

     << "=======================================\n\n";

}

void Batalha::iniciar() {

    cout << "=====================================\n"
     << "         A LUTA COMECA!\n"
     << "=====================================\n\n";

    while(personagemHeroi.estaVivo() && personagemVilao.estaVivo()) {

        if(turno(personagemHeroi, personagemVilao)){
            break;
        }

        if(turno(personagemVilao, personagemHeroi)){
            break;
        }
    }

    mostrarStatus();

    if (!personagemHeroi.estaVivo()) {

        cout << "\n"
             << personagemHeroi.getNome() << " foi derrotado!\n\n"
             << personagemVilao.getNome() << " VENCEU!!!!!!!!\n";

    } else {

        cout << "\n"
             << personagemVilao.getNome() << " foi derrotado!\n\n"
             << personagemHeroi.getNome() << " VENCEU!!!!!!!!\n";
    }

    cout << "\nBatalha encerrada!\n";

}

int Batalha::menu() {
    int escolha;

    do {
        cout << "\n-------------------------------------\n"
     << "[ 1 ] Atacar\n"
     << "[ 2 ] Defender\n"
     << "-------------------------------------\n";
        cin >> escolha;
    } while (escolha != 1 && escolha != 2);

    return escolha;

}

bool Batalha::turno(Personagem& atacante, Personagem& defensor) {

    cout << "\n=====================================\n"
     << "Turno de " << atacante.getNome() << "!\n"
     << "=====================================\n\n";
    
    mostrarStatus();

    int escolha = menu();

    if(escolha == 1){
        const vector<Habilidade>& habilidades = atacante.getHabilidades();
        int indice;

        do {
            cout << "\nEscolha uma habilidade:\n";
            for (int i = 0; i < (int)habilidades.size(); i++) {
                cout << i << " - " << habilidades[i].getNome() << "\n";
            }
            cin >> indice;

            if (indice < 0 || indice >= (int)habilidades.size()) {
                cout << "\nHabilidade invalida!\n\n";
            }
            else if (!atacante.manaSuficiente(habilidades[indice].getCustoMana())) {
                cout << "\nMana insuficiente!\n"
                << "Mana atual: " << atacante.getMana()
                << " | Custo: " << habilidades[indice].getCustoMana()
                << "\n";
            }
        } while (indice < 0 || indice >= (int)habilidades.size()
                 || !atacante.manaSuficiente(habilidades[indice].getCustoMana()));
        atacante.atacar(defensor, habilidades[indice]);

        cout << "\n"
     << atacante.getNome() << " usou "
     << habilidades[indice].getNome() << "!\n\n"
     << defensor.getNome() << " agora possui "
     << defensor.getVida() << " HP.\n";

        defensor.resetarDefesa();

    } else {
        atacante.defender();

        cout << "\n"
         << atacante.getNome()
         << " entrou em posicao defensiva!\n";
    }

    return !defensor.estaVivo();
}

