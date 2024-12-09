/*Plataforma de streaming
El programa actual simula una plataforma de streaming como Netflix, Disney+, Steam o HBO, recabando informacion sobre los usuarios
existentes de la cuenta como su nombre y su edad para desplegar contenido restringido o apto para todos. Además de esto, el
programa generará el contenido disponible en clases como películas, videojuegos, series y episodios mediante una archivo que 
contiene a los anteriores. Finalmente el usuario, dependiendo de su edad, podrá reproducir diversos contenidos al seleccionarlos 
mediante un menú interactivo que puede controlar con las flechas. Cada clas de contenido en el menu tendrá información relevante 
como un ID, nombre, duración, genero, rating, y otro tipo de informacion basado en su clase o características únicas.
*/
//Bibliotecas
#include <typeinfo>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <typeindex>

//Clases
using namespace std;
#include "Usuario.h"
#include "Contenido.h"
#include "Episode.h"
#include "Serie.h"
#include "Videojuego.h"
#include "Movie.h"

// ======================================================Funciones=============================================================

template<typename Value, typename Allocator>
bool Menu(string msg, vector<Value, Allocator> usuarios, vector<Contenido*> vec, bool restricted){
    /*
    (Implemento polimorfismo y clases abstractas de manera correcta y util,impemento sobrecarga y sobreescritura de métodos de 
    manera correcta y util)
    recibe:"msg" valor de tipo string, "usuarios" vector de valores de tipo universal hasta que se declaren, "vec" vector de
    valores de tipo Contenido*, "restricted" valor booleano.
    Despliega un menu interactivo con los vectores de usuarios y contenidos multimedia disponibles, dependiendo de la edad del
    usuario. El usuario puede navegar en el menu con las flechas y elegir la opcion con la tecla enter
    devuelve: un valor de tipo booleano
    */
    while(GetAsyncKeyState(VK_RETURN) != 0){ //Espera mientras que ninguna tecla este presionada
		Sleep(1);
	}
    vector<string> menu;
    if(usuarios.size() > 0){ //Si la funcion no recibe un vector vacio de usuarios, se recolectan los usuarios disponibles
        for (int i = 0; i < usuarios.size();i++){
            menu.push_back(usuarios[i]->getName());
        }
    }
    else{//Si la funcion recibe un vector vacio de usuarios, se recolectan los contenidos multimedia disponibles
        vector<Contenido*> newvec;
        if (restricted == true){ //Se recolectan los contenidos no restringidos si el usuario es menor de edad
            for (int i = 0; i < vec.size();i++){
                if(vec[i]->getRestricted() == false){
                    newvec.push_back(vec[i]);
                }
            }
            vec = newvec;
        }
        for (int i = 0; i < vec.size();i++){ // Se crea un string por cada contenido multimedia con sus datos relevantes
            stringstream stream;
            string texto;
            int largo;
            stream << fixed << setprecision(2) << vec[i]->getRating();

            //downcasting para acceder al metodo "getlength" especifico de la clase "Serie"
            const std::type_info& type_info = typeid(*vec[i]) ; 
            if(type_info == typeid(Serie)) 
            {   
                Serie *p1 = (Serie *) vec[i];
                largo = p1->getLength();
            }
            else{
                largo = vec[i]->getLength();
            }

            texto = vec[i]->getName() + "        || ID: " + to_string(vec[i]->getID()) + ", Duracion: "+ to_string(largo)\
            + ", Genero: " + vec[i]->getGenre() + ", Rating: " + stream.str();
            
        
            if(type_info == typeid(Videojuego))// downcasting para acceder a los métodos especificos de la clase videojuego
            {   
                Videojuego *p1 = (Videojuego *) vec[i];
                texto = texto + ", Monedas: " +  to_string(p1->getMonedas()) + ", Nivel: " + to_string(p1->getNivel()) + ", Powerup: "\
                + to_string(p1->getPowerup()) + ", Salud: " + to_string(p1->getSalud());
            }

            texto = texto  +" ||";
            menu.push_back(texto); //se añade el string del contenido multimedia a un vector de strings
        }

    }
   
    for (int i = 0; i < menu.size();i++){
        cout << menu[i] << endl;
    }
    menu.push_back("Salir");
	int pointer = 0;

	while(true){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout <<"=======================\n" << msg +"\n\n";
		// ============ color inicial de la primera opcion del menu ===========
		for (int i = 0; i < menu.size(); ++i){
			if (i == pointer){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << menu[i] << endl;
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << menu[i] << endl;
			}
		}
		
		while(true){	
			//Si la tecla "arriba" es presionada..
			if (GetAsyncKeyState(VK_UP) != 0){
				pointer -= 1;
				if (pointer == -1){
					pointer = menu.size()-1;
				}
				break;
			}
			//Si la tecla "abajo" es presionada..
			else if (GetAsyncKeyState(VK_DOWN) != 0){
				pointer += 1;
				if (pointer == menu.size()){
					pointer = 0;
				}
				break;
			}
			//Si la tecla "enter" es presionada..
			else if (GetAsyncKeyState(VK_RETURN) != 0){
				if (pointer == menu.size()-1){
                    if (menu[menu.size()-1] == "Salir"){ //Si se da enter en "Salir", el programa termina o retrocede al menu anterior
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    cout << "\n\n\n Hasta luego!";
                    Sleep(500);
					return 0;
                    }

                }
                else{
                    if(usuarios.size() <= 0){//Si se da enter en un contenido, se reproduce
                        cout << vec[pointer]->reproducir() << endl;
                        Sleep(1000);
                        break;
                    }
                    //Si se da click en un usuario se muestran sus contenidos disponibles
                    else if(typeid(usuarios)== typeid(vector<Usuario*>)){ 
                        cout << "\n\n\n Hola de nuevo " << menu[pointer]<< "!";
                        Sleep(500);    
                        restricted = usuarios[pointer]->getRestricted();
                        msg = "Peliculas,series y videojuegos";
                        vector<Usuario*> empty;
                        Menu(msg, empty, vec, restricted);
                        break;
                    }
                    break;
                }
			}
		}
		Sleep(150);
	}
    return 0;
}

