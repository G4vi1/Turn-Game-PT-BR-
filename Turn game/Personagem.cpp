#include "Personagem.hpp"
#include <iostream>

using namespace std;

//Construtor

Personagem::Personagem(const string& nome, double vida, double esquiva, double defesa, int mana)
    : nome(nome), vida(vida), esquiva(esquiva), defesa(defesa), mana(mana), estaDefendendo(false) {
}

//Métodos de Consulta



bool Personagem::estaVivo() const{      //Consulta se o personagem está vivo
    if(vida <= 0){
        return false;
    } else {
        return true;
    }
}

bool Personagem::manaSuficiente(int custo) const{       //Consulta se o personagem tem mana suficiente pra realizar determinado ataque
    return custo <= mana;
}


bool Personagem::consultarDefesa() const {
    return estaDefendendo;
}

    //Getters

double Personagem::getDefesa() const {
    return defesa;
}

double Personagem::getEsquiva() const {
    return esquiva;
}

const vector<Habilidade>& Personagem::getHabilidades() const {
    return habilidades;
}

//Métodos Mutators:

    //Desconta a mana do personagem

bool Personagem::usoMana(int custo) { //Caso a consulta de manaSuficiente() retorne como verdadeira, então desconta o mana disponível do jogador.
    if (manaSuficiente(custo)){
        mana-= custo;
        return true;
    } else {
        return false;
    }
}

void Personagem::receberDano(double dano){
    if (dano < 0){
        cout << "Erro";
        return;
    } else {
        vida -= dano;
        if (vida < 0){
            vida = 0;
        }
    }
}

void Personagem::defender(){
    estaDefendendo = true;
}

void Personagem::resetarDefesa(){
    estaDefendendo = false;
}

//Adiciona habilidades ao personagem:

void Personagem::adicionarHabilidade(const Habilidade& habilidade){
    habilidades.push_back(habilidade);
}
