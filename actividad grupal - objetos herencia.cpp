//Herencia en POO

#include <iostream>
using namespace std;
//Clase persona
 class Persona{
 private: //Atributos
 string nombre;
 int edad;
 public: //Metodos
 Persona(string,int);//Constructor
 void mostrarPersona();
 };
//Subclase
class Alumno : public Persona{
private: //Atributos
string codigoAlumno;
float notaFinal;
public: //Metodos
Alumno(string,int,string,float);//Constructor de la clase Alumnos
void mostrarAlumno();

};

//Constructor de la clase Persona )(Clase Paadre)
Persona::Persona(string _nombre, int _edad){
nombre = _nombre;
edad = _edad;
}
//Constructor de la subclase
Alumno::Alumno(string _nombre,int _edad,string _codigoAlumno,float _notaFinal): Persona(_nombre,_edad){
codigoAlumno = _codigoAlumno;
notaFinal = _notaFinal;
}

void Persona::mostrarPersona(){
cout<<"Nombre: "<<nombre<<endl;
cout<<"Edad: "<<edad<<endl;
}

void Alumno::mostrarAlumno(){
mostrarPersona();
cout<<"Codigo Alumno: "<<codigoAlumno<<endl;
cout<<"Nota final: "<<notaFinal<<endl;
}

int main(){
Alumno alumno1("Alejandro",20,"12312312",15.6);

alumno1.mostrarAlumno();

system("pause");
return 0;
}
