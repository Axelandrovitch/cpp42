#include "Point.hpp"

static Fixed area(Point const &p1, Point const &p2, Point const &p3) {
    Fixed result = (p1.getX() * (p2.getY() - p3.getY()) +
                    p2.getX() * (p3.getY() - p1.getY()) +
                    p3.getX() * (p1.getY() - p2.getY())) / Fixed(2);
    if (result < Fixed(0))
        return result * Fixed(-1);
    return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = area(a, b, c);
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);

    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false;

    return (areaABC == areaPAB + areaPBC + areaPCA);
}

