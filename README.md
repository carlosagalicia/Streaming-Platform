# **Plataforma-de-streaming**
### Contexto
La popularidad de los servicios de streaming como Prime Video, HBO+, Netflix o Disney+ ha aumentado considerablemente en la actualidad. Este proyecto consiste en la elaboración de buscador de contenido audiovisual, donde se le mostrará al usuario una coleccion de películas, series y episodios basados en el título buscado. Este proyecto es bastante interesante debido a que se utiliza comunmente por muchos servicios como los mencionados anteriormente, además de que es posible realizarlo de diversas formas e identificarlo como uno de los componentes o funcionalidades escenciales que forman parte de estos servicios.

### Solución
La forma en la cual daría solucion al probema sería declarando 3 clases principales, las cuales serían la clase "Video", la clase "Serie" y la clase "Episodio". Donde los videos tienen su propio ID, nombre, tamaño, genero y rating, los episodios y las peliculas tendrian estas mismas características, además de que los episodios contaran con una temporada a la cual perteneceran. Por otro lado se planea que las series contengan los episodios y las mismas características de los videos (ID, nombre, tamaño, genero y rating). Finalmente se mostrarán las películas, series y episodios dependiendo del nombre y/o género buscado.

### Instrucciones para la ejecución del programa
Descargar el archivo (.cpp)

Generar el ejecutable (.exe):
  
    g++ -o streaming.cpp
  
Ejecutar en terminal con los comandos:

    streaming.exe
