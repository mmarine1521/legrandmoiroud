#include "ServicesManager.hpp"

using namespace std;
//using namespace server ; 

void ServicesManager::registerService(unique_ptr<AbstractService> service) 
{
   services.push_back(std::move(service)) ;  
   //ajoute un service à la liste de service. 
}

AbstractService* ServicesManager::findService(const string& url) const 
{
    /*renvoie l'adresse d'un service en fonction de l'url, sinon nullptr ; 
     on considère qu'un service correspond à une URL si son motif (pattern)
     correspond au dossier désigné par l'url.*/
    
    for (auto& service : services) 
    {
		const string& pattern(service->getPattern()) ;
		 
		if (url.find(pattern)!=0)
			
			return service.get() ; 
			
		if(url.size()>pattern.size() && url[pattern.size()] != '/')
			
			return service.get() ; 
			
	} 
	return nullptr ; 

}

HttpStatus ServicesManager::queryService (string& out, const string& in, const string& url, const string& method) 
{ 
    /*la méthode utilise ServicesManager::findService pour trouver le service demandé
     * puis utilise l'une des méthodes de l'interface AbstractService (get, post, put
     * et remove) pour exécuter le service */
    AbstractService* service = ServicesManager::findService(url) ; 
    std::cout << "entrée query service  " << url << std::endl ; 
    
    if (!service) 
    {
		
		throw ServiceException(HttpStatus::NOT_FOUND, "Service "+url+"non trouvé") ; 
	}
    
    const string& pattern(service->getPattern()) ;
    //recherche d'un éventuel ID /mon/service/<id> et traitement des erreurs 
    int id = 0 ; 
    if(url.size()>pattern.size())
    {
		string fin_url = url.substr(pattern.size()) ;//renvoie l'url à partir de la position 'taille d'un pattern' jusqu'à la fin  
		
		if(fin_url[0] != '/') 
		{
			throw ServiceException(HttpStatus::BAD_REQUEST, "Url malformée (forme attendue: <service>/<nombre>)");
		}
		fin_url=fin_url.substr(1) ; //on enlève le '/' si il est présent 
		if(fin_url.empty()) //si la suite est vide
		{
			throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
		}
		
		try{
			size_t position = 0 ; 
			id = stoi(fin_url, &position) ; //stoi : conversion en int 
			if(position!=fin_url.size())
			{
				throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+fin_url+"' n'est pas un nombre");
			}
		}
		catch(...) 
		{
			throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+fin_url+"' n'est pas un nombre");
		}
	}
		
	if(method == "GET") //renvoyer les infos d'un user à partir de son ID. 
	{
		cerr<<"Requête GET" << pattern << " avec id =" << id << endl ; 
		Json::Value jsonOut ; 
		HttpStatus status = service ->get(jsonOut, id) ; 
		out = jsonOut.toStyledString() ; //converti l'objet jsonOut en string
		return status ; 
	}	
	
	if(method == "POST") //modifie les informations d'un utilisateur existant	
	{
		cerr<< "Requête POST" << pattern << "avec id=" << id << endl ; 
		Json::Value jsonIn ; 
		Json::Reader reader ; 
		//on parse l'argument in pour former un objet JSON, on utilise reader avec la méthode parse. 
		if(!reader.parse(in, jsonIn))
		{
			throw ServiceException(HttpStatus::BAD_REQUEST, "Données invalides: "+reader.getFormattedErrorMessages()) ; 
		}
		return service->post(jsonIn, id) ;
	}  
	if(method == "PUT") //ajouter un utilisateur existant
	{
		cerr<< "Requête PUT" << pattern << " avec contenu: " << in <<endl ; 
		Json::Value jsonIn ; 
		Json::Reader reader ; 
		if(!reader.parse(in, jsonIn))
		{
			throw ServiceException(HttpStatus::BAD_REQUEST, "Données invalides: "+reader.getFormattedErrorMessages()) ; 
		}
		Json::Value jsonOut;
		HttpStatus status = service->put(jsonOut, jsonIn) ; 
		out = jsonOut.toStyledString() ; //conversion en string 
		return status ; 
	}
	if(method == "DELETE") 
	{
		cerr<< "Requête DELETE" << endl ; 
		return service-> remove(id) ; 
	}
} 
