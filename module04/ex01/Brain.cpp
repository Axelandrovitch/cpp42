#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain copy constructor called\n";
  *this = other;
}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < 100; ++i) {
      _ideas[i] = other._ideas[i];
    }
  }
  std::cout << "Brain assigment operator called\n";
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain deconstructor called\n";
}

void Brain::setIdea(int i, const std::string& idea) {
  if (i <= 0 && i < 100) {
    _ideas[i] = idea;
  }
}

std::string Brain::getIdea(int i) const {
  if (i <= 0 && i < 100) {
    return _ideas[i];
  }
  return "";
}

