#pragma once

///
/// @brief Interface of method for command execution
///
/// Decouples the object that invokes the operation
/// from the one that knows how to perform it. Holds:
///
/// * An object
///
/// * A method to be applied to the object
///
/// * The arguments to be passed when the method is applied.
///
/// Commands can delegate to any methods of a receiver.
/// Command normally specifies a sender-receiver connection with a subclass.
/// @see Receiver
class Command {
 public:
  /// @brief Interface destructor
  ///
  /// The destructor of a base class should be virtual
  /// to prevent memory leak of derived class object
  /// when destroyed via base class pointer
  virtual ~Command() = default;

  /// @brief Action to be executed
  ///
  /// Calls action on the receiver
  /// @see Receiver
  /// @note This description will be shown in all derived classes
  /// unless overridden
  virtual void execute() = 0;
};
