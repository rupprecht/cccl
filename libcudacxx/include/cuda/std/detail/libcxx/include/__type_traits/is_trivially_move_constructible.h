//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCUDACXX___TYPE_TRAITS_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_H
#define _LIBCUDACXX___TYPE_TRAITS_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_H

#ifndef __cuda_std__
#include <__config>
#endif // __cuda_std__

#include "../__type_traits/add_rvalue_reference.h"
#include "../__type_traits/is_trivially_constructible.h"

#if defined(_CCCL_IMPLICIT_SYSTEM_HEADER_GCC)
#  pragma GCC system_header
#elif defined(_CCCL_IMPLICIT_SYSTEM_HEADER_CLANG)
#  pragma clang system_header
#elif defined(_CCCL_IMPLICIT_SYSTEM_HEADER_MSVC)
#  pragma system_header
#endif // no system header

_LIBCUDACXX_BEGIN_NAMESPACE_STD

#if defined(_LIBCUDACXX_IS_TRIVIALLY_CONSTRUCTIBLE) && !defined(_LIBCUDACXX_USE_IS_TRIVIALLY_CONSTRUCTIBLE_FALLBACK)

template <class _Tp>
struct _LIBCUDACXX_TEMPLATE_VIS is_trivially_move_constructible
    : public integral_constant<bool,
        _LIBCUDACXX_IS_TRIVIALLY_CONSTRUCTIBLE(_Tp, __add_rvalue_reference_t<_Tp>)>
    {};

#if _CCCL_STD_VER > 2011 && !defined(_LIBCUDACXX_HAS_NO_VARIABLE_TEMPLATES)
template <class _Tp>
_LIBCUDACXX_INLINE_VAR constexpr bool is_trivially_move_constructible_v =
    _LIBCUDACXX_IS_TRIVIALLY_CONSTRUCTIBLE(_Tp, __add_rvalue_reference_t<_Tp>);
#endif

#else

template <class _Tp> struct _LIBCUDACXX_TEMPLATE_VIS is_trivially_move_constructible
    : public is_trivially_constructible<_Tp, __add_rvalue_reference_t<_Tp>>
    {};

#if _CCCL_STD_VER > 2011 && !defined(_LIBCUDACXX_HAS_NO_VARIABLE_TEMPLATES)
template <class _Tp>
_LIBCUDACXX_INLINE_VAR constexpr bool is_trivially_move_constructible_v = is_trivially_move_constructible<_Tp>::value;
#endif

#endif // defined(_LIBCUDACXX_IS_TRIVIALLY_CONSTRUCTIBLE) && !defined(_LIBCUDACXX_USE_IS_TRIVIALLY_CONSTRUCTIBLE_FALLBACK)

_LIBCUDACXX_END_NAMESPACE_STD

#endif // _LIBCUDACXX___TYPE_TRAITS_IS_TRIVIALLY_MOVE_CONSTRUCTIBLE_H
