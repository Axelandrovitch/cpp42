#include "Contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    int count;
    int oldest;

  public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact();
    void searchContact() const;
    void displayContacts() const;
};
