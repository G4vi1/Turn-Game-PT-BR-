#ifndef Habilidade_HPP
#define Habilidade_HPP
#include <string>

using namespace std;

enum class TipoHabilidade {
    Fisica,
    Magica,
    Especial, 
    Move
};

class Habilidade{

    private:
        string nome;
        TipoHabilidade tipo;
        int custoMana;
        double valorAtaque;

    public:
        Habilidade(const string& nome, TipoHabilidade tipo, int custoMana, double valorAtaque);
        string getNome() const;
        TipoHabilidade getTipo() const;
        int getCustoMana() const;
        double getValorAtaque() const;

};

#endif
