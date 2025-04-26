#include "read_command.hpp"

#include <iostream>

#include "element.hpp"
#include "receiver.hpp"

ReadCommand::ReadCommand(std::weak_ptr<Receiver> aReceiver)
    : mReceiver{std::move(aReceiver)} {}

void ReadCommand::execute() {
  std::cout << "Execute ReadCommand\n";

  if (auto receiver = mReceiver.lock()) {
    mReads = receiver->read();
    std::cout << "ReadCommand execution result size: " << mReads.size() << '\n';
  }
}

std::vector<Element> ReadCommand::getReads() const { return mReads; }