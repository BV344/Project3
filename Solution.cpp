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
    //For Testing purposes
//    cout << "s.width - " << s.width << " s.height - " << s.height << endl;
//    Image(s.width, s.height)->Red = 255;
//    Image(s.width, s.height)->Green = 0;
//    Image(s.width, s.height)->Blue = 0;
//
//    cout << "t.width - " << t.width << " t.height - " << t.height << endl;
//    Image(t.width, t.height)->Red = 255;
//    Image(t.width, t.height)->Green = 0;
//    Image(t.width, t.height)->Blue = 0;

    int maxWidth = Image.TellWidth();
    int maxHeight = Image.TellHeight();

    // Initialize a queue
    queue<Vertex> Q;
    Q.push(s);

    // Initialize 2D Vector & Set all visited to False
    vector<vector<bool>> visited(maxWidth, vector<bool>(maxHeight, false));

    //Makes the starting vertex equal to true
    visited.at(s.width).at(s.height) = true;

    //Setting the distance of Width and Height
    vector<vector<int>> distance(maxWidth, vector<int>(maxHeight, INT_MAX));//Makes all the distances infinity or rather INT_MAX
    distance[0][0] = 0;//Sets the distance of the starting vertex

    while (!Q.empty() && !visited[t.width][t.height]) {
        Vertex u = Q.front();
        Q.pop();

        // Assuming you have a function GetNeighbors in the Vertex class that returns neighbors
        vector<Vertex> neighbors = u.GetNeighbors(maxWidth, maxHeight, Image);

        for (int i = 0; i < neighbors.size(); ++i) {
            const Vertex &v = neighbors[i];
            if (!visited[v.width][v.height]) {
                visited[v.width][v.height] = true;
                Image(v.width, v.height)->Red = 0;
                Image(v.width, v.height)->Green = 255; // Set color of v to Green
                Image(v.width, v.height)->Blue = 0;

                distance[v.width][v.height] = distance[u.width][u.height] + 1;

                Q.push(v);
            }
        }
    }
}

void Vertex::bestFirstSearch(BMP &Image, Vertex s, Vertex t) {

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





