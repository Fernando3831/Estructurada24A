#include <iostream>

using namespace std;

class Pokemon{
    public:
    string nombre;
    float peso;

    public:
    Pokemon(string, float);
    void Saludo();
};

Pokemon::Pokemon(string _nombre, float _peso){

    nombre = _nombre;
    peso = _peso;
}
void Pokemon::Saludo(){
    cout<<"El pokemon que te saluda es: "<<nombre<<" y el pesa: "<<peso<<" Kilogramos."<<endl;
}

class Pokemons_Fuego : public Pokemon{
    public:
    int vida;
    char genero;
    public:
    Pokemons_Fuego(string, float, int, char);
    void Saludo();
};

Pokemons_Fuego::Pokemons_Fuego(string _nombre, float _peso, int _vida, char _genero) : Pokemon(_nombre, _peso){

    vida = _vida;
    genero = _genero;
}
void Pokemons_Fuego::Saludo(){
    Pokemon::Saludo();
    cout<<"El pokemon tiene: "<<vida<<" puntos de vida y su genero es: "<<genero<<endl;

}

int main(){
    Pokemons_Fuego pokemon1("Charmander", 0.95, 30, 'F');
    pokemon1.Saludo();
    Pokemons_Fuego pokemon2("Pikachu", 4.56, 76, 'M');
    pokemon2.Saludo();

    return 0;
}
