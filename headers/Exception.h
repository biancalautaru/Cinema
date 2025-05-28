#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
protected:
	std::string message;

public:
	Exception();
	explicit Exception(const std::string& message);

	const char* what() const noexcept override;
};

#endif
