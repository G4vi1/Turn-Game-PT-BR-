#include "Personagem.hpp"
#include "Habilidade.hpp"
#include "Batalha.hpp"

using namespace std;

int main(){

    // Habilidades do herói

    Habilidade golpeSagrado("Golpe Sagrado", TipoHabilidade::Fisica, 10, 25.0);
    Habilidade lancaDivina("Lanca Divina", TipoHabilidade::Fisica, 15, 35.0);
    Habilidade bencaoCurativa("Bencao Curativa", TipoHabilidade::Especial, 20, 15.0);

    // Habilidades do vilão

    Habilidade garraSombria("Garra Sombria", TipoHabilidade::Fisica, 8, 20.0);
    Habilidade explosaoArcana("Explosao Arcana", TipoHabilidade::Magica, 25, 45.0);
    Habilidade grito("Grito Devastador", TipoHabilidade::Especial, 30, 50.0);

    //Personagens

    Personagem personagemA("Arcanjo", 100.0, 0.8, 12, 60);
    Personagem personagemB("Leviathan", 100.0, 0.4, 15, 70);

    //Adicionar habilidades (Player)

    personagemA.adicionarHabilidade(golpeSagrado);
    personagemA.adicionarHabilidade(lancaDivina);
    personagemA.adicionarHabilidade(bencaoCurativa);

    personagemB.adicionarHabilidade(garraSombria);
    personagemB.adicionarHabilidade(explosaoArcana);
    personagemB.adicionarHabilidade(grito);

    
    //Criar batalha

    Batalha batalha(personagemA, personagemB);

    //Rodar

    batalha.iniciar();

    return 0;


}