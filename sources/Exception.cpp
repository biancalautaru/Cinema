#include "../headers/Exception.h"

Exception::Exception() {
}

Exception::~Exception() {
}

Exception::Exception(const std::string& message):
	message(message) {
}

const char* Exception::what() const noexcept {
	return message.c_str();
}
