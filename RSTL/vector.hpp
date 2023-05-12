#include <string.h>
#include <stdlib.h>

#ifndef RSTL_NO_INITIALIZER_LIST
#include <initializer_list>
#endif


namespace RSTL {
    template <typename type, size_t capacity = 0> /* assuming type is a valid character type, i.e */
    struct vector {
        type* src; /* source c-array */
        size_t srcSize = 0; /* size of the c-array */

        void push_back(type data) {
            srcSize++;

            src = (type*)realloc(src, sizeof(type) * size());

            src[size() - 1] = data;
        }

        void push_back(vector<type> data) {
            for (int i = 0; i < data.size(); i++)
                push_back(data[i]);
        }

        void insert(int index, type data) {
            if (index > size())
                push_back(data);
            else
                src[index] = data;
        }

        void insert(int begin, vector<type> data) {
            for (int i = begin; i < data.size(); i++) {
                if (i < size())
                    src[i] = data[i];
                else
                    push_back(data[i]);
            }
        }

        void erase(int index) {
            index++;

            type* ahead;
            type* behind;

            int j = 0;
            for (int i = 0; i < size(); i++, j++) {
                if (i == index)
                    j--;

                src[j] = src[i];
            }

            srcSize--;

            src = (type*) realloc(src, sizeof(type) * size());
        }

        /* functions for std compatibility */
        size_t size() { return srcSize; } 
        type& at(int index) { return src[index]; }
        type& back(){ return src[size() - 1]; }
        int begin(){ return 0; } /* filler */
        const type* data() { return src; }
        const type* c_str() { return data(); }

        vector(const type* data, size_t size) {
            src = (type*)malloc(size * sizeof(type));

            srcSize = size;

            memcpy(src, data, size * sizeof(type));
        }

        #ifndef RSTL_NO_INITIALIZER_LIST
        vector(std::initializer_list<type> list) {  
            src = (type*)malloc(list.srcSize * sizeof(type));

            srcSize = list.srcSize;

            memcpy(src, list.src, size() * sizeof(type));
        }
        #endif

        type& operator[](int index){ return at(index); }

        ~vector() {             
            if (size())
                free(src); 
            srcSize = 0;
        }

        bool operator==(vector<type> vector2);
    };
}
