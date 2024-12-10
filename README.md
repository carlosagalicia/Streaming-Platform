# **Streaming Platform**
### Context
The popularity of streaming services such as Prime Video, HBO+, Netflix, and Disney+ has significantly increased in recent times. This project involves creating a search engine for audiovisual content, where users can browse a collection of movies, series, and episodes based on the searched title. This project is particularly interesting as it mirrors functionality commonly used by many services like those mentioned above. Moreover, it can be implemented in various ways and is a core feature of these services.

### Solution
The proposed solution involves defining three main classes: the "Video" class, the "Series" class, and the "Episode" class. Videos will have their own ID, name, size, genre, and rating. Both episodes and movies will share these characteristics, with episodes also having a season to which they belong. Additionally, series will contain episodes and the same attributes as videos (ID, name, size, genre, and rating). The program will display movies, series, and episodes based on the searched title and/or genre.

### Instructions for Running the Program
1. Download the file (.cpp).

2. Generate the executable (.exe):
    ```bash
    g++ -o streaming streaming.cpp
    ```

3. Run in the terminal using the command:
    ```bash
    streaming.exe
    ```
