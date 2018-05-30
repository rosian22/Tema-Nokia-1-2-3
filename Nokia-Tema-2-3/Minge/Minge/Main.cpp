#include <vector>
#include <algorithm>

#include "Minge.hpp"

void afisareVector(std::vector<Minge>&);
void cautaMingiDupaNume(std::vector<Minge>&);
void stergeMingiDupaNume(std::vector<Minge>&);

int main()
{
	Minge m1("World Cup");
	m1.introducereMarca("Puma"); m1.introducereMarca("Nike");
	m1.introducereMarca("Addidas"); m1.introducereMarca("Reebok");
	m1.introducereMarca("Lacoste");
	m1.afiseazaMinge();

	Minge m2(m1);
	m2.afiseazaMinge();

	Minge m3("Ordem");
	m3.afiseazaMinge();
	m3 = m1;
	m3.afiseazaMinge();

	Minge moveMinge(m1);
	moveMinge.afiseazaMinge();
	Minge m4(std::move(moveMinge));
	m4.afiseazaMinge();

	Minge moveassgMinge(m1);
	moveassgMinge.afiseazaMinge();
	Minge m5("CR7");
	m5.afiseazaMinge();
	m5 = std::move(moveassgMinge);
	m5.afiseazaMinge();

	m2.setNumeMinge("Ordem");
	m3.setNumeMinge("CR7");
	m4.setNumeMinge("Magia");
	m5.setNumeMinge("Ordem");

	std::cout << "==============Initializare vector==============" << std::endl;
	std::vector<Minge> vectorMinge {m1, m2, m3, m4, m5};
	std::cout << "===============================================" << std::endl << std::endl;
	
	std::cout << "Cauta mingi dupa nume" << std::endl;
	cautaMingiDupaNume(vectorMinge);
	stergeMingiDupaNume(vectorMinge);
	std::cout << std::endl << "Afisare dupa stergerea mingilor" << std::endl;
	afisareVector(vectorMinge);

	std::cin.get();
}

void afisareVector(std::vector<Minge>& mingi)
{
	std::cout << "Afisare continut vector" << std::endl;
	for (std::vector<Minge>::iterator it = begin(mingi); it != end(mingi); ++it)
		it->afiseazaMinge();
}

void cautaMingiDupaNume(std::vector<Minge>& vectorMinge) 
{
	std::find_if(vectorMinge.begin(), vectorMinge.end(), [](Minge& minge)
	{
		if (minge.getNumeMinge() == "CR7")
		{
			minge.afiseazaMinge();
			return true;
		}
		else
			return false;
	}), vectorMinge.end();
}

void stergeMingiDupaNume(std::vector<Minge>& vectorMinge) 
{
	for (std::vector<Minge>::iterator it = begin(vectorMinge); it != end(vectorMinge); ++it)
	{
		vectorMinge.erase(std::remove_if(vectorMinge.begin(), vectorMinge.end(), [](Minge& minge)
		{
			return minge.getNumeMinge() == "Ordem";
		}), vectorMinge.end());
	}
}