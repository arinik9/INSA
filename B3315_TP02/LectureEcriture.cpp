#ifndef LECTUREECRITURE_H_
#define LECTUREECRITURE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct UnLog
{
	string extension;
	string cible_url; 
	string source_url;
	string aQuelHeure;
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
