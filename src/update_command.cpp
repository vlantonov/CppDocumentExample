#include "update_command.hpp"

#include <iostream>

#include "receiver.hpp"

UpdateCommand::UpdateCommand(std::weak_ptr<Receiver> aReceiver,
                             Element aUpdateData)
    : mReceiver{std::move(aReceiver)}, mUpdateData{std::move(aUpdateData)} {}

void UpdateCommand::execute() {
  std::cout << "Execute UpdateCommand\n";

  if (auto receiver = mReceiver.lock()) {
    const auto result = receiver->update(mUpdateData);
    std::cout << "UpdateCommand execution result: " << std::boolalpha << result
              << '\n';
  }
}