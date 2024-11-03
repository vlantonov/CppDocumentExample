#include "delete_command.hpp"

#include <iostream>

#include "receiver.hpp"

DeleteCommand::DeleteCommand(std::weak_ptr<Receiver> aReceiver,
                             Element aDeleteData)
    : mReceiver{std::move(aReceiver)}, mDeleteData{std::move(aDeleteData)} {}

void DeleteCommand::execute() {
  std::cout << "Execute DeleteCommand\n";

  if (auto receiver = mReceiver.lock()) {
    const auto result = receiver->update(mDeleteData);
    std::cout << "DeleteCommand execution result: " << std::boolalpha << result
              << '\n';
  }
}