#include "container_receiver.hpp"

#include "element.hpp"

/// @file Short explanation about this file - container receiver definitions
/// @author Vladislav Antonov
/// @date 2025

///
/// This comment is written inside the source file.
/// The interface comments are overwritten in implementation.
/// Appears as separate paragraph after header comments.
///
bool ContainerReceiver::create(std::string_view aData) {
  const auto [it, isCreated] = mContainer.emplace(aData);
  /// This comment is inside the source of the method.
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