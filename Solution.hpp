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
    int heuristic(const Vertex& u, const Vertex& t) const;

    void breadthFirstSearch(BMP& Image, Vertex s, Vertex t);
    void bestFirstSearch(BMP& Image, Vertex s, Vertex t);

private:
    int width;
    int height;
};

struct CompareVertex {
    Vertex t;  // Add a member variable to store the target vertex

    CompareVertex(const Vertex& target) : t(target) {}

    bool operator()(const Vertex& v1, const Vertex& v2) const {
        // Compare based on the estimated distance (heuristic)
        return v1.heuristic(v1, t) > v2.heuristic(v2, t);
    }
};

#endif //PROJECT3_SOLUTION_HPP
