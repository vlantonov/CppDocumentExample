#pragma once

#include <string>
#include <string_view>

///
/// @brief Example element
///
/// Object to be used in commands.
/// Implements major operations and logs them.
/// @note There should be an empty line after brief tag
///
class Element {
 public:
  ///
  /// @brief Default constructor
  ///
  /// Default identifier is empty
  ///
  Element();

  ///
  /// @brief Constructor setting identifier
  ///
  /// By default single argument constructors should be explicit.
  /// @param aData Value of the identifier
  ///
  explicit Element(std::string_view aData);

  ///
  /// @brief Destructor 
  /// 
  /// Consider using the default one
  /// Should be defined if a class needs an explicit action at object destruction
  ~Element() noexcept;

  ///
  /// @brief Copy constructor
  ///
  /// Consider using the default.
  /// Should be consistent to copy assigment operator.
  /// @note Descritpion is on multiple line and appears as single paragraph.
  /// @param aOther Object to copy from
  Element(const Element& aOther);

  ///
  /// @brief Move constructor
  ///
  /// Consider using the default.
  /// Should be noexcept.
  /// Should be consistent to move assigment operator.
  /// @param aOther Object to move
  Element(Element&& aOther) noexcept;

  ///
  /// @brief Copy assignment operator
  ///
  /// Consider using the default.
  /// Should be consistent to copy constructor.
  /// @param aOther Object to copy from
  /// @return
  Element& operator=(const Element& aOther);

  ///
  /// @brief Move assignment operator
  ///
  /// Consider using the default.
  /// Should be noexcept.
  ///
  /// (Separated paragraph by empty line) Should be consistent to move constructor.
  /// @param aOther Object to move
  /// @return 
  Element& operator=(Element&& aOther) noexcept;

  ///
  /// @brief Define default comparison
  ///
  /// Spaceship operator is used:
  /// <a href="https://en.cppreference.com/w/cpp/language/default_comparisons">Default comparisons</a> 
  auto operator<=>(const Element&) const = default;

  ///
  /// @brief Print operator
  ///
  /// @param aOutputStream Stream to print the object
  /// @param aValue Object to be printed
  /// @note Although defined in class header it is in fact
  /// a separate function
  ///
  friend std::ostream& operator<<(std::ostream& aOutputStream,
                                  const Element& aValue) {
    constexpr std::string_view prefix{"Element{"};
    constexpr std::string_view suffix{"}"};
    aOutputStream << prefix << aValue.mData << suffix;
    return aOutputStream;
  }

 private:
  /// @brief Object identifier
  ///
  /// Without the comment the field would not be displayed.
  std::string mData;
};