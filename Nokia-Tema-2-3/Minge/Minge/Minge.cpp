#include "Minge.hpp"

Minge::Minge(std::string numeMinge) :
	numeMinge_(numeMinge),
	numarMingi_(NUMAR_INITIAL_MINGI),
	locuriDisponibile_(0),
	marcaMingi_(new std::string[numarMingi_])
{
	std::cout << "Explicit Constructor" << std::endl;
}

Minge::Minge(const Minge& minge) :
	numeMinge_(minge.numeMinge_),
	numarMingi_(minge.numarMingi_),
	locuriDisponibile_(minge.locuriDisponibile_),
	marcaMingi_(new std::string[minge.numarMingi_])
{
	std::cout << "Copy constructor" << std::endl;

	for (int i = 0; i < locuriDisponibile_; ++i)
		marcaMingi_[i] = minge.marcaMingi_[i];
}

Minge& Minge::operator=(const Minge& minge)
{
	std::cout << "Overload Assignment Operator" << std::endl;

	if (this == &minge)
		return *this;

	this->numeMinge_ = minge.numeMinge_;
	this->numarMingi_ = minge.numarMingi_;
	this->locuriDisponibile_ = minge.locuriDisponibile_;

	for (int i = 0; i < locuriDisponibile_; i++)
		this->marcaMingi_[i] = minge.marcaMingi_[i];

	return *this;
}

Minge::Minge(Minge&& minge) :
	numeMinge_(minge.numeMinge_),
	numarMingi_(minge.numarMingi_),
	locuriDisponibile_(minge.locuriDisponibile_),
	marcaMingi_(minge.marcaMingi_)
{
	std::cout << "Move constructor" << std::endl;

	minge.numeMinge_ = "\0";
	minge.numarMingi_ = 0;
	minge.locuriDisponibile_ = 0;
	minge.marcaMingi_ = nullptr;
}

Minge& Minge::operator=(Minge&& minge)
{
	std::cout << "Move Assignment Operator" << std::endl;

	if (this != &minge)
	{
		delete[] marcaMingi_;

		this->numeMinge_ = minge.numeMinge_;
		this->numarMingi_ = minge.numarMingi_;
		this->locuriDisponibile_ = minge.locuriDisponibile_;
		this->marcaMingi_ = minge.marcaMingi_;

		minge.numeMinge_ = "\0";
		minge.numarMingi_ = 0;
		minge.locuriDisponibile_ = 0;
		minge.marcaMingi_ = nullptr;
	}

	return *this;
}

Minge::~Minge()
{
	delete[] marcaMingi_;
}

std::string Minge::getNumeMinge()
{
	return numeMinge_;
}

int Minge::getNumarMingi()
{
	return numarMingi_;
}

int Minge::getLocuriDisponibile()
{
	return locuriDisponibile_;
}

void Minge::setNumeMinge(std::string nume)
{
	this->numeMinge_ = nume;
}

void Minge::introducereMarca(std::string marcaMinge)
{
	if (this->locuriDisponibile_ == this->numarMingi_)
		std::cout << "Stocul este plin." << std::endl;
	else 
	{
		this->marcaMingi_[locuriDisponibile_] = marcaMinge;
		++locuriDisponibile_;
	}
}

void Minge::afiseazaMinge()
{
	std::cout << "==============================================" << std::endl <<
		"Nume: " << numeMinge_ << std::endl <<
		"Numar mingi: " << numarMingi_ << std::endl <<
		"Locuri disponibile: " << locuriDisponibile_ << std::endl;
	for (int i = 0; i < numarMingi_; ++i)
		std::cout << marcaMingi_[i] << " | ";

	std::cout << std::endl << "==============================================" << std::endl << std::endl;
}

void Minge::setNumarMingi(int numarMingi)
{
	numarMingi_ = numarMingi;
}

void Minge::setLocuriDisponibile(int locuriDisponibile)
{
	locuriDisponibile_ = locuriDisponibile;
}
