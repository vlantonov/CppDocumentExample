#pragma once

///
/// @brief Interface of method for command execution
///
class Command {
 public:
  virtual ~Command() = default;

  virtual void execute() = 0;
};
