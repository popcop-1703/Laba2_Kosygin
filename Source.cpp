#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

typedef pair<int, int> point;

int getPixelColor(int** image, int x, int y) {
    return image[x][y];
}

void setPixelColor(int** image, int x, int y, int color) {
    image[x][y] = color;
}

void fill(int** image, int x, int y, int fillColor, int borderColor) {
    if (getPixelColor(image, x, y) == borderColor) {
        return;
    }
    if (getPixelColor(image, x, y) == fillColor) {
        return;
    }
    setPixelColor(image, x, y, fillColor);
    fill(image, x + 1, y, fillColor, borderColor);
    fill(image, x - 1, y, fillColor, borderColor);
    fill(image, x, y + 1, fillColor, borderColor);
    fill(image, x, y - 1, fillColor, borderColor);
}

int main() {
    int width = 10;
    int height = 10;
    int** image = new int* [width];
    for (int i = 0; i < width; i++) {
        image[i] = new int[height];
        for (int j = 0; j < height; j++) {
            image[i][j] = 1;
        }
    }
    for (int i = 1; i < width - 1; i++) {
        image[i][1] = 0; // Граница
        image[i][height - 2] = 0; // Граница
    }
    for (int j = 1; j < height - 1; j++) {
        image[1][j] = 0; // Граница
        image[width - 2][j] = 0; // Граница
    }

    fill(image, 5, 5, 2, 0);

    ofstream fout("output.txt");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fout << image[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
    Sleep(10000);
    return 0;
}