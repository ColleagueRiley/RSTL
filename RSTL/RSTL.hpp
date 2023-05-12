#if defined(_GLIBCXX_STRING) || defined(_GLIBCXX_VECTOR) || defined(_INITIALIZER_LIST)
#define RSTL_STD /* if the std library is already being used, override RSTL and just keep using std */
#endif

#if defined(RSTL_NO_OVERRIDE) && defined(RSTL_STD) /* allow std override to be toggled */
#undef RSTL_STD
#endif

#ifdef RSTL_STD
#include <string>
#include <vector>

namespace RSTL {
    using std::vector;
    using std::basic_string;
    using std::string;
}
#endif

/* strings + vectors are included by default, but you can choose to not include them */

#ifndef RSTL_NO_STRING
#include "string.hpp"
#endif

#ifndef RSTL_NO_VECTOR
#include "vector.hpp"
#endif