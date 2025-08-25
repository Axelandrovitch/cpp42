#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string name;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;

public:
    Contact();
    ~Contact();
    Contact(const Contact& other);
    Contact& operator=(const Contact& other);

    bool setName(const std::string& name);
    bool setLastName(const std::string& lastName);
    bool setNickName(const std::string& nickName);
    bool setDarkestSecret(const std::string& darkestSecret);
    bool setPhoneNumber(const std::string& phoneNumber);

    std::string getName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getDarkestSecret() const;
    std::string getPhoneNumber() const;
};

#endif

