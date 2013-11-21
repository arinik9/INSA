#include "LectureEcriture.h"

UnLog LectureEcriture::ProchainLog()
{
		UnLog logEnCours;
		string s="",c="";
		std::size_t foundPoint;

		getline(myFile,s,':');
		getline(myFile,logEnCours.aQuelHeure,':');

		getline(myFile,s,'"');
		getline(myFile,s,' ');

		getline(myFile,logEnCours.cible_url,' ');  // f="html" mesela
		foundPoint=logEnCours.cible_url.find('.');
		  if (foundPoint != string::npos){
		  unsigned found=logEnCours.cible_url.find_last_of('.');
			c=logEnCours.cible_url.substr(found+1);
		  }
			  if (logEnCours.cible_url.find("?") !=std::string::npos){
					c=c.substr(0,3);
					  }

		transform(c.begin(),c.end(),c.begin(),::tolower);
		logEnCours.extension=c;
		//cout << logEnCours.extension <<endl;,

		getline(myFile,s,'"');
		getline(myFile,s,'"');
		getline(myFile,logEnCours.source_url,'"');

		getline(myFile,s,'\n');
		return logEnCours;
}




bool LectureEcriture:: EstFini()
{
return(myFile.eof());
}

LectureEcriture::LectureEcriture(string nomfic):myFile(nomfic.c_str()) {
	// TODO Auto-generated constructor stub
}

LectureEcriture::~LectureEcriture() {
	// TODO Auto-generated destructor stub
}
