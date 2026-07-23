#include "Habilidade.hpp"

using namespace std;

//Construtor

Habilidade::Habilidade(const string& nome, TipoHabilidade tipo, int custoMana, double valorAtaque)
    : nome(nome), tipo(tipo), custoMana(custoMana), valorAtaque(valorAtaque) {
}

//Getters

string Habilidade::getNome() const {
    return nome;
}


TipoHabilidade Habilidade::getTipo() const {
    return tipo;
}

int Habilidade::getCustoMana() const {
    return custoMana;
}

double Habilidade::getValorAtaque() const {
    return valorAtaque;
}