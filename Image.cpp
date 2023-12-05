#include "Image.hpp"

Color::Color() {
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::~Color() {}

Image::Image() {
    m_width = 0;
    m_height = 0;
}

Image::Image(int height, int width) {
    this->m_height = height;
    this->m_width = width;

    this->m_colors = vector<Color>(height * width);
}

Image::~Image() {}

Color Image::getColor(int x, int y) const {

    return m_colors[y * m_width + x];
}

void Image::setColor(const Color &color, int x, int y) {
    m_colors[y * m_width + x].r = color.r;
    m_colors[y * m_width + x].g = color.g;
    m_colors[y * m_width + x].b = color.b;
}

void Image::Export(const char *path) const {
    ofstream f;
    f.open(path, std::ios::out | std::ios::binary);

    if(!f.is_open()){
        cout << "File could not be Opened\n";
        return;
    }

    unsigned char bmpPad[3] = {0, 0, 0};
    const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);
    //m_width * 3 is how many bits the bytes the color occupies
    //The (4 - (m_width * 3) % 4) tells how many bytes are left over.
    //The extra %4 is to make sure that we have zero as a remainder

    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    const int fileSize = fileHeaderSize + informationHeaderSize + (m_width * m_height * 3) + (paddingAmount * m_height);


}


