#pragma once

#include <memory>

#include "command.hpp"
#include "element.hpp"

class Receiver;

class UpdateCommand : public Command {
 public:
  UpdateCommand(std::weak_ptr<Receiver> aReceiver, Element aUpdateData);

  ~UpdateCommand() override = default;

 private:
  void execute() override;

  std::weak_ptr<Receiver> mReceiver;
  Element mUpdateData;
};
