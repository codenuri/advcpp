#include <iostream>
#include <string>
#include <vector>
#include "trace_new.h"

int main()
{
    std::vector<std::string> v;

    // �Ʒ� �ڵ�� VC(Release) ���� 1018 ���� �޸� �Ҵ��� �ֽ��ϴ�.
    // 1000 : string�� �����ڰ� ���
    // 18   : vector �� ���۸� Ű��µ� ���

    for (int i = 0; i < 1000; ++i) 
    {    
        v.emplace_back("to be or not to be");
    }
    report();
}
