#include "create_command.hpp"

#include <iostream>

#include "receiver.hpp"

CreateCommand::CreateCommand(std::weak_ptr<Receiver> aReceiver,
                             std::string_view aData)
    : mReceiver{std::move(aReceiver)}, mData{std::move(aData)} {}

void CreateCommand::execute() {
  std::cout << "Execute CreateCommand\n";

  if (auto receiver = mReceiver.lock()) {
    const auto result = receiver->create(mData);
    std::cout << "CreateCommand execution result: " << std::boolalpha << result
              << '\n';
  }
}