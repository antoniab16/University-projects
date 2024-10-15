#include <exception>
#include <iostream>

class Exceptions : public std::exception{
private:
    std::string message;

public:
    Exceptions(std::string msg);
    const std::string& get_message() const;
};