/*
 Copyright (c) 2014 Glen Joseph Fernandes
 glenfe at live dot com

 Distributed under the Boost Software License,
 Version 1.0. (See accompanying file LICENSE_1_0.txt
 or copy at http://boost.org/LICENSE_1_0.txt)
*/
#ifndef BOOST_ALIGN_DETAIL_ALIGNMENT_OF_MSVC_HPP
#define BOOST_ALIGN_DETAIL_ALIGNMENT_OF_MSVC_HPP

#include <boost/align/detail/min_size.hpp>
#include <boost/align/detail/no_ref.hpp>

namespace boost {
    namespace alignment {
        namespace detail {
            template<class T>
            struct padded {
                char unit;
                typename no_ref<T>::type object;
            };
        }

        template<class T>
        struct alignment_of {
            enum {
                value = detail::min_size<__alignof(T),
                    sizeof(detail::padded<T>) - sizeof(T)>::value
            };
        };
    }
}

#endif
