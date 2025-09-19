#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(3, 3);
    Point edge(0, 5);
    Point outside(20, 5);

    std::cout << "Inside (3,3): " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Edge (0,5): " << (bsp(a, b, c, edge) ? "true" : "false") << std::endl;
    std::cout << "Outside (20,5): " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;

    return 0;
}

