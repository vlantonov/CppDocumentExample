#pragma once

#include <optional>

#include "element.hpp"
#include "receiver.hpp"

///
/// @brief Implements single element storage.
///
class SingleReceiver : public Receiver {
 public:
  ~SingleReceiver() override = default;

 private:
  bool create(std::string_view aData) override;
  std::vector<Element> read() override;
  bool update(const Element& aUpdated) override;
  bool remove(const Element& aRemoved) override;

  /// @brief Stored element
  std::optional<Element> mStored;
};