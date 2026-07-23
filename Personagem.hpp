#ifndef Personagem_HPP
#define Personagem_HPP
#include "Habilidade.hpp"
#include <string>
#include <vector>

using namespace std;

class Personagem {

    //Atributos

    private:
        string nome;
        double vida, vidaMax, esquiva, defesa;
        int mana, manaMax;
        bool estaDefendendo; //Teste lógico para saber se ele está defendendo no turno
        vector<Habilidade> habilidades; //Opções de move

    //Métodos

    public:

        Personagem(const string& nome, double vida, double esquiva, double defesa, int mana); //Construtor
        
    //Consultores
        
        bool estaVivo() const; //Consultor que serve de base para determinar a situação do loop
        bool manaSuficiente(int custo) const;
        bool consultarDefesa() const;

        //Getters

        string getNome() const;
        double getVida() const;
        double getVidaMax() const;
        double getDefesa() const;
        double getEsquiva() const;
        double getMana() const;
        double getManaMax() const;
        
        const vector<Habilidade>& getHabilidades() const;

    //Mutators

        void defender();
        void resetarDefesa();   //Limpa o estado de estaDefendendo 
        bool usoMana(int custo);
        void receberDano(double dano); //Tramite burócratico que verifica e desconta a vida do alvo
        void atacar(Personagem& alvo, const Habilidade& habilidade); //Calculo do dano em relação ao alvo
        void adicionarHabilidade(const Habilidade& habilidade);
        

};

#endif