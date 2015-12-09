/*
(c) 2014 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

(c) 2015 NumScale SAS

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#include <boost/align/is_aligned.hpp>
#include <boost/core/lightweight_test.hpp>
#include <cstddef>

template<std::size_t Alignment>
void test()
{
    char s[Alignment << 1];
    char* b = s;
    while (!boost::alignment::is_aligned(Alignment, b)) {
        b++;
    }
    std::size_t n = Alignment;
    {
        void* p = &b[n];
        BOOST_TEST(boost::alignment::is_aligned(n, p));
    }
    {
        BOOST_TEST(boost::alignment::is_aligned(Alignment, n));
    }
    if (n > 1) {
        {
            void* p = &b[1];
            BOOST_TEST(!boost::alignment::is_aligned(n, p));
        }
        {
            BOOST_TEST(!boost::alignment::is_aligned(Alignment, n + 1));
        }
    }
}

int main()
{
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
