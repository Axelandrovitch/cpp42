#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const Fixed &other) { *this = other; }
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->_rawBits = other._rawBits;
    return *this;
}
Fixed::~Fixed() {}

Fixed::Fixed(const int value) {
    _rawBits = value << _fractionalBits;
}
Fixed::Fixed(const float value) {
    _rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

int Fixed::getRawBits(void) const { return _rawBits; }
void Fixed::setRawBits(int const raw) { _rawBits = raw; }

bool Fixed::operator>(const Fixed &other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed &other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed &other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed &other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed &other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed &other) const { return _rawBits != other._rawBits; }

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
    _rawBits++;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _rawBits++;
    return temp;
}
Fixed &Fixed::operator--() {
    _rawBits--;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _rawBits--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

