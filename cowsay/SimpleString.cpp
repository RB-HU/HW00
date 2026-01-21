#include "SimpleString.hpp"
#include <ostream>

size_t cstrlen(const char* cstring) {
  size_t len = 0;
  while (cstring[len] != '\0') {
    len += 1;
  }
  return len;
}
SimpleString SimpleString_From(const char* cstring) {
  SimpleString copied;
  copied.len = cstrlen(cstring);
  copied.data = new char[copied.len + 1];
  for (size_t i = 0; i < copied.len; i++) {
    copied.data[i] = cstring[i];
  }
  copied.data[copied.len] = '\0';
  return copied;
}

SimpleString SimpleString_Clone(const SimpleString to_copy) {
  return SimpleString_From(to_copy.data);
}

SimpleString SimpleString_Substr(const SimpleString self,
                                 size_t start_index,
                                 size_t length) {
  SimpleString substr;
  size_t sub_len;
  if (length == SimpleString::npos || start_index + length > self.len) {
    sub_len = self.len - start_index;
  } else {
    sub_len = length;
  }
  substr.len = sub_len;
  substr.data = new char[sub_len + 1];
  for (size_t i = 0; i < sub_len; i++) {
    substr.data[i] = self.data[start_index + i];
  }
  substr.data[sub_len] = '\0';
  return substr;
}

size_t SimpleString_Find(const SimpleString self, char target) {
  for (size_t i = 0; i < self.len; i++) {
    if (self.data[i] == target) {
      return i;
    }
  }
  return SimpleString::npos;
}

bool operator==(const SimpleString lhs, const SimpleString rhs) {
  if (lhs.len != rhs.len) {
    return false;
  }
  for (size_t i = 0; i < lhs.len; i++) {
    if (lhs.data[i] != rhs.data[i]) {
      return false;
    }
  }
  return true;
}

char SimpleString_At(const SimpleString self, size_t index) {
  return self.data[index];
}

void SimpleString_Destruct(SimpleString to_destroy) {
  delete[] to_destroy.data;
  to_destroy.len = 0;
}

std::ostream& operator<<(std::ostream& os, const SimpleString to_print) {
  os << to_print.data;
  return os;
}
