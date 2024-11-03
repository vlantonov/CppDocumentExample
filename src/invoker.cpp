#include "invoker.hpp"

#include <iostream>

void Invoker::addCommand(std::shared_ptr<Command> command) {
  commands.emplace_back(std::move(command));
}

void Invoker::executeCommands() {
  std::cout << "Execute Commands\n";

  for (auto command : commands) {
    command->execute();
  }

  commands.clear();
}
