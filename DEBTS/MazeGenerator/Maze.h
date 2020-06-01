#ifndef MAZEGENERATOR_MAZE_H
#define MAZEGENERATOR_MAZE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Cell{
public:
    Cell();
    int x;
    int y;
    int value;
    //bool visited; бэктрекингом не сделал
};

class Maze {

public:
    void DisplayMaze();
    Maze(int, int);
    ~Maze();
    void GenerateMaze1();
    void GenerateMaze2(); //целых 3(!) процедуры
    void GenerateMaze3();
    void SwapExits();
    void GenerateExits();
    Cell GetExit();
    Cell GetEntrance();
    int GetLength();
    int GetWidth();
    bool Validation();
    void GeneratePathing();
private:
    Cell** maze;
    int length;
    int width;
    Cell exit;
    Cell entrance;
    Cell** mazePath;
};


#endif //MAZEGENERATOR_MAZE_H
