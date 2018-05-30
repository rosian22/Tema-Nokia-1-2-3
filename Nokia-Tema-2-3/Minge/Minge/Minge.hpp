#ifndef MINGE_FILE_H_
#define MINGE_FILE_H_

#include <iostream>
#include <string>

const int NUMAR_INITIAL_MINGI = 5;

class Minge {
public:
	Minge() = default;
	Minge(std::string);
	Minge(const Minge&);
	Minge& operator=(const Minge&);
	Minge(Minge&&);
	Minge& operator=(Minge&&);
	virtual ~Minge();
	std::string getNumeMinge();
	int getNumarMingi();
	int getLocuriDisponibile();
	void setNumeMinge(std::string);
	void introducereMarca(std::string);
	void afiseazaMinge();
private:
	std::string numeMinge_;
	int numarMingi_;
	int locuriDisponibile_;
	std::string* marcaMingi_;

	void setNumarMingi(int);
	void setLocuriDisponibile(int);
};

#endif // !MINGE_FILE_H_
