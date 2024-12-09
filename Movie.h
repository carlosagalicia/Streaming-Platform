#ifndef MOVIE_H
#define MOVIE_H

class Movie: public Contenido{
    public:
    //Constructor:
    Movie(int id, int largo, float rate, string nombre, string genero, bool restringido);
    //===============metodos=======================
    string reproducir() override;
};


Movie::Movie(int id, int largo, float rate, string nombre, string genero, bool restringido){
    ID = id;
    length = largo;
    rating = rate;
    name = nombre;
    genre = genero;
    restricted = restringido;
}

string Movie::reproducir(){
    /*(Implemento herencia de manera correcta y util,Implemento polimorfismo y clases abstractas de manera correcta y util,
    Impemento sobrecarga y sobreescritura de métodos de manera correcta y util)
    recibe: ningun valor
    devuelve: valor de tipo string con el nombre del objeto actual
    */
    return "Reproduciendo pelicula " + this->getName() + "\n";
}

#endif
