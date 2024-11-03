#pragma once

#include <string_view>
#include <vector>

class Element;

class Receiver {
 public:
  virtual ~Receiver() = default;

  // actions
  virtual bool create(std::string_view aData) = 0;
  virtual std::vector<Element> read() = 0;
  virtual bool update(const Element& aUpdated) = 0;
  virtual bool remove(const Element& aRemoved) = 0;
};
