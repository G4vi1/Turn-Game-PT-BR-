#ifndef Batalha_HPP
#define Batalha_HPP
#include "Personagem.hpp"

using namespace std;

class Batalha {

    public:

        Batalha(Personagem& personagemHeroi, Personagem& personagemVilao);
        void iniciar();

    private: 
        Personagem& personagemHeroi;
        Personagem& personagemVilao;
        string desenharBarra(double atual, double maximo, char simbolo);
        void mostrarStatus();
        bool turno(Personagem& atacante, Personagem& defensor);
        int menu();
        
        

};

#endif