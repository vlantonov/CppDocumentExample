#pragma once

#include <memory>

#include "command.hpp"
#include "element.hpp"

class Receiver;

class DeleteCommand : public Command {
 public:
  DeleteCommand(std::weak_ptr<Receiver> aReceiver, Element aDeleteData);

  ~DeleteCommand() override = default;

 private:
  void execute() override;

  std::weak_ptr<Receiver> mReceiver;
  Element mDeleteData;
};
