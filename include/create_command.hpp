#pragma once

#include <memory>

#include "command.hpp"

class Receiver;

class CreateCommand : public Command {
 public:
  CreateCommand(std::weak_ptr<Receiver> aReceiver, std::string_view aData);

  ~CreateCommand() override = default;

 private:
  void execute() override;

  std::weak_ptr<Receiver> mReceiver;
  std::string mData;
};
