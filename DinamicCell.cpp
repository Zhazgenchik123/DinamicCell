#include <iostream>
#include <cstdlib>
#include <ctime>

class Cell
{
public:
    Cell() :  symbol('0'), x(0), y(0) {}
    Cell(int val1, int val2,int sym) :symbol(sym),x(val1),y(val2) {}
    char symbol; //'1','2','3', 'A', '0', 'X'
    int x, y;
    void printCell() {
        if (highlighted) {
            std::cout << "\033[0;31m" << symbol << "\033[0m";
        }
        else {
            std::cout << symbol;
        }
    }
    void setHighlighted(bool value) {
        highlighted = value;
    }
private:
    bool highlighted = false;
};
int solve(int a, int b) {
    char characters[62];
    for (int i = 0; i < 10; ++i) {
       characters[i] = '0' + i;
   }
    for (int i = 0; i < 26; ++i) {
        characters[i + 10] = 'A' + i;
    }
   for (int i = 0; i < 26; ++i) {
        characters[i + 36] = 'a' + i;
    }
    int count = 0;
    int s;
    Cell** num = new Cell* [a];
    for (int i = 0; i < a; i++) {
        num[i] = new Cell[b];
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            s = std::rand() % 62;
            num[i][j] = Cell(i, j, characters[s]);
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b - 2; j++) {
            if (num[i][j].symbol == num[i][j + 1].symbol && num[i][j].symbol == num[i][j + 2].symbol) {
                count += 1;
                num[i][j].setHighlighted(true);
                num[i][j+1].setHighlighted(true);
                num[i][j+2].setHighlighted(true);
            }
        }
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a - 2; j++) {
            if (num[j][i].symbol == num[j + 1][i].symbol && num[j][i].symbol == num[j + 2][i].symbol) {
                count += 1;
                num[j][i].setHighlighted(true);
                num[j + 1][i].setHighlighted(true);
                num[j + 2][i].setHighlighted(true);
            }
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            num[i][j].printCell();
        }
        std::cout << std::endl;
    }



    for (int i = 0; i < a; i++) {
        delete[] num[i];
    }
    delete[] num;
    std::cout << count;
    return count;
    
}

int main()
{
    std::srand(std::time(nullptr));
    
    int rows, cols;

    std::cout << "Input quantity of rows: ";
    std::cin >> rows;
    std::cout << "Input quantity of cols: ";
    std::cin >> cols;
    solve(rows, cols);
    return 0;
}

