//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char32_t>

// static constexpr int_type to_int_type(char_type c);

#include <string>
#include <cassert>

#include "test_macros.h"

int main(int, char**)
{
#ifndef _LIBCUDACXX_HAS_NO_UNICODE_CHARS
    assert(std::char_traits<char32_t>::to_int_type(U'a') == U'a');
    assert(std::char_traits<char32_t>::to_int_type(U'A') == U'A');
    assert(std::char_traits<char32_t>::to_int_type(0) == 0);
#endif  // _LIBCUDACXX_HAS_NO_UNICODE_CHARS

  return 0;
}
