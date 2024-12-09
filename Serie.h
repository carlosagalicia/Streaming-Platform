#ifndef SERIE_H
#define SERIE_H

class Serie: public Contenido{
    private:
        vector<Episode*> episodios;
    public:
        //Constructor:
        Serie(int id, int largo, float rate, string nombre, string genero, bool restringido, vector<Episode*> _episodios);
        //===============setters=======================
        vector<Episode*> getEpisodes();    
        int getLength();
        //===============metodos=======================
        bool menu(string, vector<Episode*>);
        string reproducir(int);
        string reproducir() override; 
};

Serie::Serie(int id, int largo, float rate, string nombre, string genero,bool restringido, vector<Episode*> _episodios){ 
    ID = id;
    length = largo;
    rating = rate;
    name = nombre;
    genre = genero;
    restricted = restringido;
    episodios = _episodios;
}

vector<Episode*> Serie::getEpisodes(){
    return episodios;
}

int Serie::getLength(){
    /*(Codifico clases con métodos, atributos y modificadores de acceso(constructores, getters, setters),
    Impemento sobrecarga de operadores de manera correcta y util,Implemento herencia de manera correcta y util,
    Impemento sobrecarga y sobreescritura de métodos de manera correcta y util)
    recibe: ningun valor
    Suma la duracion de cada episodio en el vector de episodios en un nuevo objeto de tipo Episodio y devuelve su duracion total
    devuelve: atributo length de tipo int
    */ 
    Episode ep3;
    for(int i = 0; i < episodios.size(); i++){
        const std::type_info& type_info = typeid(*episodios[i]) ;
        if(type_info == typeid(Episode))
        {   
            Episode *p1 = (Episode *) episodios[i];
            ep3 = ep3 + p1;
        }
    }
    length = ep3.getLength();
    return length;
}


bool Serie::menu(string msg ,vector<Episode*> _episodios){
    /*
    (Implemento polimorfismo y clases abstractas de manera correcta y util,impemento sobrecarga y sobreescritura de métodos de 
    manera correcta y util)
    recibe:"msg" valor de tipo string, "episodios" vector de valores de tipo Episode*
    Despliega un menu interactivo con los vectores episodios y su informacion. El usuario puede navegar en el menu con las 
    flechas y elegir la opcion con la tecla enter
    devuelve: un valor de tipo booleano
    */
    while(GetAsyncKeyState(VK_RETURN) != 0){
		Sleep(1);
	}
    vector<string> menu;
    int season = 0;
    int count = 1;
    for (int i = 0; i < _episodios.size();i++){
        if (season != _episodios[i]->getSeason()){
            season = season + 1;
            count = 1;
        }
        stringstream stream;
        stream << fixed << setprecision(2) << _episodios[i]->getRating();
        string texto = "Temporada " + to_string(_episodios[i]->getSeason()) + " Episodio "+ to_string(count) + ": " + _episodios[i]->getName()\
         + "        || ID: " + to_string(_episodios[i]->getID()) + ", Duracion: "+ to_string(_episodios[i]->getLength())+ ", Genero: " + \
         _episodios[i]->getGenre() + ", Rating: " + stream.str() +" ||";
        menu.push_back(texto);
        count += 1;
    }

    for (int i = 0; i < menu.size();i++){
        cout << menu[i] << endl;
    }
    menu.push_back("Regresar");
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
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    cout << "\n\n\n Regresando...";
                    Sleep(500);
					return 0;
                }
                else{
                    cout << this->reproducir(pointer+1) << endl;
                    Sleep(1000);
                    break;
                }
			}
		}
		Sleep(150);
	}
    return 0;
}

string Serie::reproducir(int _ep){
    /*(Implemento herencia de manera correcta y util,Implemento polimorfismo y clases abstractas de manera correcta y util,
    Impemento sobrecarga y sobreescritura de métodos de manera correcta y util)
    recibe: valor _ep de tipo in
    Llama a la funcion reproducir de cada episodio basado en su numero de episodio
    devuelve: valor de tipo string con el nombre del objeto actual basado en el numero de episodio
    */
     vector<Episode*> eps = this->getEpisodes();
     return eps[_ep-1]->reproducir();
}

string Serie::reproducir(){
    /*(Implemento herencia de manera correcta y util,Implemento polimorfismo y clases abstractas de manera correcta y util,
    Impemento sobrecarga y sobreescritura de métodos de manera correcta y util)
    recibe: ningun valor
    Despliega un menu de la serie con su vector de episodios
    devuelve: string vacio
    */
    string msg = "Serie " + this->getName();
    vector<Episode*> eps = this->getEpisodes();
    this->menu(msg, eps);
    return "";
}

#endif
