#include <iostream>
#include <string>

class Contact{

  private:
    std::string name;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    unsigned int phoneNumber;

  public:
    Contact(void);
    ~Contact(void);

    bool setName(std::string name){
      if (name.length() == 0)
        return false;

      this->name = name;

      return true;
    }

    bool setLastName(std::string lastName){
      if (lastName.length() == 0)
        return false;

      this->lastName= lastName;

      return true;
    }

    bool setNickName(std::string nickName){
      if (nickName.length() == 0)
        return false;

      this->nickName = nickName;

      return true;
    }

    bool setDarkestSecret(std::string darkestSecret){
      if (darkestSecret.length() == 0)
        return false;

      this->darkestSecret= darkestSecret;

      return true;
    }

    bool setPhoneNumber(std::string phoneNumber){
      long long int longPhoneNumber = std::stoll(phoneNumber);
      if (longPhoneNumber <= 0 || longPhoneNumber > 999999999999)
      {
        std::cout << "Invalid phone number" << std::endl;
        std::cout << "Valid phone number must be between 0 and 999,999,999,999" << std::endl;
        return false;
      }
      return true;
    }
};
