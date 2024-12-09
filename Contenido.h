    #ifndef CONTENIDO_H
    #define CONTENIDO_H

    class Contenido {
        protected:
            int ID, length;
            float rating;
            string name, genre;
            bool restricted;

        public:
            // ==============getters====================
            int getID();
            string getName();
            int getLength();
            string getGenre();
            float getRating();
            bool getRestricted();
            //===============setters=======================
            void setID(int id);
            void setName(string nombre);
            void setLength(int largo);
            void setGenre(string genero);
            void setRating(float rate);
            void setRestricted(bool restringido);
            //===============metodos=======================
            virtual string reproducir()=0;
    };

    int Contenido::getID(){
        return ID;
    }

    string Contenido::getName(){
        return name;
    }

    int Contenido::getLength(){
        return length;
    }

    string Contenido::getGenre(){
        return genre;
    }

    float Contenido::getRating(){
        return rating;
    }

    bool Contenido::getRestricted(){
        return restricted;
    }

    void Contenido::setID(int id){      
        ID = id;
    }

    void Contenido::setName(string nombre){
        name = nombre;
    }

    void Contenido::setLength(int largo){
        length = largo;
    }

    void Contenido::setGenre(string genero){
        genre = genero;
    }

    void Contenido::setRating(float rate){
        rating = rate;
    }

    void Contenido::setRestricted(bool restringido){
        restricted = restringido;
    }

    #endif
