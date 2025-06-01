#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

/**
 * @class Exception
 * @brief Base custom exception class that extends std::exception.
 *
 * The Exception class provides a custom exception type with a message string.
 * It can be inherited to define more specific exceptions across the application.
 */
class Exception : public std::exception {
protected:
	std::string message;

public:
	Exception();

	virtual ~Exception();

	explicit Exception(const std::string& message);

	const char* what() const noexcept override;
};

#endif
