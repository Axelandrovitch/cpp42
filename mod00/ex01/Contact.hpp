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

    void setName(const std::string& name);
    void setLastName(const std::string& lastName);
    void setNickName(const std::string& nickName);
    void setDarkestSecret(const std::string& darkestSecret);
    void setPhoneNumber(const std::string& phoneNumber);

    std::string getName();
    std::string getLastName();
    std::string getNickName();
    std::string getDarkestSecret();
    std::string getPhoneNumber();
};
