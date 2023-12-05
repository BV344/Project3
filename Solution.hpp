#ifndef PROJECT3_SOLUTION_HPP
#define PROJECT3_SOLUTION_HPP

#include "EasyBMP.h"

using namespace std;

class Solution {
public:
    void breadthFirstSearch(BMP& Image, int s_width, int s_height, int t_width, int t_height);
    void bestFirstSearch(BMP& Image, int s_width, int s_height, int t_width, int t_height);
};

#endif //PROJECT3_SOLUTION_HPP
