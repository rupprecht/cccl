//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <chrono>

// duration

// template <class Rep1, class Period, class Rep2>
//   constexpr
//   duration<typename common_type<Rep1, Rep2>::type, Period>
//   operator%(const duration<Rep1, Period>& d, const Rep2& s)

#include <chrono>
#include <cassert>

#include "test_macros.h"
#include "../../rep.h"

int main(int, char**)
{
    {
    typedef std::chrono::nanoseconds Dur;
    Dur ns(15);
    ASSERT_SAME_TYPE(Dur, decltype(ns % 6));
    ns = ns % 6;
    assert(ns.count() == 3);
    }
    {
    constexpr std::chrono::nanoseconds ns(15);
    constexpr std::chrono::nanoseconds ns2 = ns % 6;
    static_assert(ns2.count() == 3, "");
    }

    { // This is PR#41130
    typedef std::chrono::seconds Duration;
    Duration d(5);
    NotARep n;
    ASSERT_SAME_TYPE(Duration, decltype(d % n));
    d = d % n;
    assert(d.count() == 5);
    }

  return 0;
}
