#pragma once

#include <string>
#include <string_view>

class Element {
 public:
  Element();
  explicit Element(std::string_view aData);

  ~Element();

  Element(const Element& aOther);
  Element(Element&& aOther) noexcept;

  Element& operator=(const Element& aOther);
  Element& operator=(Element&& aOther) noexcept;

  auto operator<=>(const Element&) const = default;

  friend std::ostream& operator<<(std::ostream& aOutputStream,
                                  const Element& aValue) {
    constexpr std::string_view prefix{"Element{"};
    constexpr std::string_view suffix{"}"};
    aOutputStream << prefix << aValue.mData << suffix;
    return aOutputStream;
  }

 private:
  std::string mData;
};