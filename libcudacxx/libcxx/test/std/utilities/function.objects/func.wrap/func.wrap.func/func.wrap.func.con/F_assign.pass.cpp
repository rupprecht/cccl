//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <functional>

// class function<R(ArgTypes...)>

// template<class F>
//   requires CopyConstructible<F> && Callable<F, ArgTypes..>
//         && Convertible<Callable<F, ArgTypes...>::result_type
//   operator=(F f);

#include <functional>
#include <cassert>

#include "test_macros.h"
#include "count_new.h"

class A
{
    int data_[10];
public:
    static int count;

    A()
    {
        ++count;
        for (int i = 0; i < 10; ++i)
            data_[i] = i;
    }

    A(const A&) {++count;}

    ~A() {--count;}

    int operator()(int i) const
    {
        for (int j = 0; j < 10; ++j)
            i += data_[j];
        return i;
    }

    int foo(int) const {return 1;}
};

int A::count = 0;

int g(int) {return 0;}

struct RValueCallable {
    template <class ...Args>
    void operator()(Args&&...) && {}
};
struct LValueCallable {
    template <class ...Args>
    void operator()(Args&&...) & {}
};

int main(int, char**)
{
    assert(globalMemCounter.checkOutstandingNewEq(0));
    {
    std::function<int(int)> f;
    f = A();
    assert(A::count == 1);
    assert(globalMemCounter.checkOutstandingNewEq(1));
    assert(f.target<A>());
    assert(f.target<int(*)(int)>() == 0);
    }
    assert(A::count == 0);
    assert(globalMemCounter.checkOutstandingNewEq(0));
    {
    std::function<int(int)> f;
    f = g;
    assert(globalMemCounter.checkOutstandingNewEq(0));
    assert(f.target<int(*)(int)>());
    assert(f.target<A>() == 0);
    }
    assert(globalMemCounter.checkOutstandingNewEq(0));
    {
    std::function<int(int)> f;
    f = (int (*)(int))0;
    assert(!f);
    assert(globalMemCounter.checkOutstandingNewEq(0));
    assert(f.target<int(*)(int)>() == 0);
    assert(f.target<A>() == 0);
    }
    {
    std::function<int(const A*, int)> f;
    f = &A::foo;
    assert(f);
    assert(globalMemCounter.checkOutstandingNewEq(0));
    assert(f.target<int (A::*)(int) const>() != 0);
    }
    {
    std::function<void(int)> f;
    f = &g;
    assert(f);
    assert(f.target<int(*)(int)>() != 0);
    f(1);
    }
    {
        using Fn = std::function<void(int, int, int)>;
        static_assert(std::is_assignable<Fn&, LValueCallable&>::value, "");
        static_assert(std::is_assignable<Fn&, LValueCallable>::value, "");
        static_assert(!std::is_assignable<Fn&, RValueCallable&>::value, "");
        static_assert(!std::is_assignable<Fn&, RValueCallable>::value, "");
    }

  return 0;
}
