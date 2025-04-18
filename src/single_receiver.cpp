#include "single_receiver.hpp"

bool SingleReceiver::create(std::string_view aData) {
  mStored.emplace(aData);
  return mStored.has_value();
}

std::vector<Element> SingleReceiver::read() {
  if (mStored) {
    return {*mStored};
  }

  return {};
}

///
/// This comment is written inside the source file.
/// Overrides the interface header comments.
///
bool SingleReceiver::update(const Element& aUpdated) {
  if (!mStored) {
    return false;
  }

  mStored = aUpdated;
  return mStored.has_value();
}

bool SingleReceiver::remove(const Element& aRemoved) {
  if (!mStored) {
    return true;
  }

  if (aRemoved != *mStored) {
    return false;
  }

  mStored.reset();

  return true;
}