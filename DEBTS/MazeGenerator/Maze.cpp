#include "Maze.h"

Cell::Cell() {
    x = -1;
    y = -1;
//    visited = false;
}



Maze::Maze(int length, int width) {

    length = length * 2 + 1;
    width = width * 2 + 1;
    this->length = length;
    this->width = width;
    maze = new Cell * [length];
    for (int k = 0; k < length; ++k) {
        maze[k] = new Cell[width];
    }

    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; ++j) {
            maze[i][j].x = i;
            maze[i][j].y = j;
            maze[i][j].value = 1;
        }

    for (int i = 1; i < length; i += 2)
        for (int j = 1; j < width; j += 2) {
            maze[i][j].value = 0;
        }


}



void Maze::GeneratePathing() {
    if(length == 0)
        return;

    mazePath = new Cell * [length];
    for (int k = 0; k < length; ++k) {
        mazePath[k] = new Cell[width];
    }
    int wall = -1, nothing = -2;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if(maze[i][j].value)
                mazePath[i][j].value = wall;
            else
                mazePath[i][j].value = nothing;
        }
    }

    mazePath[entrance.x][entrance.y].value = 0;
    int dx[4] = {1, 0, -1, 0};   // смещения, соответствующие соседям ячейки
    int dy[4] = {0, 1, 0, -1};

    // волновой поиск пути
    int d = 0;
    bool stop;
    do {
        stop = true;               //новых клеток нет
        for (int x = 0; x < length; ++x )
            for (int y = 0; y < width; ++y )
                if ( mazePath[x][y].value == d )
                {
                    for (int k = 0; k < 4; ++k )                    // проход по соседним клеткам
                    {
                        int ix = x + dx[k], iy = y + dy[k];
                        if ( ix >= 0 && ix < length && iy >= 0 && iy < width && mazePath[ix][iy].value == nothing)
                        {
                            stop = false;                         // новая клетка
                            mazePath[ix][iy].value = d + 1;      // распространение волны
                        }
                    }
                }
        d++;
    } while ( !stop && mazePath[exit.x][exit.y].value == nothing );

    for (int l = 0; l < length; ++l) {
        for (int i = 0; i < width; ++i) {
            if(mazePath[l][i].value == -1)
                cout << setw(3) << char(178);
            else
                if(mazePath[l][i].value == -2)
                    cout << setw(3) << " ";
                else
                    cout << setw(3) << mazePath[l][i].value;
        }
        cout << endl;
    }


}

void Maze::GenerateMaze1() {
    for (int i = 1; i < length; i += 2) {
        for (int j = 1; j < width; j += 2) {
            if (i != 1)
                if (rand() % 2 == 0)
                    if (j != width - 2)
                        maze[i][j + 1].value = 0;
                    else
                        maze[i - 1][j].value = 0;
                else
                    maze[i - 1][j].value = 0;
            else
            if (j != width - 2)
                maze[i][j + 1].value = 0;
        }
    }

    GenerateExits();

}

void Maze::DisplayMaze() {
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if (maze[i][j].value == 0)
                cout << setw(3) << " ";
            else
                cout << setw(3) << char(178);
        }
        cout << endl;
    }
}

Maze::~Maze() {
    for (int i = 0; i < length; ++i) {
        delete[] maze[i];
    }
    delete[] maze;
    length = 0;
    width = 0;
}

void Maze::GenerateMaze2() {

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j].value = 0;
        }
    }

    for (int i = 0; i < length; i++) {
        maze[i][0].value = 1;
        maze[i][width - 1].value = 1;
    }

    for (int i = 0; i < width; i++) {
        maze[0][i].value = 1;
        maze[length - 1][i].value = 1;
    }

    for (int i = 1; i < length - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            if (rand() % 4 == 0)
                maze[i][j].value = 1;
        }
    }

    GenerateExits();
}

void Maze::GenerateExits() {

    entrance.value = 1;
    exit.value = 1;
    entrance.x = 0;
    exit.x = length - 1;

    while (entrance.value == 1) {
        int coord = rand() % (width - 2) + 1;
        if (maze[1][coord].value == 0) {
            entrance.value = 0;
            entrance.y = coord;
            maze[entrance.x][entrance.y].value = 0;
        }
    }

    while (exit.value == 1) {
        int coord = rand() % (width - 2) + 1;
        if (maze[length - 2][coord].value == 0) {
            exit.value = 0;
            exit.y = coord;
            maze[exit.x][exit.y].value = 0;
        }
    }
}

bool Maze::Validation() {
    for (int i = 1; i < length; i += 2)
        for (int j = 1; j < width; j += 2) {
            if (maze[i][j].value != 0)
                return true;
        }
    return false;
}

//тут страх
void Maze::GenerateMaze3() {

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            maze[i][j].value = 1;
        }
    }

    bool flag = true;
    maze[1][1].value = 0;
    int x = 1, y = 1, counter = 0;

    while (flag) {
        counter++;
        int direction = rand() % 4;
        enum { goLeft = 0, goRight, goUp, goDown };
        switch (direction) {
            case goLeft:
                if (y - 2 > 0) {
                    if (maze[x][y - 1].value == 0 &&
                        maze[x][y - 2].value == 0)              // можно без == 0, но так лучше понимается
                        y -= 2;
                    else if (maze[x][y - 2].value == 1) {      // else if -- такой рефактор сделала ide если что :^)
                        maze[x][y - 1].value = 0;
                        maze[x][y - 2].value = 0;
                        y -= 2;
                    }
                }
                break;
            case goRight:
                if (y + 2 < width) {
                    if (maze[x][y + 1].value == 0 && maze[x][y + 2].value == 0)
                        y += 2;
                    else if (maze[x][y + 2].value == 1) {
                        maze[x][y + 1].value = 0;
                        maze[x][y + 2].value = 0;
                        y += 2;
                    }
                }
                break;
            case goUp:
                if (x - 2 > 0) {
                    if (maze[x - 1][y].value == 0 && maze[x - 2][y].value == 0)
                        x -= 2;
                    else if (maze[x - 2][y].value == 1) {
                        maze[x - 1][y].value = 0;
                        maze[x - 2][y].value = 0;
                        x -= 2;
                    }
                }
                break;
            case goDown:
                if (x + 2 < length) {
                    if (maze[x + 1][y].value == 0 && maze[x + 2][y].value == 0)
                        x += 2;
                    else if (maze[x + 2][y].value == 1) {
                        maze[x + 1][y].value = 0;
                        maze[x + 2][y].value = 0;
                        x += 2;
                    }
                }
        }

        if (counter % (width + length) == 0)
            flag = Validation();
    }

    GenerateExits();
}

int Maze::GetWidth() {
    return this->width;
}

int Maze::GetLength() {
    return this->length;
}

void Maze::SwapExits() {
    Cell temp;
    temp.x = exit.x;
    temp.y = exit.y;
    exit.x = entrance.x;
    exit.y = entrance.y;
    entrance.x = temp.x;
    entrance.y = temp.y;
}

