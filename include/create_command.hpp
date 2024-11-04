#pragma once

#include <memory>

#include "command.hpp"

class Receiver;

///
/// @brief Create Command
/// Creates an Element in storage
///
class CreateCommand : public Command {
 public:
  CreateCommand(std::weak_ptr<Receiver> aReceiver, std::string_view aData);

  ~CreateCommand() override = default;

 private:
  void execute() override;

  /// @brief Object to delegate complex data operations
  /// Commands can delegate to any methods of a receiver.
  /// @see Receiver
  std::weak_ptr<Receiver> mReceiver;

  /// @brief Context data
  /// Required for launching the receiver's methods.
  std::string mData;
};
