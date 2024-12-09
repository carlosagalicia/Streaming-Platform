#ifndef EPISODE_H
#define EPISODE_H

class Episode: public Contenido{
    private:
        int season;

    public:
        //Constructor:
        Episode();
        Episode(int id, int largo, float rate, string nombre, string genero, int temporada);
        // ==============getters====================
        int getSeason();
        // ==============setters====================
        void setSeason(int temporada);
        //===============metodos=======================
        string reproducir() override;    
        Episode operator+(Episode* val);
};
Episode::Episode():Contenido(){
    season = 0;
    length = 0;
}

Episode::Episode(int id, int largo, float rate, string nombre, string genero, int temporada){
    ID = id;
    length = largo;
    rating = rate;
    name = nombre;
    genre = genero;
    season = temporada;
}

int Episode::getSeason(){
    return season;
}

void Episode::setSeason(int temporada){
    season = temporada;
}

string Episode::reproducir(){
    /*(Implemento herencia de manera correcta y util,Implemento polimorfismo y clases abstractas de manera correcta y util,
    Impemento sobrecarga y sobreescritura de métodos de manera correcta y util)
    recibe: ningun valor
    devuelve: valor de tipo string con el nombre del objeto actual
    */
    return "Reproduciendo episodio " + this->getName() + "\n";
}

Episode Episode::operator+(Episode* val){
    /*(Impemento sobrecarga de operadores de manera correcta y util)
    recibe: valor val de tipo Episode*
    Establece que al sumar dos objetos de case Episode con "+" el atributo length del nuevo objeto tendra el valor de la suma de
    los valores length de los objetos que se suman.
    devuelve: objeto temp de clase Episode
    */
    Episode temp;
    temp.setLength(this->getLength() + val->getLength());
    return temp;
}

#endif
