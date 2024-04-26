#include <iostream>
using namespace std;
//Las clases
class Pokemon{
//Estos son los atributos
public:
    string nombre;
    float peso;
    //Los metodos
public:
    Pokemon(string,  float);//Orden de acomodo de datos por este orden en este constructor
    void Saludo();
    };
    Pokemon::Pokemon (string _nombre, float _peso){
    nombre = _nombre;
    peso = _peso;
    }
    void Pokemon::Saludo(){
    cout<<"El pokemon que te saluda es:" <<nombre<< "y el pesa " <<peso<< " kilogramos.\n";
    }
int main(){
Pokemon pokemon1 = Pokemon("Chicorita", 0.75);
pokemon1.Saludo();
Pokemon pokemon2("Charmander", 0.91);
pokemon2.Saludo();


return 0;

}
