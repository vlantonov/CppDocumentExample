#pragma once

#include <memory>
#include <vector>

#include "command.hpp"

class Receiver;
class Element;

///
/// @brief Read Command
/// Implements additional method to read stored Elements
///
class ReadCommand : public Command {
 public:
  ReadCommand(std::weak_ptr<Receiver> aReceiver);

  ~ReadCommand() override = default;

  std::vector<Element> getReads() const { return mReads; }

 private:
  void execute() override;

  /// @brief Object to delegate complex data operations
  /// Commands can delegate to any methods of a receiver.
  /// @see Receiver
  std::weak_ptr<Receiver> mReceiver;

  /// @brief Context data
  /// Required for launching the receiver's methods.
  std::vector<Element> mReads;
};
