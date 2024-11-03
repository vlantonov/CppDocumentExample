#include "container_receiver.hpp"

#include "element.hpp"

bool ContainerReceiver::create(std::string_view aData) {
  const auto [it, isCreated] = mContainer.emplace(aData);
  return isCreated;
}

std::vector<Element> ContainerReceiver::read() {
  return {mContainer.begin(), mContainer.end()};
}

bool ContainerReceiver::update(const Element& aUpdated) {
  auto it = mContainer.find(aUpdated);
  if (mContainer.end() == it) {
    return false;
  }

  mContainer.erase(it);
  mContainer.insert(aUpdated);

  return true;
}

bool ContainerReceiver::remove(const Element& aRemoved) {
  const auto erasedElements = mContainer.erase(aRemoved);
  return erasedElements > 0;
}