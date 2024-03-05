#pragma once

#include "application.h"
#include "asio/ip/udp.hpp"
#include "net/message_handler.h"
#include "net/server.h"
#include "types.h"
#include "util/err.h"

class ServerApp : public Application {
public:
  ServerApp(u32 port);

public:
  // Methods inherited from Application
  Err run() override;
  void shutdown() override;

private:
  void handle_message(const Net::Message &message);

private:
  std::unique_ptr<Net::Server> server;
  bool running = false;
};