//================================================Funcion principal main ======================================================

int main(){
    /*(Implemento herencia de manera correcta y util, Implemento polimorfismo y clases abstractas de manera correcta y util)
    recibe: ningun valor
    Abre el archivo que tiene los contenidos multimedia a mostrar, los cuales se guardan en vectores de tipo
    apuntador de diferentes clases y se pasan como parámetros a la funcion "Menu" para ser mostrados en pantalla.
    devuelve: no devuelve ningun valor
    */

    string name;
    int edad;
    int opcion;

    //Se abre archivo de texto con los contenidos que se guardaran en un vector de tipo Contenido*
    ifstream file;
    string lines;
    vector<Contenido*> vecContenido;

    file.open("contenidos.txt");
    vector<Episode*> episodios;

    while (getline(file, lines)) {
        string s;
        stringstream ss(lines);
        vector <string> line; 
        while (getline(ss, s, ',')) {
            line.push_back(s);
        }    

        if(s == "MOVIE"){
            vecContenido.insert(vecContenido.end(),1, new Movie(stoi(line[0]),stoi(line[1]),stof(line[2]),line[3],line[4],stoi(line[5])));
        }

        if(s == "EPISODE"){
            episodios.insert(episodios.end(),1,new Episode(stoi(line[0]),stoi(line[1]),stof(line[2]),line[3],line[4],stoi(line[5])));
        }

        if(s == "SERIE"){
            vecContenido.insert(vecContenido.end(),1, new Serie(stoi(line[0]),stoi(line[1]),stof(line[2]),line[3],line[4],stoi(line[5]),episodios));
            episodios.clear();
        }

        if(s == "JUEGO"){
        vecContenido.insert(vecContenido.end(),1,new Videojuego(stoi(line[0]),stoi(line[1]),stof(line[2]),line[3],line[4],stoi(line[5]),\
            stoi(line[6]),stoi(line[7]),stoi(line[8]),stoi(line[9])));
        }
    }
    file.close();
    
    //=========================Usuarios========================
    vector<Usuario*> usuarios = {new Usuario("Charly", 19), new Usuario("Timmy", 9)};

    //==========================Menu=============================
    string msg = "Usuarios: ";
    bool restricted = false;
    Menu(msg, usuarios, vecContenido, restricted);

    return 0;

}

