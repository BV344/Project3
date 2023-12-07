#ifndef PROJECT3_SOLUTION_HPP
#define PROJECT3_SOLUTION_HPP

#include <iostream>
#include <vector>
#include <queue>
#include "EasyBMP.h"

using namespace std;

class Vertex {
public:
    Vertex();
    ~Vertex();
    Vertex(int width, int height);

    vector<Vertex> GetNeighbors(int maxWidth, int maxHeight, BMP& Image) const;

    void breadthFirstSearch(BMP& Image, Vertex s, Vertex t);
    void bestFirstSearch(BMP& Image, Vertex s, Vertex t);

private:
    int width;
    int height;
};

#endif //PROJECT3_SOLUTION_HPP
