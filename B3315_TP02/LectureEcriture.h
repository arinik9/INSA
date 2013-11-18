#ifndef LECTUREECRITURE_H_
#define LECTUREECRITURE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct UnLog
{
	string extension, cible_url, source_url, aQuelHeure;
};

class LectureEcriture {
private:
	ifstream myFile;
public:

	UnLog ProchainLog();
	LectureEcriture(string nomfic);
	bool EstFini();
	virtual ~LectureEcriture();

};

#endif /* LECTUREECRITURE_H_ */
