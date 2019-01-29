#include "UserService.hpp"

UserService::UserService (UserDB& userDB) : AbstractService("/user"),
    userDB(userDB) {
    
}

HttpStatus UserService::get (Json::Value& out, int id) const {
    //implémentation de la fonction GET : renvoit les infos de l'utilisateur avec l'id d'entrée
    const User* user = userDB.getUser(id) ; 
    if(!user) 
		throw ServiceException(HttpStatus::NOT_FOUND, "Invalid user ID") ; 
    out["name"] = user->name ; 
    out["type"] = user->age ; 
    return HttpStatus::OK ; 
}

HttpStatus UserService::post (const Json::Value& in, int id) {
	//modifie les informations d'un utilisateur
    const User* user = userDB.getUser(id) ; 
    if(!user) 
    {
		throw ServiceException(HttpStatus::NOT_FOUND, "Utilisateur ID inconnu") ; 
	}
	unique_ptr<User> newUser (new User(*user)) ; 
	if(in.isMember("name"))
	{
		newUser->name = in["name"].asString() ; 
	}
	if(in.isMember("type"))
	{
		newUser->age = in["type"].asInt() ; 
	}
	userDB.setUser(id, std::move(newUser)) ; 
	return HttpStatus::NO_CONTENT ; 
}

HttpStatus UserService::put (Json::Value& out,const Json::Value& in) 
{
    //ajoute un utilisateur dans la base 
    string name = in["name"].asString() ; 
    int type = in["type"].asInt() ; 
    out["id"] = userDB.addUser(make_unique<User>(name, type)) ; 
    return HttpStatus::CREATED ; 
}

HttpStatus UserService::remove (int id) {
   //supprime un utilisateur dans la liste.
   const User* user = userDB.getUser(id) ; 
   if(!user) 
   {
	   throw ServiceException(HttpStatus::NOT_FOUND, "ID du joueur invalide") ; 
   }
   userDB.removeUser(id) ; 
   return HttpStatus::NO_CONTENT ; 
}
