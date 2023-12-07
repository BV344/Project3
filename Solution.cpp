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
    cout << "s.width - " << s.width << " s.height - " << s.height << endl;
    Image(s.width, s.height)->Red = 255;
    Image(s.width, s.height)->Green = 0;
    Image(s.width, s.height)->Blue = 0;

    cout << "t.width - " << t.width << " t.height - " << t.height << endl;
    Image(t.width, t.height)->Red = 255;
    Image(t.width, t.height)->Green = 0;
    Image(t.width, t.height)->Blue = 0;

    int maxWidth = Image.TellWidth();
    int maxHeight = Image.TellHeight();

    // Initialize a queue
    queue<Vertex> Q;
    Q.push(s);

    // Initialize 2D Vector & Set all visited to False
    vector<vector<bool>> visited(maxWidth, vector<bool>(maxHeight, false));
    cout << "Displaying Boolean: " << visited.at(0).at(0) << endl;

    visited.at(s.width).at(s.height) = true;
    cout << "Displaying Boolean: " << visited.at(0).at(0) << endl;

    //Setting the distance of Width and Height
    vector<vector<int>> distance(maxWidth, vector<int>(maxHeight, INT_MAX));
    cout << "Displaying Distance: " << distance.at(0).at(100) << endl;

    while(!Q.empty() && !visited[t.width][t.height]){
        Vertex temp = Q.front();
        Q.pop();



    }

}

void Vertex::bestFirstSearch(BMP &Image, Vertex s, Vertex t) {

}



