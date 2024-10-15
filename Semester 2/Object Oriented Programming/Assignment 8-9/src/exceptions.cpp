#include "exceptions.h"

Exceptions::Exceptions(std::string msg) : std::exception(), message{std::move(msg)} {}

const std::string &Exceptions::get_message() const {
    return this->message;
}
