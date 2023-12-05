#ifndef PROJECT3_IMAGE_HPP
#define PROJECT3_IMAGE_HPP

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Color{
    float r, g, b;

    Color();
    Color(float r, float g, float b);
    ~Color();
};

class Image {
    Image();
    Image(int height, int width);
    ~Image();

    Color getColor(int x, int y) const;
    void setColor(const Color& color, int x, int y);

    void Export(const char* path) const;

private:
    int m_width;
    int m_height;

    vector<Color> m_colors;
};


#endif //PROJECT3_IMAGE_HPP
