#include "./catch.hpp"
#include <cstring>  // Does not do our cstring.h this includes C's <string.h>
#include <cstdlib>  // include's C's <stdlib.h>
#include <iostream> // for C++ printing

#include "SimpleString.hpp"

using namespace std;

TEST_CASE("From", "[SimpleString]") {
  char *s1 = strdup("Seamus");
  char *s2 = strdup("Echoes");
  char *s3 = strdup("Chumbawamba");
  char *s4 = strdup("What shalllll    we use          to   fill       the            emptyyyy           spaces");

  SimpleString ss = SimpleString_From(s1);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s1) == 0);
  delete[] ss.data;

  ss = SimpleString_From(s2);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s2) == 0);
  delete[] ss.data;

  ss = SimpleString_From(s3);
  REQUIRE(ss.len == 11U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s3) == 0);
  delete[] ss.data;

  ss = SimpleString_From(s4);
  REQUIRE(ss.len == strlen(s4));
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s4) == 0);
  delete[] ss.data;

  REQUIRE(strcmp("Seamus", s1) == 0);
  REQUIRE(strcmp("Echoes", s2) == 0);
  REQUIRE(strcmp("Chumbawamba", s3) == 0);
  REQUIRE(strcmp("What shalllll    we use          to   fill       the            emptyyyy           spaces", s4) == 0);

  free(s1);
  free(s2);
  free(s3);
  free(s4);

  char uninitialized[5];
  uninitialized[0] = 'H';
  uninitialized[1] = 'i';
  uninitialized[2] = '\0';
  // last 2 chars in array are purposefullly unitialized
  // this is done to help check for valgrind errors
  // for accessing something you should not access

  ss = SimpleString_From(uninitialized);
  REQUIRE(ss.len == 2U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, "Hi") == 0);
  delete[] ss.data;

  REQUIRE(strcmp(uninitialized, "Hi") == 0);
}

TEST_CASE("Destruct", "[SimpleString]") {
  char *s1 = strdup("Seamus");
  char *s2 = strdup("Echoes");
  char *s3 = strdup("Chumbawamba");
  char *s4 = strdup("What shalllll    we use          to   fill       the            emptyyyy           spaces");

  SimpleString ss = SimpleString_From(s1);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s1) == 0);
  SimpleString_Destruct(ss);

  ss = SimpleString_From(s2);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s2) == 0);
  SimpleString_Destruct(ss);

  ss = SimpleString_From(s3);
  REQUIRE(ss.len == 11U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s3) == 0);
  SimpleString_Destruct(ss);

  ss = SimpleString_From(s4);
  REQUIRE(ss.len == strlen(s4));
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s4) == 0);
  SimpleString_Destruct(ss);

  REQUIRE(strcmp("Seamus", s1) == 0);
  REQUIRE(strcmp("Echoes", s2) == 0);
  REQUIRE(strcmp("Chumbawamba", s3) == 0);
  REQUIRE(strcmp("What shalllll    we use          to   fill       the            emptyyyy           spaces", s4) == 0);

  free(s1);
  free(s2);
  free(s3);
  free(s4);

  char uninitialized[5];
  uninitialized[0] = 'H';
  uninitialized[1] = 'i';
  uninitialized[2] = '\0';
  // last 2 chars in array are purposefullly unitialized
  // this is done to help check for valgrind errors
  // for accessing something you should not access

  ss = SimpleString_From(uninitialized);
  REQUIRE(ss.len == 2U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, "Hi") == 0);
  SimpleString_Destruct(ss);

  REQUIRE(strcmp(uninitialized, "Hi") == 0);

  char str[] = "";
  ss = SimpleString_From(str);
  REQUIRE(strcmp(ss.data, "") == 0);
  REQUIRE(strcmp(str, "") == 0);
  REQUIRE(ss.len == 0U);
  SimpleString_Destruct(ss);
}

