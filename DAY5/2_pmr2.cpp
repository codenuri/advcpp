#include <iostream>
#include <string>
#include <vector>
#include "trace_new.h"

int main()
{
    std::vector<std::string> v;

    // 아래 코드는 VC(Release) 에서 1018 번의 메모리 할당이 있습니다.
    // 1000 : string의 생성자가 사용
    // 18   : vector 의 버퍼를 키우는데 사용

    for (int i = 0; i < 1000; ++i) 
    {    
        v.emplace_back("to be or not to be");
    }
    report();
}
