cmake_minimum_required(VERSION 4.0)
project(BomberMan)

set(CMAKE_CXX_STANDARD 20)

add_executable(BomberMan main.cpp
        Menu.cpp
        Menu.h
        Player.cpp
        Player.h
        Globals.cpp
        Globals.h
        Stanza.cpp
        Stanza.h
        Bomba.cpp
        Bomba.h
        Render.cpp
        Render.h
        Entity.cpp
        Entity.h
        Enemy.cpp
        Enemy.h
        Position.h
        Game.cpp
        Game.h
)