TEST_CASE("At", "[SimpleString]") {
  char *s1 = strdup("Seamus");
  char *s2 = strdup("Echoes");
  char *s3 = strdup("Chumbawamba");

  SimpleString ss = SimpleString_From(s1);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s1) == 0);
  REQUIRE(SimpleString_At(ss, 0) == 'S');
  REQUIRE(SimpleString_At(ss, 1) == 'e');
  REQUIRE(SimpleString_At(ss, 2) == 'a');
  REQUIRE(SimpleString_At(ss, 3) == 'm');
  REQUIRE(SimpleString_At(ss, 4) == 'u');
  REQUIRE(SimpleString_At(ss, 5) == 's');
  SimpleString_Destruct(ss);

  ss = SimpleString_From(s2);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s2) == 0);
  REQUIRE(SimpleString_At(ss, 0) == 'E');
  REQUIRE(SimpleString_At(ss, 1) == 'c');
  REQUIRE(SimpleString_At(ss, 2) == 'h');
  REQUIRE(SimpleString_At(ss, 3) == 'o');
  REQUIRE(SimpleString_At(ss, 4) == 'e');
  REQUIRE(SimpleString_At(ss, 5) == 's');
  SimpleString_Destruct(ss);

  ss = SimpleString_From(s3);
  REQUIRE(ss.len == 11U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s3) == 0);
  REQUIRE(SimpleString_At(ss, 0) == 'C');
  REQUIRE(SimpleString_At(ss, 1) == 'h');
  REQUIRE(SimpleString_At(ss, 2) == 'u');
  REQUIRE(SimpleString_At(ss, 3) == 'm');
  REQUIRE(SimpleString_At(ss, 4) == 'b');
  REQUIRE(SimpleString_At(ss, 5) == 'a');
  REQUIRE(SimpleString_At(ss, 6) == 'w');
  REQUIRE(SimpleString_At(ss, 7) == 'a');
  REQUIRE(SimpleString_At(ss, 8) == 'm');
  REQUIRE(SimpleString_At(ss, 9) == 'b');
  REQUIRE(SimpleString_At(ss,10) == 'a');
  SimpleString_Destruct(ss);

  REQUIRE(strcmp("Seamus", s1) == 0);
  REQUIRE(strcmp("Echoes", s2) == 0);
  REQUIRE(strcmp("Chumbawamba", s3) == 0);

  free(s1);
  free(s2);
  free(s3);
}

TEST_CASE("Clone", "[SimpleString]") {
  char *s1 = strdup("Seamus");
  char *s2 = strdup("Echoes");
  char *s3 = strdup("Chumbawamba");
  char *s4 = strdup("What shalllll    we use          to   fill       the            emptyyyy           spaces");

  SimpleString ss = SimpleString_From(s1);
  SimpleString copy = SimpleString_Clone(ss);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s1) == 0);
  REQUIRE(copy.len == ss.len);
  REQUIRE(strcmp(copy.data, ss.data) == 0);
  SimpleString_Destruct(ss);
  SimpleString_Destruct(copy);

  ss = SimpleString_From(s2);
  copy = SimpleString_Clone(ss);
  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s2) == 0);
  REQUIRE(copy.len == ss.len);
  REQUIRE(strcmp(copy.data, ss.data) == 0);
  SimpleString_Destruct(ss);
  SimpleString_Destruct(copy);

  ss = SimpleString_From(s3);
  copy = SimpleString_Clone(ss);
  REQUIRE(ss.len == 11U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s3) == 0);
  REQUIRE(copy.len == ss.len);
  REQUIRE(strcmp(copy.data, ss.data) == 0);
  SimpleString_Destruct(ss);
  SimpleString_Destruct(copy);

  ss = SimpleString_From(s4);
  copy = SimpleString_Clone(ss);
  REQUIRE(ss.len == strlen(s4));
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s4) == 0);
  REQUIRE(copy.len == ss.len);
  REQUIRE(strcmp(copy.data, ss.data) == 0);
  SimpleString_Destruct(ss);
  SimpleString_Destruct(copy);

  REQUIRE(strcmp("Seamus", s1) == 0);
  REQUIRE(strcmp("Echoes", s2) == 0);
  REQUIRE(strcmp("Chumbawamba", s3) == 0);
  REQUIRE(strcmp("What shalllll    we use          to   fill       the            emptyyyy           spaces", s4) == 0);

  free(s1);
  free(s2);
  free(s3);
  free(s4);

  char uninitialized[5];
  uninitialized[0] = 'H';
  uninitialized[1] = 'i';
  uninitialized[2] = '\0';
  // last 2 chars in array are purposefullly unitialized
  // this is done to help check for valgrind errors
  // for accessing something you should not access

  ss = SimpleString_From(uninitialized);
  copy = SimpleString_Clone(ss);
  REQUIRE(ss.len == 2U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, "Hi") == 0);
  REQUIRE(copy.len == ss.len);
  REQUIRE(strcmp(copy.data, ss.data) == 0);
  SimpleString_Destruct(ss);
  SimpleString_Destruct(copy);

  REQUIRE(strcmp(uninitialized, "Hi") == 0);

  char str[] = "";
  ss = SimpleString_From(str);
  copy = SimpleString_Clone(ss);
  REQUIRE(strcmp(ss.data, "") == 0);
  REQUIRE(strcmp(str, "") == 0);
  REQUIRE(ss.len == 0U);
  REQUIRE(copy.len == ss.len);
  REQUIRE(strcmp(copy.data, ss.data) == 0);
  SimpleString_Destruct(ss);
  SimpleString_Destruct(copy);
}

