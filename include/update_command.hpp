#pragma once

#include <memory>

#include "command.hpp"
#include "element.hpp"

class Receiver;

///
/// @brief Update Command
/// Implements additional method to update stored Elements
///
class UpdateCommand : public Command {
 public:
  /// @brief Update Command constructor
  /// @param aReceiver Object to delegate execution
  /// @param aUpdateData Context data for the receiver - element to be updated
  UpdateCommand(std::weak_ptr<Receiver> aReceiver, Element aUpdateData);

  ~UpdateCommand() override = default;

 private:
  void execute() override;

  /// @brief Object to delegate complex data operations
  ///
  /// Commands can delegate to any methods of a receiver.
  /// @see Receiver
  std::weak_ptr<Receiver> mReceiver;

  /// @brief Context data
  ///
  /// Required for launching the receiver's methods.
  Element mUpdateData;
};
