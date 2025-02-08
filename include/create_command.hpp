#pragma once

#include <memory>

#include "command.hpp"

class Receiver;

///
/// @brief Create Command
///
/// Creates an element in storage.
///
/// Complex commands can accept one or several receiver objects along with any
/// context data via the constructor.
/// @see Element
///
class CreateCommand : public Command {
 public:
  /// @brief Create Command constructor
  /// @param aReceiver Object to delegate execution
  /// @param aData Context data for the receiver
  CreateCommand(std::weak_ptr<Receiver> aReceiver, std::string_view aData);

  ///
  /// @brief Overridden destructor.
  ///
  /// Override base destructor on implementation.
  /// Default destructor may be used as well.
  ~CreateCommand() override = default;

 private:
  /// @brief Specific action to be executed
  ///
  /// Overrides description in interface
  void execute() override;

  ///
  /// @brief Object to delegate complex data operations
  ///
  /// Commands can delegate to any methods of a receiver.
  /// @see Receiver
  std::weak_ptr<Receiver> mReceiver;

  ///
  /// @brief Context data
  ///
  /// Required for launching the receiver's methods.
  std::string mData;
};