TEST_CASE("Find", "[SimpleString]") {
  char arr1[] = "Hello";
  char arr2[] = "Xen Gorilla";
  char arr3[] = {'X', 'e', 'n', '\0', 'y', 'e', 's'};

  SimpleString s1 = SimpleString_From(arr1);
  SimpleString s2 = SimpleString_From(arr2);
  SimpleString s3 = SimpleString_From(arr3);

  REQUIRE(SimpleString_Find(s1, 'H') == 0);
  REQUIRE(SimpleString_Find(s1, 'l') == 2);
  REQUIRE(SimpleString_Find(s1, 'h') == SimpleString::npos);

  REQUIRE(SimpleString_Find(s2, ' ') == 3);
  REQUIRE(SimpleString_Find(s2, 'G') == 4);

  REQUIRE(SimpleString_Find(s3, 'e') == 1);
  REQUIRE(SimpleString_Find(s3, 'y') == SimpleString::npos);
  REQUIRE(SimpleString_Find(s3, 's') == SimpleString::npos);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);
  SimpleString_Destruct(s3);

  s1 = SimpleString_From("");
  REQUIRE(SimpleString_Find(s1, '\0') == SimpleString::npos);
  REQUIRE(SimpleString_Find(s1, 'a') == SimpleString::npos);
  SimpleString_Destruct(s1);

  REQUIRE(SimpleString::npos == -1);

  char* cs1 = strdup("Seamus");
  char* cs2 = strdup("Echoes");
  char* cs3 = strdup("Chumbawamba");
  char* cs4 = strdup(
      "What shalllll    we use          to   fill       the            "
      "emptyyyy           spaces");

  s1 = SimpleString_From(cs1);
  s2 = SimpleString_From(cs2);
  s3 = SimpleString_From(cs3);
  SimpleString s4 = SimpleString_From(cs4);

  REQUIRE(SimpleString_Find(s1, 'S') == 0);
  REQUIRE(SimpleString_Find(s1, 's') == 5);
  REQUIRE(SimpleString_Find(s1, '\0') == SimpleString::npos);

  REQUIRE(SimpleString_Find(s2, 'c') == 1);
  REQUIRE(SimpleString_Find(s2, '.') == SimpleString::npos);
  REQUIRE(SimpleString_Find(s2, 'e') == 4);

  REQUIRE(SimpleString_Find(s3, 'm') == 3);
  REQUIRE(SimpleString_Find(s3, 'a') == 5);
  REQUIRE(SimpleString_Find(s3, '4') == SimpleString::npos);

  REQUIRE(SimpleString_Find(s4, ' ') == 4);
  REQUIRE(SimpleString_Find(s4, 'y') == 68);
  REQUIRE(SimpleString_Find(s4, 'R') == SimpleString::npos);
  REQUIRE(SimpleString_Find(s4, '\0') == SimpleString::npos);

  free(cs1);
  free(cs2);
  free(cs3);
  free(cs4);
  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);
  SimpleString_Destruct(s3);
  SimpleString_Destruct(s4);

  char uninitialized[5];
  uninitialized[0] = 'H';
  uninitialized[1] = 'i';
  uninitialized[2] = '\0';

  SimpleString uninit = SimpleString_From(uninitialized);

  REQUIRE(SimpleString_Find(uninit, 'H') == 0);
  REQUIRE(SimpleString_Find(uninit, 'a') == SimpleString::npos);
  REQUIRE(SimpleString_Find(uninit, '\0') == SimpleString::npos);

  SimpleString_Destruct(uninit);
}

