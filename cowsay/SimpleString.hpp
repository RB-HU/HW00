// TODO: add header guards
// look at what is done in lecture and do something similar.
// Just remeber that this file is called SimpleString.hpp
#ifndef SIMPLEStTRING_HPP_
#define SIMPLEStTRING_HPP_
#include <cstddef>  // for size_t
#include <ostream>  // for ostream

// no other #includes are allowed

/*!
 * Gets the length of a null-termianted c-string. This does not include the
 * null-terminator as counting towards the length.
 *
 * This function is not part of the SimpleString "object", but you will likely
 * still find it useful, so we suggest you implement it.
 */
size_t cstrlen(const char* cstring);

/*!
 * Represents a string "object"
 */
struct SimpleString {
  char* data; /*! A dynamically allocated null-terminated character array */
  size_t len; /*! The length of the string */

  /*!
   * Since this is a static variable, it is not tied to any specific
   * instance of a SimpleString. It can always be referred to via
   * doing `SimpleString::npos`
   */
  static const size_t npos = -1;
};

/*!
 * "constructs" a new `SimpleString` from a given C-style string.
 *
 * @param: cstring - the null-terminated C-style string this is based off of
 * @return: a new SimpleString "object" this object is based off of the
 *          passed in cstring. However, after construction the SimpleString
 *          is independent from the passed in `cstring` by making its own copy
 *          of the `cstring`'s contents.
 */
SimpleString SimpleString_From(const char* cstring);

/*!
 * "constructs" a copy of a `SimpleString`
 *
 * @param: to_copy - the SimpleString we are copying
 * @return: a new SimpleString "object" this object is based off of the
 *          passed in SimpleString. However, the new SimpleString
 *          is independent from the passed in SimpleString by making its own
 *          copy of the `SimpleString`'s contents.
 *
 */
SimpleString SimpleString_Clone(const SimpleString to_copy);

/*!
 * takes the substring of a given string.
 * Note: unlike some substring functions in other languages, in C++
 * the substring is usually defined by being given the starting index into the
 * string and the __length__ of the substring.
 *
 * For example:
 *   SimpleString s = SimpleString_From("Hello!");
 *   SimpleString sub = SimpleString_Substr(s, 3, 3);
 *   cout << sub << endl;  // prints "lo!"
 *
 * @param: self - the string we are taking the substring of
 * @param: start_index - the index we are starting our substring at
 * @param: length - the length of the substring we want to make.
 *         If length is equal to `SimpleString::npos` or if
 *         `length + start_index >= self.len` then the substring
 *         just goes from the specified start index and goes to the
 *         end of the input string.
 * @pre you can assume start_index is a valid index into the string.
 * @return: the specified substring
 */
SimpleString SimpleString_Substr(const SimpleString self,
                                 size_t start_index,
                                 size_t length);

/*!
 * Finds the location of a character in the string starting
 * from index 0.
 *
 * @param: self - the string we are searching
 * @param: target - the char we are lookking for
 * @return: the lowest index that the character is found at
 *          or SimpleString::npos if it is not found.
 */
size_t SimpleString_Find(const SimpleString self, char target);

/*!
 * Checks to see if two SimpleString's are equal.
 *
 * Two SimpleStrings are equal iff (if and only if) they have
 * the same length and the same character at the same indexes.
 *
 * @param: lhs - the first string we want to compare
 * @param: rhs - the second string we want to compare
 * @returns: true iff the strings are equal
 *
 * Note that we call the parameters `lhs` and `rhs`.
 * This is short for Left Hand Side and Right Hand Side.
 * This is because C++ allows us to define functions that look like
 * normal operators and this is an exmaple of this. We can invoke this
 * function is like so:
 *
 * SimpleString s1 = SimpleString_From("Howdy!");
 * SimpleString s2 = SimpleString_From("howdy!");
 * bool equal = s1 == s2;  // <-- we call the function here with ==
 *                         // evaluates to false since the strings are differ
 *
 * as you can see, one SimpleString is on the left side of the `==` operator
 * and one of the SimpleStrings is on the right side :)
 */
bool operator==(const SimpleString lhs, const SimpleString rhs);

/*!
 * Gets the character at the specified index in the SimpleString
 *
 * @param: self - the string we want to get a character from
 * @param: index - the index we want to get the character from
 * @returns: the character at the specified index
 * @pre: assumes that the index is a valid index into the string
 *
 * example:
 * SimpleString s1 = SimpleString_From("Howdy!");
 * cout << SimpleString_At(s1, 0) << endl;  // prints "H"
 */
char SimpleString_At(const SimpleString self, size_t index);

/*!
 * Cleans up a SimpleString object.
 *
 * @param: to_destroy the SimpleString whose resources we want to clean up
 * @pre: assumes we are given a valid SimpleString
 * @post: using the SimpleString passed in for ANYTHING after calling this
 * function is erronous behaviour.
 */
void SimpleString_Destruct(SimpleString to_destroy);

// this function is implemented for you in the assignment specification.
// It allows us to print using cout like:
// SimpleString h = SimpleString_From("Hello!");
// cout << h << endl;
std::ostream& operator<<(std::ostream& os, const SimpleString to_print);

#endif //SIMPLEStTRING_HPP_
