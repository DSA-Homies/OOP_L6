#include "ScooterException.h"

using namespace Exception;

ScooterException::ScooterException(const string &message) {
    this->message = message;
}

const char *ScooterException::what() const noexcept {
    return this->message.c_str();
}
