#ifndef Batalha_HPP
#define Batalha_HPP
#include "Personagem.hpp"
#include <string>

using namespace std;

class Batalha {

    public:

        Batalha(Personagem& personagemHeroi, Personagem& personagemVilao);
        void iniciar();
        bool terminou() const;

    private: 
        Personagem& personagemHeroi;
        Personagem& personagemVilao;
        int menu();
        

};

#endif