TEST_CASE("operator==", "[SimpleString]") {
  SimpleString s1 = SimpleString_From("");
  SimpleString s2 = SimpleString_From("");

  REQUIRE(s1 == s2);
  REQUIRE(s2 == s1);
  REQUIRE(s1 == s1);
  REQUIRE(s2 == s2);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);

  s1 = SimpleString_From("hello");
  s2 = SimpleString_From("hello");

  REQUIRE(s1 == s2);
  REQUIRE(s2 == s1);
  REQUIRE(s1 == s1);
  REQUIRE(s2 == s2);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);

  s1 = SimpleString_From("hella");
  s2 = SimpleString_From("hellb");
  SimpleString s3 = SimpleString_From("hellc");

  REQUIRE_FALSE(s1 == s2);
  REQUIRE_FALSE(s1 == s3);
  REQUIRE_FALSE(s2 == s3);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);
  SimpleString_Destruct(s3);

  s1 = SimpleString_From("hello");
  s2 = SimpleString_From("helloa");

  REQUIRE_FALSE(s1 == s2);
  REQUIRE_FALSE(s2 == s1);
  REQUIRE(s1 == s1);
  REQUIRE(s2 == s2);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);

  s1 = SimpleString_From("abc");
  s2 = SimpleString_From("xbc");
  s3 = SimpleString_From("axc");
  SimpleString s4 = SimpleString_From("abx");

  REQUIRE_FALSE(s1 == s2);
  REQUIRE_FALSE(s2 == s3);
  REQUIRE_FALSE(s1 == s4);
  REQUIRE_FALSE(s2 == s4);
  REQUIRE_FALSE(s2 == s3);
  REQUIRE_FALSE(s3 == s4);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);
  SimpleString_Destruct(s3);
  SimpleString_Destruct(s4);

  s1 = SimpleString_From("hello!");
  s2 = SimpleString_From("hello?");
  REQUIRE_FALSE(s2 == s1);
  REQUIRE_FALSE(s1 == s2);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);

  s1 = SimpleString_From("");
  s2 = SimpleString_From("nonempty");
  REQUIRE_FALSE(s2 == s1);
  REQUIRE_FALSE(s1 == s2);

  SimpleString_Destruct(s1);
  SimpleString_Destruct(s2);
}

TEST_CASE("Substr", "[SimpleString]") {
  char *s1 = strdup("Seamus");
  char *s2 = strdup("Echoes");
  char *s3 = strdup("Chumbawamba");

  SimpleString ss = SimpleString_From(s1);
  
  SimpleString sub = SimpleString_Substr(ss, 0, 6);
  REQUIRE(sub.len == 6U);
  REQUIRE(strcmp(sub.data, "Seamus") == 0);
  SimpleString_Destruct(sub);

  sub = SimpleString_Substr(ss, 1, 5);
  REQUIRE(sub.len == 5U);
  REQUIRE(strcmp(sub.data, "eamus") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 2, 4);
  REQUIRE(sub.len == 4U);
  REQUIRE(strcmp(sub.data, "amus") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 3, 3);
  REQUIRE(sub.len == 3U);
  REQUIRE(strcmp(sub.data, "mus") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 4, 2);
  REQUIRE(sub.len == 2U);
  REQUIRE(strcmp(sub.data, "us") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 5, 1);
  REQUIRE(sub.len == 1U);
  REQUIRE(strcmp(sub.data, "s") == 0);
  SimpleString_Destruct(sub); 

  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s1) == 0);
  SimpleString_Destruct(ss);

  ss = SimpleString_From(s2);

  sub = SimpleString_Substr(ss, 1, 0);
  REQUIRE(sub.len == 0U);
  REQUIRE(strcmp(sub.data, "") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 1, 100);
  REQUIRE(sub.len == 5U);
  REQUIRE(strcmp(sub.data, "choes") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 4, SimpleString::npos);
  REQUIRE(sub.len == 2U);
  REQUIRE(strcmp(sub.data, "es") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 3, 43125132);
  REQUIRE(sub.len == 3U);
  REQUIRE(strcmp(sub.data, "oes") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 0, SimpleString::npos);
  REQUIRE(sub.len == 6U);
  REQUIRE(strcmp(sub.data, "Echoes") == 0);
  SimpleString_Destruct(sub); 

  REQUIRE(ss.len == 6U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s2) == 0);
  SimpleString_Destruct(ss);

  ss = SimpleString_From(s3);

  sub = SimpleString_Substr(ss, 4, 43125132);
  REQUIRE(sub.len == 7U);
  REQUIRE(strcmp(sub.data, "bawamba") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 1, 10);
  REQUIRE(sub.len == 10U);
  REQUIRE(strcmp(sub.data, "humbawamba") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 0, SimpleString::npos);
  REQUIRE(sub.len == 11U);
  REQUIRE(strcmp(sub.data, "Chumbawamba") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 10, 1);
  REQUIRE(sub.len == 1U);
  REQUIRE(strcmp(sub.data, "a") == 0);
  SimpleString_Destruct(sub); 

  sub = SimpleString_Substr(ss, 7, 2);
  REQUIRE(sub.len == 2U);
  REQUIRE(strcmp(sub.data, "am") == 0);
  SimpleString_Destruct(sub); 

  REQUIRE(ss.len == 11U);
  REQUIRE(SimpleString::npos == -1);
  REQUIRE(strcmp(ss.data, s3) == 0);
  SimpleString_Destruct(ss);

  REQUIRE(strcmp("Seamus", s1) == 0);
  REQUIRE(strcmp("Echoes", s2) == 0);
  REQUIRE(strcmp("Chumbawamba", s3) == 0);

  free(s1);
  free(s2);
  free(s3);
}
