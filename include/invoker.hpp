#pragma once

#include <memory>
#include <vector>

#include "command.hpp"

///
/// @brief Sends requests to commands
/// Can be associated with one or several commands.
/// Does not depend on concrete command or receiver classes.
/// The request is passed to a receiver indirectly, by executing a command.
///
class Invoker {
 public:
  /// @brief Add command to be executed.
  /// The client code can parameterize by adding any commands.
  void addCommand(std::shared_ptr<Command> command);

  /// @brief Executes added commands
  /// @note After execution the list of the commands is cleared.
  void executeCommands();

 private:
  std::vector<std::shared_ptr<Command>> commands;
};
