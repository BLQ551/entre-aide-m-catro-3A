cmake_minimum_required(VERSION 2.8)
project(projet_1)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

include(FindCurses)

message(STATUS " dossier des includes de ncurses : " ${CURSES_INCLUDE_DIRS})

include_directories(include ${CURSES_INCLUDE_DIRS})

#Construction de la bibliothèque
add_library(
        matrices
        SHARED
        src/matrices.cpp
        include/libmatrices/matrices.h
)

#Utilisation de la bibliothèque
link_directories(lib/${CMAKE_BUILD_TYPE})
#Déclaration de l'exécutable
add_executable(my_exe src/leprog.cpp)
#Configuration de l'édition de liens
target_link_libraries(my_exe matrices ncurses)

