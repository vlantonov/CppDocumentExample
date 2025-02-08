#pragma once

#include <string_view>
#include <vector>

class Element;

///
/// @brief Interface to business logic
///
/// Methods are to perform all kinds of operations,
/// associated with carrying out a request.
///
/// Specific implementations contain some important business logic.
/// It is the knowledge to perform all kinds of operations,
/// associated with carrying out a request.
///
/// In this case the Repository Pattern methods are presented
///
class Receiver {
 public:
  virtual ~Receiver() = default;

  /// @brief Create action
  /// @param aData Identifier of an Element to be created
  /// @see Element
  /// @return True if element is successfully created
  virtual bool create(std::string_view aData) = 0;

  /// @brief Read action
  /// @return Read elements
  virtual std::vector<Element> read() = 0;

  /// @brief Update action
  /// @param aUpdated Element to be updated
  /// @return True if element is successfully updated
  virtual bool update(const Element& aUpdated) = 0;

  /// @brief Remove action
  /// @param aRemoved Element to be removed
  /// @return True if element is successfully removed
  virtual bool remove(const Element& aRemoved) = 0;
};
