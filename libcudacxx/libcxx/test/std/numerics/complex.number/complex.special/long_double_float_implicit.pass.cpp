//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

// <complex>

// template<> class complex<long double>
// {
// public:
//     constexpr complex(const complex<float>&);
// };

#include <complex>
#include <cassert>

#include "test_macros.h"

int main(int, char**)
{
    {
    const std::complex<float> cd(2.5, 3.5);
    std::complex<long double> cf = cd;
    assert(cf.real() == cd.real());
    assert(cf.imag() == cd.imag());
    }
    {
    constexpr std::complex<float> cd(2.5, 3.5);
    constexpr std::complex<long double> cf = cd;
    static_assert(cf.real() == cd.real(), "");
    static_assert(cf.imag() == cd.imag(), "");
    }

  return 0;
}
