//
//  main.cpp
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/18.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#include "BASE.h"
#include "Utils.h"
#include "Algorithm.h"

int main(int argc, const char * argv[]) {
    cout<<"hello!"<<endl;
    vector<int> pages = Utils::getPagesFromFiles("/Users/zhangchi/Desktop/OS-code/CppOOPStudy/CppOOPStudy/pages.txt");
    for (int i=0; i<5; i++) {
        cout<<pages[i]<<endl;
    }
    
    Algorithm::FIFO_Algorithm(pages, "/Users/zhangchi/Desktop/OS-code/CppOOPStudy/CppOOPStudy/output.txt");
    
    return 0;
}
