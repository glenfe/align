/*
(c) 2015 NumScale SAS

(c) 2014 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGN_PREV_HPP
#define BOOST_ALIGN_DETAIL_ALIGN_PREV_HPP

#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <boost/align/detail/is_alignment.hpp>
#include <cstdlib>

namespace boost {
namespace alignment {

inline std::size_t align_prev(std::size_t alignment, std::size_t value)
    BOOST_NOEXCEPT
{
    BOOST_ASSERT(detail::is_alignment(alignment));
    return value & ~(alignment - 1);
}

template <class T>
inline T* align_prev(std::size_t alignment, T* ptr)
    BOOST_NOEXCEPT
{
    BOOST_ASSERT(detail::is_alignment(alignment));
    std::size_t addr = reinterpret_cast<std::size_t>(ptr);
    return reinterpret_cast<T*>(::boost::alignment::align_prev(alignment, addr));
}

} /* .alignment */
} /* .boost */

#endif
