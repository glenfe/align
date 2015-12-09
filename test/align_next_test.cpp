/*
(c) 2015 NumScale SAS

(c) 2014 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/

#include <boost/align/align.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/align/align_next.hpp>
#include <boost/core/lightweight_test.hpp>
#include <cstddef>
#include <iostream>

template <std::size_t Alignment>
void test()
{
    std::size_t value = 0x1;
    std::size_t aligned_value = Alignment;
    void* uptr = reinterpret_cast<void*>(value);
    void* aptr = reinterpret_cast<void*>(aligned_value);
    {
      // `align_next` has no effect if the pointer has already the desired alignment
      void* ptr = boost::alignment::align_next(Alignment, aptr);
      BOOST_TEST(ptr == aptr);
    }
    {
      void* ptr = boost::alignment::align_next(Alignment, uptr);
      BOOST_TEST(ptr == aptr);
    }
    {
      // `align_next` has no effect if the value has already the desired alignment
      std::size_t val = boost::alignment::align_next(Alignment, aligned_value);
      BOOST_TEST(val == aligned_value);
    }
    {
      std::size_t val = boost::alignment::align_next(Alignment, value);
      BOOST_TEST(val == aligned_value);
    }
}

int main()
{
    std::cout << boost::alignment::align_next(16, 16) << std::endl;
    test<1>();
    test<2>();
    test<4>();
    test<8>();
    test<16>();
    test<32>();
    test<64>();
    test<128>();

    return boost::report_errors();
}
