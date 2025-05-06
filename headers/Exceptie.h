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

	const char* what() const noexcept override;
};

class OptiuneInexistenta : public Exceptie {
public:
	OptiuneInexistenta();
	explicit OptiuneInexistenta(const std::string& mesaj);
};

class InputGresit : public Exceptie {
public:
	InputGresit();
	explicit InputGresit(const std::string& mesaj);
};

class LocOcupat : public Exceptie {
public:
	LocOcupat();
	explicit LocOcupat(const std::string& mesaj);
};

class ProdusInexistent : public Exceptie {
public:
	ProdusInexistent();
	explicit ProdusInexistent(const std::string& mesaj);
};

#endif
