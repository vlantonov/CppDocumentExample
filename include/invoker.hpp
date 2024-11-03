#pragma once

#include <memory>
#include <vector>

#include "command.hpp"

class Invoker {
 public:
  void addCommand(std::shared_ptr<Command> command);

  void executeCommands();

 private:
  std::vector<std::shared_ptr<Command>> commands;
};
