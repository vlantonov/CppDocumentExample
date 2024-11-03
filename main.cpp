#include <iostream>
#include <memory>

#include "container_receiver.hpp"
#include "create_command.hpp"
#include "delete_command.hpp"
#include "element.hpp"
#include "invoker.hpp"
#include "read_command.hpp"
#include "single_receiver.hpp"
#include "update_command.hpp"

int main() {
  const auto firstId = "first";
  const auto secondId = "second";
  const auto thirdId = "third";

  std::cout << "Create elements\n";
  Element firstElement{firstId};
  Element secondElement{secondId};

  std::cout << "Create receivers\n";
  auto firstReceiver = std::make_shared<SingleReceiver>();
  auto secondReceiver = std::make_shared<ContainerReceiver>();

  {
    std::cout << "SingleReceiver start\n";

    auto firstCommand = std::make_shared<CreateCommand>(firstReceiver, firstId);
    auto secondCommand =
        std::make_shared<CreateCommand>(firstReceiver, thirdId);
    auto thirdCommand = std::make_shared<ReadCommand>(firstReceiver);
    auto fourthCommand =
        std::make_shared<UpdateCommand>(firstReceiver, secondElement);
    auto fifthCommand =
        std::make_shared<DeleteCommand>(firstReceiver, secondElement);

    Invoker invoker;
    invoker.addCommand(firstCommand);
    invoker.addCommand(secondCommand);
    invoker.addCommand(thirdCommand);
    invoker.addCommand(fourthCommand);
    invoker.addCommand(fifthCommand);

    invoker.executeCommands();

    std::cout << "SingleReceiver end\n";
  }

  {
    std::cout << "ContainerReceiver start\n";

    auto firstCommand =
        std::make_shared<CreateCommand>(secondReceiver, firstId);
    auto secondCommand =
        std::make_shared<CreateCommand>(secondReceiver, thirdId);
    auto thirdCommand = std::make_shared<ReadCommand>(secondReceiver);
    auto fourthCommand =
        std::make_shared<UpdateCommand>(secondReceiver, secondElement);
    auto fifthCommand =
        std::make_shared<DeleteCommand>(secondReceiver, secondElement);

    Invoker invoker;
    invoker.addCommand(firstCommand);
    invoker.addCommand(secondCommand);
    invoker.addCommand(thirdCommand);
    invoker.addCommand(fourthCommand);
    invoker.addCommand(fifthCommand);

    invoker.executeCommands();

    std::cout << "ContainerReceiver end\n";
  }

  std::cout << "Done\n";
  return 0;
}
