// Generated by dia2code
#ifndef CLIENT__NETWORKCLIENT__H
#define CLIENT__NETWORKCLIENT__H

#include <string>
#include <memory>
#include <json/json.h>

namespace ai {
  class AI;
}

#include "ai/AI.h"

namespace client {

  /// class NetworkClient - 
  class NetworkClient {
    // Attributes
  private:
    std::string url;
    int port;
    int character;
    std::unique_ptr<ai::AI> user_ai;
    // Operations
  public:
    NetworkClient (const std::string& url, int port, int character);
    std::string getGameStatus ();
    bool getServerCommands (Json::Value& out);
    void putServerCommands (engine::Commande* command);
    void run ();
    // Setters and Getters
  };

};

#endif
