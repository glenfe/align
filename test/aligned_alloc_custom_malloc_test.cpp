/*
(c) 2014 Glen Joseph Fernandes
<glenjofe -at- gmail.com>

(c) 2015 NumScale SAS

Distributed under the Boost Software
License, Version 1.0.
http://boost.org/LICENSE_1_0.txt
*/

#define BOOST_ALIGN_CUSTOM_MEMORY_HANDLERS
#include "aligned_alloc_test.cpp"

namespace boost {
namespace alignment {

static std::size_t       memory_index = 0;
static const std::size_t memory_size  = 2000;
static char              memory_pool[memory_size];

void* custom_malloc(std::size_t size)
{
    if (memory_index > memory_size) {
      return 0;
    }
    void* ptr = &memory_pool[memory_index];
    memory_index += size;
    return ptr;
}

void custom_free(void*)
{
    // Should free here
}

} /* .alignment */
} /* .boost */
