#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void input(int**, int, const char*);
void output(int**, int, const char*);
void transformation(int**, int**, int);
int** allocateMatrix(int);
int* allocateArray(int);
int matrixOrder(const char*);

int main()
{
    const char* inPath = "in.txt";
    const char* outPath = "out.txt";
    int side = matrixOrder(inPath);

    int** firstMatrix = allocateMatrix(side);
    for (int i = 0; i < side; i++) {
        firstMatrix[i] = allocateArray(side);
    }

    int** secondMatrix = allocateMatrix(side);
    for (int i = 0; i < side; i++) {
        secondMatrix[i] = allocateArray(side);
    }

    input(firstMatrix, side, inPath);
    transformation(firstMatrix, secondMatrix, side);
    output(secondMatrix, side, outPath);
}


int matrixOrder(const char* path) {
    ifstream in;
    in.open(path);
    if (!in.is_open()) {
        cout << "Input file is not open\n";
    }
    int temp;
    int count = 0;
    while (in >> temp) {
        count++;
    }
    in.clear();
    in.seekg(0);
    in.close();
    return sqrt(count);
}

void input(int** matrix, int side, const char* path) {
    ifstream in;
    in.open(path);
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            in >> matrix[i][j];
        }
    }
    in.close();
}

void output(int** matrix, int side, const char* path) {
    std::ofstream out(path, std::ios::app);
    out << endl;
    for (int i = 0; i < side; i++) {
        out << endl;
        for (int j = 0; j < side; j++) {
            out << matrix[i][j] << " ";
        }
    }
    out.close();
}

void transformation(int** first, int** second, int side) {
    for (int i = 0; i < side; i++) {
        for (int j = i; j < side; j++) {
            if (i == j) {
                second[i][j] = first[i][j];
                continue;
            }
            second[i][j] = first[0][0];
            second[j][i] = first[0][0];
            for (int k = 0; k < side; k++) {
                for (int l = k; l < side; l++) {
                    if (k <= i || l >= j) {
                        if (first[k][l] >= second[i][j])
                            second[i][j] = first[k][l];
                        if (first[l][k] >= second[j][i])
                            second[j][i] = first[l][k];
                    }
                }
            }
        }
    }
}

int** allocateMatrix(int side) {
    return new int* [side];
}

int* allocateArray(int side) {
    return new int[side];
}
