#pragma once

#include <set>

#include "receiver.hpp"

/// @file Short explanation about this file - container receiver declarations
/// @author Vladislav Antonov
/// @date 2025

///
/// @brief Implements multiple element storage.
/// Container stores multiple ordered unique elements
///
class ContainerReceiver : public Receiver {
 public:
  /// @throw std::exception Should not throw
  ~ContainerReceiver() override = default;

 private:
  /// @brief Create element in storage
  ///
  /// Method is private as it is meant to be accessed only by base interface
  /// @param aData Identifier of the created element
  /// @see Element
  /// @return True if element was successfully created
  bool create(std::string_view aData) override;

  /// @brief Read all elements in storage
  ///
  /// Method is private as it is meant to be accessed only by base interface
  /// @see Element
  /// @return List of element read
  std::vector<Element> read() override;

  /// @brief Update storage with element
  ///
  /// Method is private as it is meant to be accessed only by base interface
  /// @param aUpdated Element to update in storage
  /// @see Element
  /// @return True if element is successfully updated
  bool update(const Element& aUpdated) override;

  /// @brief Remove element from storage
  ///
  /// Method is private as it is meant to be accessed only by base interface
  /// @param aRemoved Element to remove from storage
  /// @see Element
  /// @return True if element is successfully removed
  bool remove(const Element& aRemoved) override;

  /// @brief Elements container
  std::set<Element> mContainer;
};