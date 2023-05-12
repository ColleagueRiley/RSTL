#include <string.h>
#include <stdlib.h>

namespace RSTL {
    template <typename type> /* assuming type is a valid character type, i.e */
    struct basic_string {
        type* src;
        size_t srcSize;

        /* load string */
        basic_string(const type* str) {
            for (srcSize = 0; str[srcSize]; srcSize++); /* when str[srcSize] == 0, it's reached the end of the string */

            src = (type*)malloc(sizeof(type) * size());

            strcpy(src, str);
        }

        void operator+=(basic_string<type> str) {
            char* src2 = (type*)malloc(sizeof(type) * (size() + str.size()));

            sprintf(src2, "%s%s", src, str.src); 

            src = src2;
        }

        bool operator==(basic_string<type> str) { return !strcmp(src, str.str); }

        basic_string() { srcSize = 0; }

        ~basic_string() { 
            if (size())
                free(src); 
            srcSize = 0;
        } /* auto free */
    
        /* functions for std compatibility */
        const type* c_str() { return src; }
        const type* data() { return src; }
        const size_t size() { return srcSize; }
    };

    typedef basic_string<char> string;
}