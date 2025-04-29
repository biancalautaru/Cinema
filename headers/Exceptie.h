#ifndef EXCEPTIE_H
#define EXCEPTIE_H

#include <exception>
#include <string>

class Exceptie : public std::exception {
private:
	std::string mesaj;

public:
	Exceptie();
	explicit Exceptie(const std::string& mesaj);

	virtual const char* what() const noexcept override;
};

#endif
