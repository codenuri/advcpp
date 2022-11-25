#include <iostream>
#include <string>
#include <vector>
#include <memory_resource> // C++17 ±â¼ú
#include "trace_new.h"

int main()
{
    char buff[200000];

    std::pmr::monotonic_buffer_resource pool(buff, sizeof(buff));
    std::pmr::vector<std::string> v(&pool);
//  std::vector<std::string> v;

    for (int i = 0; i < 1000; ++i)
    {
        v.emplace_back("to be or not to be");
    }
    report();
}
