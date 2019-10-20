//
// Created by Wang on 2019/10/20.
//

#include "Leetcode733cn.h"

vector<vector<int>> Leetcode733cn::floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int old = image[sr][sc];
    if (old == newColor)
        return image;

    image[sr][sc] = newColor;
    if (sr > 0 && image[sr - 1][sc] == old) {
        floodFill(image, sr - 1, sc, newColor);
    }
    if (sr < image.size() - 1 && image[sr + 1][sc] == old) {
        floodFill(image, sr + 1, sc, newColor);
    }
    if (sc > 0 && image[sr][sc - 1] == old) {
        floodFill(image, sr, sc - 1, newColor);
    }
    if (sc < image[0].size() - 1 && image[sr][sc + 1] == old) {
        floodFill(image, sr, sc + 1, newColor);
    }
    return image;
}
