//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// we get this comparison "for free" because the string implicitly converts to the string_view

#include <string>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

template <class S, class SV>
void
test(SV lhs, const S& rhs, bool x)
{
    assert((lhs == rhs) == x);
}

int main(int, char**)
{
    {
    typedef std::string S;
    typedef std::string_view SV;
    test(SV(""), S(""), true);
    test(SV(""), S("abcde"), false);
    test(SV(""), S("abcdefghij"), false);
    test(SV(""), S("abcdefghijklmnopqrst"), false);
    test(SV("abcde"), S(""), false);
    test(SV("abcde"), S("abcde"), true);
    test(SV("abcde"), S("abcdefghij"), false);
    test(SV("abcde"), S("abcdefghijklmnopqrst"), false);
    test(SV("abcdefghij"), S(""), false);
    test(SV("abcdefghij"), S("abcde"), false);
    test(SV("abcdefghij"), S("abcdefghij"), true);
    test(SV("abcdefghij"), S("abcdefghijklmnopqrst"), false);
    test(SV("abcdefghijklmnopqrst"), S(""), false);
    test(SV("abcdefghijklmnopqrst"), S("abcde"), false);
    test(SV("abcdefghijklmnopqrst"), S("abcdefghij"), false);
    test(SV("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), true);
    }
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    typedef std::basic_string_view<char, std::char_traits<char>> SV;
    test(SV(""), S(""), true);
    test(SV(""), S("abcde"), false);
    test(SV(""), S("abcdefghij"), false);
    test(SV(""), S("abcdefghijklmnopqrst"), false);
    test(SV("abcde"), S(""), false);
    test(SV("abcde"), S("abcde"), true);
    test(SV("abcde"), S("abcdefghij"), false);
    test(SV("abcde"), S("abcdefghijklmnopqrst"), false);
    test(SV("abcdefghij"), S(""), false);
    test(SV("abcdefghij"), S("abcde"), false);
    test(SV("abcdefghij"), S("abcdefghij"), true);
    test(SV("abcdefghij"), S("abcdefghijklmnopqrst"), false);
    test(SV("abcdefghijklmnopqrst"), S(""), false);
    test(SV("abcdefghijklmnopqrst"), S("abcde"), false);
    test(SV("abcdefghijklmnopqrst"), S("abcdefghij"), false);
    test(SV("abcdefghijklmnopqrst"), S("abcdefghijklmnopqrst"), true);
    }

  return 0;
}
