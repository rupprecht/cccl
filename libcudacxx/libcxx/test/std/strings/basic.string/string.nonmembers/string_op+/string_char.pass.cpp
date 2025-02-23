//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// template<class charT, class traits, class Allocator>
//   basic_string<charT,traits,Allocator>
//   operator+(const basic_string<charT,traits,Allocator>& lhs, charT rhs);

// template<class charT, class traits, class Allocator>
//   basic_string<charT,traits,Allocator>&&
//   operator+(basic_string<charT,traits,Allocator>&& lhs, charT rhs);

#include <string>
#include <utility>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

template <class S>
void test0(const S& lhs, typename S::value_type rhs, const S& x) {
  assert(lhs + rhs == x);
}

template <class S>
void test1(S&& lhs, typename S::value_type rhs, const S& x) {
  assert(std::move(lhs) + rhs == x);
}

int main(int, char**) {
  {
    typedef std::string S;
    test0(S(""), '1', S("1"));
    test0(S("abcde"), '1', S("abcde1"));
    test0(S("abcdefghij"), '1', S("abcdefghij1"));
    test0(S("abcdefghijklmnopqrst"), '1', S("abcdefghijklmnopqrst1"));
  }
  {
    typedef std::string S;
    test1(S(""), '1', S("1"));
    test1(S("abcde"), '1', S("abcde1"));
    test1(S("abcdefghij"), '1', S("abcdefghij1"));
    test1(S("abcdefghijklmnopqrst"), '1', S("abcdefghijklmnopqrst1"));
  }
  {
    typedef std::basic_string<char, std::char_traits<char>,
                              min_allocator<char> >
        S;
    test0(S(""), '1', S("1"));
    test0(S("abcde"), '1', S("abcde1"));
    test0(S("abcdefghij"), '1', S("abcdefghij1"));
    test0(S("abcdefghijklmnopqrst"), '1', S("abcdefghijklmnopqrst1"));

    test1(S(""), '1', S("1"));
    test1(S("abcde"), '1', S("abcde1"));
    test1(S("abcdefghij"), '1', S("abcdefghij1"));
    test1(S("abcdefghijklmnopqrst"), '1', S("abcdefghijklmnopqrst1"));
  }

  return 0;
}
