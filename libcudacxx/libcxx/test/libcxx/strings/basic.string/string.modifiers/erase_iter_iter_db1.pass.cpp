//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// Call erase(const_iterator first, const_iterator last); with first iterator from another container

#if _LIBCUDACXX_DEBUG >= 1

#define _LIBCUDACXX_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <string>
#include <cassert>
#include <exception>
#include <cstdlib>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
    std::string l1("123");
    std::string l2("123");
    std::string::iterator i = l1.erase(l2.cbegin(), l1.cbegin()+1);
    assert(false);
    }
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    S l1("123");
    S l2("123");
    S::iterator i = l1.erase(l2.cbegin(), l1.cbegin()+1);
    assert(false);
    }
}

#else

int main(int, char**)
{

  return 0;
}

#endif
