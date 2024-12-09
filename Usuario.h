#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
    private:
        string nombre;
        int edad;
        bool restricted = false;

    public:
        // Constructor:
        Usuario(string _nombre, int _edad);
        // ==============getters====================
        string getName();
        int getEdad();
        bool getRestricted();
        // ==============setters====================
        void setName(string _nombre);
        void setEdad(int _edad);
};

Usuario::Usuario(string _nombre, int _edad){
    nombre = _nombre;
    edad = _edad;
}

string Usuario::getName(){
    return nombre;
}

int Usuario::getEdad(){ 
    return edad;
}

bool Usuario::getRestricted(){
    /*(Codifico clases con métodos, atributos y modificadores de acceso  (constructores, getters, setters))
    recibe: ningun valor
    Determina si el usuario tiene una cuenta restringida a partir de su edad
    devuelve: valor restricted de tipo bool
    */ 
    if (this->getEdad() < 18){
        restricted = true;
    }
    else{
        restricted = false;
    }
    return restricted;
}

void Usuario::setName(string _nombre){
    nombre = _nombre;
}

void Usuario::setEdad(int _edad){
    edad = _edad;
}

#endif
