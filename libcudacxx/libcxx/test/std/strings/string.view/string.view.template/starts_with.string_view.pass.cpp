//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++98, c++03, c++11, c++14, c++17

// <string_view>

//   constexpr bool starts_with(string_view x) const noexcept;

#include <string_view>
#include <cassert>

#include "test_macros.h"
#include "constexpr_char_traits.h"

int main(int, char**)
{
    {
    typedef std::string_view SV;
    const char *s = "abcde";
    SV  sv0 {};
    SV  sv1 { s, 1 };
    SV  sv2 { s, 2 };
    SV  sv3 { s, 3 };
    SV  sv4 { s, 4 };
    SV  sv5 { s, 5 };
    SV  svNot {"def", 3 };

    ASSERT_NOEXCEPT(sv0.starts_with(sv0));

    assert ( sv0.starts_with(sv0));
    assert (!sv0.starts_with(sv1));

    assert ( sv1.starts_with(sv0));
    assert ( sv1.starts_with(sv1));
    assert (!sv1.starts_with(sv2));
    assert (!sv1.starts_with(sv3));
    assert (!sv1.starts_with(sv4));
    assert (!sv1.starts_with(sv5));
    assert (!sv1.starts_with(svNot));

    assert ( sv2.starts_with(sv0));
    assert ( sv2.starts_with(sv1));
    assert ( sv2.starts_with(sv2));
    assert (!sv2.starts_with(sv3));
    assert (!sv2.starts_with(sv4));
    assert (!sv2.starts_with(sv5));
    assert (!sv2.starts_with(svNot));

    assert ( svNot.starts_with(sv0));
    assert (!svNot.starts_with(sv1));
    assert (!svNot.starts_with(sv2));
    assert (!svNot.starts_with(sv3));
    assert (!svNot.starts_with(sv4));
    assert (!svNot.starts_with(sv5));
    assert ( svNot.starts_with(svNot));
    }

#if TEST_STD_VER > 2011
    {
    typedef std::basic_string_view<char, constexpr_char_traits<char>> SV;
    constexpr const char *s = "abcde";
    constexpr SV  sv0 {};
    constexpr SV  sv1 { s, 1 };
    constexpr SV  sv2 { s, 2 };
    constexpr SV  sv3 { s, 3 };
    constexpr SV  sv4 { s, 4 };
    constexpr SV  sv5 { s, 5 };
    constexpr SV  svNot {"def", 3 };

    static_assert ( sv0.starts_with(sv0), "" );
    static_assert (!sv0.starts_with(sv1), "" );

    static_assert ( sv1.starts_with(sv0), "" );
    static_assert ( sv1.starts_with(sv1), "" );
    static_assert (!sv1.starts_with(sv2), "" );
    static_assert (!sv1.starts_with(sv3), "" );
    static_assert (!sv1.starts_with(sv4), "" );
    static_assert (!sv1.starts_with(sv5), "" );
    static_assert (!sv1.starts_with(svNot), "" );

    static_assert ( sv2.starts_with(sv0), "" );
    static_assert ( sv2.starts_with(sv1), "" );
    static_assert ( sv2.starts_with(sv2), "" );
    static_assert (!sv2.starts_with(sv3), "" );
    static_assert (!sv2.starts_with(sv4), "" );
    static_assert (!sv2.starts_with(sv5), "" );
    static_assert (!sv2.starts_with(svNot), "" );

    static_assert ( svNot.starts_with(sv0), "" );
    static_assert (!svNot.starts_with(sv1), "" );
    static_assert (!svNot.starts_with(sv2), "" );
    static_assert (!svNot.starts_with(sv3), "" );
    static_assert (!svNot.starts_with(sv4), "" );
    static_assert (!svNot.starts_with(sv5), "" );
    static_assert ( svNot.starts_with(svNot), "" );
    }
#endif

  return 0;
}
