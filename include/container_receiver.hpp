#pragma once

#include <set>

#include "receiver.hpp"

///
/// @brief Implements multiple element storage.
/// Container stores multiple ordered unique elements
///
class ContainerReceiver : public Receiver {
 public:
  ~ContainerReceiver() override = default;

 private:
  bool create(std::string_view aData) override;
  std::vector<Element> read() override;
  bool update(const Element& aUpdated) override;
  bool remove(const Element& aRemoved) override;

  /// @brief Elements container
  std::set<Element> mContainer;
};