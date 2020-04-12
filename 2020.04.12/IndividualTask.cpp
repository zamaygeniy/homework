#include <iostream>
#include <fstream>

using namespace std;


int Side();
void Input(int**, int);
void Output(int**, int);
void Transformation(int**, int**, int);
int** AllocateMemory(int);
int* _AllocateMemory(int);

int Side() {
    ifstream in;
    in.open("D:\\in.txt");
    if (!in.is_open())
    {
        cout << "";
    }
    int temp;
    int count = 0;
    while (in >> temp)
    {
        count++;
    }

    in.clear();
    in.seekg(0, ios::beg);
    in.close();
    return sqrt(count);
}

void Input(int** A, int side) {
    ifstream in;
    in.open("D:\\in.txt");

    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            in >> A[i][j];
        }
    }

    in.close();
}

void Output(int** B, int side) {
    std::ofstream out("D:\\in.txt", std::ios::app);
    out << endl;
    for (int i = 0; i < side; i++)
    {
        out << endl;
        for (int j = 0; j < side; j++)
        {
            out << B[i][j] << " ";
        }
    }
    out.close();
}

void Transformation(int** A, int** B, int side) {
    for (int i = 0; i < side; i++)
    {
        for (int j = i; j < side; j++)
        {
            if (i == j)
            {
                B[i][j] = A[i][j];
                continue;
            }
            B[i][j] = A[0][0];
            B[j][i] = A[0][0];
            for (int k = 0; k < side; k++)
            {
                for (int l = k; l < side; l++)
                {
                    if (k <= i || l >= j)
                    {
                        if (A[k][l] >= B[i][j])
                            B[i][j] = A[k][l];
                        if (A[l][k] >= B[j][i])
                            B[j][i] = A[l][k];
                    }
                }
            }
        }
    }
}

int** AllocateMemory(int side) {
    return new int* [side];
}

int* _AllocateMemory(int side) {
    return new int[side];
}

int main()
{
    int side = Side();

    int** A = AllocateMemory(side);
    for (int i = 0; i < side; i++)
    {
        A[i] = _AllocateMemory(side);
    }

    int** B = AllocateMemory(side);
    for (int i = 0; i < side; i++)
    {
        B[i] = _AllocateMemory(side);
    }

    Input(A, side);
    Transformation(A, B, side);
    Output(B, side);
}
