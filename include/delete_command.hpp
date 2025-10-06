#pragma once

#include <memory>

#include "command.hpp"
#include "element.hpp"

class Receiver;

/// @addtogroup group_command
/// @{

///
/// @brief Delete Command
///
/// Deletes an element from storage
///
class DeleteCommand : public Command {
 public:
  /// @brief Delete Command constructor
  /// @param aReceiver Object to delegate execution
  /// @param aDeleteData Context data for the receiver - element to be deleted
  DeleteCommand(std::weak_ptr<Receiver> aReceiver, Element aDeleteData);

  ~DeleteCommand() override = default;

 private:
  void execute() override;

  /// @brief Object to delegate complex data operations
  ///
  /// Commands can delegate to any methods of a receiver.
  /// @see Receiver
  std::weak_ptr<Receiver> mReceiver;

  ///
  /// @brief Context data
  ///
  /// Required for launching the receiver's methods.
  /// @see Element
  Element mDeleteData;
};

/// @}
