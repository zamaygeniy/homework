#include "Maze.h"

int main() {
    //ui тоже не сделал
    Maze a(8, 8);
    srand(time(NULL));
    a.GenerateMaze3();
    a.DisplayMaze();
    cout << endl;
    //a.SwapExits();
    a.GeneratePathing();
}
