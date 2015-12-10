/*
(c) 2014 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

(c) 2015 NumScale SAS

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/
#ifndef BOOST_ALIGN_DETAIL_IS_ALIGNED_HPP
#define BOOST_ALIGN_DETAIL_IS_ALIGNED_HPP

#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <boost/align/detail/address.hpp>
#include <boost/align/detail/is_alignment.hpp>
#include <cstddef>

namespace boost {
namespace alignment {

inline bool is_aligned(std::size_t alignment, std::size_t value)
    BOOST_NOEXCEPT
{
    BOOST_ASSERT(detail::is_alignment(alignment));
    return (value & (alignment - 1)) == 0;
}

inline bool is_aligned(std::size_t alignment, const void* ptr)
    BOOST_NOEXCEPT
{
    BOOST_ASSERT(detail::is_alignment(alignment));
    return is_aligned(alignment, reinterpret_cast<std::size_t>(ptr));
}

} /* .alignment */
} /* .boost */

#endif
