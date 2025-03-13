cmake_minimum_required(VERSION 3.10)
project(Rubrica)

# Imposta la versione di C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aggiunge la cartella include ai percorsi di ricerca degli header
include_directories(include)

# Trova automaticamente tutti i file .cpp nella cartella src
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Crea l'eseguibile con tutti i file sorgente trovati
add_executable(rubrica ${SRC_FILES} main.cpp)

# Imposta la directory di output
set_target_properties(rubrica PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
