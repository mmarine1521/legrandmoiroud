// Generated by dia2code
#ifndef SERVER__USERDB__H
#define SERVER__USERDB__H

#include <json/json.h>

namespace server {
  class User;
}

#include "User.h"

namespace server {

  /// class UserDB - 
  class UserDB {
    // Associations
    // Attributes
  protected:
    int idseq;
    map<int,unique_ptr<User> > users;
    // Operations
  public:
    UserDB ();
    const Player* getUser (int id) const;
    int addUser (unique_ptr<Player> );
    void setUser (int id, unique_ptr<User> user);
    void removeUser (int id);
    Json::Value getAllUser ();
    // Setters and Getters
    int getIdseq() const;
    void setIdseq(int idseq);
    const map<int,unique_ptr<User> >& getUsers() const;
    void setUsers(const map<int,unique_ptr<User> >& users);
  };

};

#endif
