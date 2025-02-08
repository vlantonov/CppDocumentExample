#include "element.hpp"

#include <iostream>
#include <utility>

///
/// This comment is written inside the source file.
/// Appears as separate paragprah from header comments.
///
Element::Element() { std::cout << "Element default ctor " << this << "\n"; }

Element::Element(std::string_view aData) : mData{std::move(aData)} {
  std::cout << "Element arg ctor " << this << " " << mData << '\n';
}

Element::~Element() {
  std::cout << "~Element " << this << " " << mData << '\n';
}

Element::Element(const Element& aRhs) : mData{aRhs.mData} {
  std::cout << "Element copy ctor " << this << " " << mData << '\n';
}

Element::Element(Element&& aRhs) noexcept
    : mData{std::move(aRhs.mData)}  // In case mData has no move operations
                                    // mData{std::exchange(aRhs.mData, {})}
{
  std::cout << "Element move ctor " << this << " " << mData << '\n';
}

Element& Element::operator=(const Element& aRhs) {
  if (this != &aRhs) {
    mData = aRhs.mData;
  }

  // copy-and-swap: strong exception safety guarantee
  // Element tmp{aRhs};
  // std::swap(*this, tmp);

  std::cout << "Element copy = " << this << " " << mData << '\n';
  return *this;
}

Element& Element::operator=(Element&& aRhs) noexcept {
  if (this != &aRhs) {
    mData = std::move(aRhs.mData);
  }

  // In case mData has no move operations
  // mData = std::exchange(aRhs.mData, {});

  std::cout << "Element move = " << this << " " << mData << '\n';
  return *this;
}