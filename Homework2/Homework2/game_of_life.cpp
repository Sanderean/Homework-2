#include "game_of_life.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

bool game_of_life::random_value() {
    return rand() % 2 == 1;
}

bool game_of_life::cell_taken(int i, int j) {
    if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
        return false;
    }
    return _generation[i][j];
}

game_of_life::game_of_life() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            _generation[i][j] = random_value();
        }
    }
}

void game_of_life::next_generation() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int neighbors = 0;
            neighbors += cell_taken(i - 1, j - 1);
            neighbors += cell_taken(i - 1, j);
            neighbors += cell_taken(i - 1, j + 1);
            neighbors += cell_taken(i, j - 1);
            neighbors += cell_taken(i, j + 1);
            neighbors += cell_taken(i + 1, j - 1);
            neighbors += cell_taken(i + 1, j);
            neighbors += cell_taken(i + 1, j + 1);
            if (_generation[i][j]) {
                _next_generation[i][j] = (neighbors == 2 || neighbors == 3);
            }
            else {
                _next_generation[i][j] = (neighbors == 3);
            }
        }
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}

void game_of_life::draw() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << (_generation[i][j] ? '*' : '_');
        }
        cout << endl;
    }
    cout << endl;
}