#include "Solution.hpp"

Vertex::Vertex() {
    width = 0;
    height = 0;
}

Vertex::~Vertex() {}


Vertex::Vertex(int width, int height) {
    this->width = width;
    this->height = height;
}

void Vertex::breadthFirstSearch(BMP &Image, Vertex s, Vertex t) {
    int maxWidth = Image.TellWidth();//Grabs Maximum Width
    int maxHeight = Image.TellHeight();//Grabs Maximum Height

    // Initialize a queue
    queue<Vertex> Q;
    Q.push(s);

    //Initialize 2D Vector & Set ALL = False
    vector<vector<bool>> visited(maxWidth, vector<bool>(maxHeight, false));

    //Makes the starting vertex equal to true
    visited.at(s.width).at(s.height) = true;

    //Setting the distance of Width and Height
    vector<vector<int>> distance(maxWidth, vector<int>(maxHeight, INT_MAX));//Makes all the distances infinity or rather INT_MAX
    distance[s.width][s.height] = 0;  // Sets the distance of the starting vertex

    //Initialize 2D vector and make every vertex = (-1,-1)
    vector<vector<Vertex>> prev(maxWidth, vector<Vertex>(maxHeight, { -1, -1 }));

    while (!Q.empty() && !visited[t.width][t.height]) {
        Vertex u = Q.front();
        Q.pop();

        //Get Neighbors gets the pixels that neigbor the pixel you're at.
        vector<Vertex> neighbors = u.GetNeighbors(maxWidth, maxHeight, Image);

        for (int i = 0; i < neighbors.size(); ++i) {
            Vertex v = neighbors[i];
            if (!visited[v.width][v.height]) {
                visited[v.width][v.height] = true;
                Image(v.width, v.height)->Red = 0;
                Image(v.width, v.height)->Green = 255; // Set color of v to Green
                Image(v.width, v.height)->Blue = 0;

                distance[v.width][v.height] = distance[u.width][u.height] + 1;

                prev[v.width][v.height] = u;  // Update predecessor

                Q.push(v);
            }
        }
    }
    //This code helps you find the path backwards and convert the pixels red
    Vertex v = t;
    while (v.width != -1 || v.height != -1) {
        Image(v.width, v.height)->Red = 255;
        Image(v.width, v.height)->Green = 0;
        Image(v.width, v.height)->Blue = 0;

        v = prev[v.width][v.height];
    }

}

void Vertex::bestFirstSearch(BMP &Image, Vertex s, Vertex t) {
    int maxWidth = Image.TellWidth();//Grabs Maximum Width
    int maxHeight = Image.TellHeight();//Grabs Maximum Height

    std::vector<std::vector<bool>> visited(maxWidth, std::vector<bool>(maxHeight, false));
    std::vector<std::vector<int>> distance(maxWidth, std::vector<int>(maxHeight, INT_MAX));
    std::vector<std::vector<Vertex>> prev(maxWidth, std::vector<Vertex>(maxHeight, { -1, -1 }));

    visited[s.width][s.height] = true;
    distance[s.width][s.height] = 0;

    CompareVertex comparator(t);  //This Vertex is the Destination!

    priority_queue<Vertex, vector<Vertex>, CompareVertex> Q(comparator);
    Q.push(s);

    while (!Q.empty() && !visited[t.width][t.height]) {
        Vertex u = Q.top();
        Q.pop();

        vector<Vertex> neighbors = u.GetNeighbors(maxWidth, maxHeight, Image);

        for (int i = 0; i < neighbors.size(); ++i) {
            Vertex v = neighbors[i];
            if (!visited[v.width][v.height]) {
                visited[v.width][v.height] = true;
                Image(v.width, v.height)->Red = 0;
                Image(v.width, v.height)->Green = 255;
                Image(v.width, v.height)->Blue = 0;

                int h_v = v.heuristic(v, t);

                distance[v.width][v.height] = distance[u.width][u.height] + 1;
                prev[v.width][v.height] = u;

                Q.push(v);
            }
        }
    }

    Vertex v = t;
    while (v.width != -1 || v.height != -1) {
        Image(v.width, v.height)->Red = 255;
        Image(v.width, v.height)->Green = 0;
        Image(v.width, v.height)->Blue = 0;

        v = prev[v.width][v.height];
    }

}

vector<Vertex> Vertex::GetNeighbors(int maxWidth, int maxHeight, BMP &Image) const {
    std::vector<Vertex> neighbors; //8-Connected Neighbors with RGB constraint

    //This double for loop is to get the neighboring pixels
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0)//Skip the center point(dx=0, dy=0)
                continue;

            int nx = width + dx;//This makes sure that the newX is either 1 less or 1 more
            int ny = height + dy;//This makes sure that the newY is either 1 less or 1 more


            if (nx >= 0 && nx < maxWidth && ny >= 0 && ny < maxHeight) {
                // Add the neighbor if it is within the bounds of the image and satisfies the RGB constraint
                if (Image(nx, ny)->Red > 100 || Image(nx, ny)->Green > 100 || Image(nx, ny)->Blue > 100) {
                    neighbors.emplace_back(nx, ny);//Adds new Vertex in the 'neighbors' Variable
                }
            }
        }
    }

    return neighbors;
}

int Vertex::heuristic(const Vertex& u, const Vertex& t) const {
    // This function calculates the heuristic value h[u] = |p1 – t1| + |p2 – t2|
    return abs(u.width - t.width) + abs(u.height - t.height);
}



