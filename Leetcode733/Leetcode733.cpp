//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode733.h"

vector<vector<int>> Leetcode733::floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (image[sr][sc] == newColor)
        return image;
    floodFill(image, oldColor, sr, sc, newColor);
    return image;
}

void Leetcode733::floodFill(vector<vector<int>> &image, int oldColor, int x, int y, int newColor) {
    if (image[x][y] != oldColor)
        return;

    image[x][y] = newColor;
    if (x - 1 >= 0)
        floodFill(image, oldColor, x - 1, y, newColor);
    if (x + 1 <= image.size() - 1)
        floodFill(image, oldColor, x + 1, y, newColor);
    if (y - 1 >= 0)
        floodFill(image, oldColor, x, y - 1, newColor);
    if (y + 1 <= image[0].size() - 1)
        floodFill(image, oldColor, x, y + 1, newColor);
}
