#pragma once

#include <memory>
#include <vector>

#include "command.hpp"

class Receiver;
class Element;

class ReadCommand : public Command {
 public:
  ReadCommand(std::weak_ptr<Receiver> aReceiver);

  ~ReadCommand() override = default;

  std::vector<Element> getReads() const { return mReads; }

 private:
  void execute() override;

  std::weak_ptr<Receiver> mReceiver;
  std::vector<Element> mReads;
};
