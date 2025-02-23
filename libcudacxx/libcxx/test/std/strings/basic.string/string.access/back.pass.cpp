//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// const charT& back() const;
//       charT& back();

#ifdef _LIBCUDACXX_DEBUG
#define _LIBCUDACXX_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))
#endif

#include <string>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

template <class S>
void
test(S s)
{
    const S& cs = s;
    ASSERT_SAME_TYPE(decltype( s.back()), typename S::reference);
    ASSERT_SAME_TYPE(decltype(cs.back()), typename S::const_reference);
    LIBCPP_ASSERT_NOEXCEPT(    s.back());
    LIBCPP_ASSERT_NOEXCEPT(   cs.back());
    assert(&cs.back() == &cs[cs.size()-1]);
    assert(&s.back() == &s[cs.size()-1]);
    s.back() = typename S::value_type('z');
    assert(s.back() == typename S::value_type('z'));
}

int main(int, char**)
{
    {
    typedef std::string S;
    test(S("1"));
    test(S("1234567890123456789012345678901234567890"));
    }
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    test(S("1"));
    test(S("1234567890123456789012345678901234567890"));
    }
#ifdef _LIBCUDACXX_DEBUG
    {
        std::string s;
        (void) s.back();
        assert(false);
    }
#endif

  return 0;
}
