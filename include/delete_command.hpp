#pragma once

#include <memory>

#include "command.hpp"
#include "element.hpp"

class Receiver;

///
/// @brief Delete Command
/// Deletes an Element from storage
///
class DeleteCommand : public Command {
 public:
  DeleteCommand(std::weak_ptr<Receiver> aReceiver, Element aDeleteData);

  ~DeleteCommand() override = default;

 private:
  void execute() override;

  /// @brief Object to delegate complex data operations
  /// Commands can delegate to any methods of a receiver.
  /// @see Receiver
  std::weak_ptr<Receiver> mReceiver;

  /// @brief Context data
  /// Required for launching the receiver's methods.
  Element mDeleteData;
};
