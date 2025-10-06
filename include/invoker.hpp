#pragma once

#include <memory>
#include <vector>

#include "command.hpp"

/// @defgroup invoker_command Invokers
/// @brief Invoker implementations
/// @{

///
/// @brief Sends requests to commands
///
/// Can be associated with one or several commands.
/// Does not depend on concrete command or receiver classes.
/// The request is passed to a receiver indirectly, by executing a command.
/// @see Receiver , Command
///
class Invoker {
 public:
  ///
  /// @brief Add command to be executed.
  ///
  /// The client code can be parameterized by adding any commands.
  /// @param command Command to be added
  void addCommand(std::shared_ptr<Command> command);

  ///
  /// @brief Executes added commands
  ///
  /// The related methods of the commands are called
  /// @note After execution the list of the commands is cleared.
  void executeCommands();

 private:
  /// @brief List of commands to be executed
  std::vector<std::shared_ptr<Command>> commands;
};

/// @}