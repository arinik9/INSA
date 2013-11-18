#include "Graph.h"


void Graph::Ajouter(string aQuelHeure,string cible_url,string extension,string source_url)
{
	std::string s = g.aQuelHeure;
//	     int hour = atoi(s.c_str());   //string'i int'e ceviriyo

	//find() metodunun yaptigi, asagidakiyle ayni, iterator ile bakiyo icerigine
	/*for (Graph::Referer::iterator it = g.analyse.begin(); it != g.analyse.end(); ++it){
			if(it->first == g.source_url){  .....  }     }*/
				if(analyse.find(g.source_url) == analyse.end()) // yani key'i bulamadiysa
				{

				    //direkt Ajouter yapariz
				//	analyse.insert(std::pair(g.source_url, std::pair(g.cible_url,g.nbHit_struct(hour,g.extension)) ) );
					// insert metodunu duwgun kullanamiyor muyuz?
				}

			else{//"source var ama cible de var mi" diye bakioruz

					if (analyse.find(g.source_url)->second.find(g.cible_url) == analyse.find(g.source_url)->second.end())
					{
						// yani içteki map'te key'i bulamadiysa, end()'e gider
				//		analyse.find(g.source_url)->second.insert(std::pair(g.cible_url,g.nbHit_struct(hour,g.extension)));
					}
				}
}


Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
