cmake_minimum_required(VERSION 3.23)
project(SemesterProjektWS2223)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-O0)

include_directories(GraphLib)

add_library(
        GraphLib STATIC
        GraphLib/Node.cpp
        GraphLib/Node.h
        GraphLib/Edge.cpp
        GraphLib/Edge.h
        GraphLib/Graph.cpp
        GraphLib/Graph.h
        GraphLib/NodeExistsException.cpp
        GraphLib/NodeExistsException.h
)


add_executable(SemesterProjektWS2223 main.cpp Piece.h Chessboard.h Chessboard.cpp
        Field.h Field.cpp Color.h King.h Pawn.h King.h Knight.cpp)

target_link_libraries(SemesterProjektWS2223 LINK_PUBLIC GraphLib)