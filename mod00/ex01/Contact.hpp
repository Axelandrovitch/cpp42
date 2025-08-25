#include <string>

class Contact{

  private:
    std::string name;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;

  public:
    Contact(void);
    ~Contact(void);

    bool setName(const std::string& name);
    bool setLastName(const std::string& lastName);
    bool setNickName(const std::string& nickName);
    bool setDarkestSecret(const std::string& darkestSecret);
    bool setPhoneNumber(const std::string& phoneNumber);

    std::string getName();
    std::string getLastName();
    std::string getNickName();
    std::string getDarkestSecret();
    std::string getPhoneNumber();
};
