#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 101;

enum RobotOrientation {
    UP, RIGHT, DOWN, LEFT
};

struct bot {
    int x = 50, y = 50;
    RobotOrientation orientation = UP;
    int stepCounter = 0;
};

void moveForward(bot* k79, int field[SIZE][SIZE])
{
    switch (k79->orientation) 
    {
    case UP:    k79->y++; break;
    case DOWN:  k79->y--; break;
    case LEFT:  k79->x--; break;
    case RIGHT: k79->x++; break;
    }
    field[k79->x][k79->y] += 1;
    k79->stepCounter++;
}

void turnLeft(bot* k79)
{
    switch (k79->orientation) 
    {
    case UP:    k79->orientation = LEFT; break;
    case DOWN:  k79->orientation = RIGHT; break;
    case LEFT:  k79->orientation = DOWN; break;
    case RIGHT: k79->orientation = UP; break;
    }
}

void turnRight(bot* k79)
{
    switch (k79->orientation) 
    {
    case UP:    k79->orientation = RIGHT; break;
    case DOWN:  k79->orientation = LEFT; break;
    case LEFT:  k79->orientation = UP; break;
    case RIGHT: k79->orientation = DOWN; break;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    string fname = "INPUT.TXT";
    string oname = "OUTPUT.TXT";
    bot k79;
    string program;
    int field[SIZE][SIZE] = { 0 };
    field[k79.x][k79.y] += 1;
    ifstream fileInput(fname);
    ofstream fileOutput(oname);
    if (fileInput.is_open())
    {
        cout << "Файл открыт" << endl;
        fileInput >> program;
           //    cin >> program;
    }   

    bool wayIsCircled = false;
    for (int i = 0; i < program.length() && !wayIsCircled; i++)
    {
        if (program[i] == 'S')
            moveForward(&k79, field);
        if (program[i] == 'L')
            turnLeft(&k79);
        if (program[i] == 'R')
            turnRight(&k79);

        if (field[k79.x][k79.y] > 1)
        {
            wayIsCircled = true;
        }
    }
    if (wayIsCircled)
        fileOutput << k79.stepCounter << endl;
    else
        fileOutput << -1 << endl;
    fileOutput.close();
    return 0;
}
