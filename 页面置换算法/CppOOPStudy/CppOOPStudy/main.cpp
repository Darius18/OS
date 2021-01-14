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
    vector<int> pages = Utils::getPagesFromFiles("/Users/zhangchi/Desktop/githubRepositories/OS/页面置换算法/CppOOPStudy/CppOOPStudy/pages.txt");
    for (int i=0; i<5; i++) {
        cout<<pages[i]<<endl;
    }
    int choose;
    string outURL = "/Users/zhangchi/Desktop/githubRepositories/OS/页面置换算法/CppOOPStudy/CppOOPStudy/output.txt";
    cout<<"choose the pages replacement algorithm:"<<endl;
    cout<<"1. FIFO"<<endl;
    cout<<"2. OPT"<<endl;
    cout<<"3. LRU"<<endl;
    cin>>choose;
    if (1==choose) {
        Algorithm::FIFO_Algorithm(pages,outURL);
    }else if (2==choose){
        Algorithm::OPT_Algorithm(pages,outURL);
        
    }else if (3==choose){
        Algorithm::LRU_Algorithm(pages,outURL);
        
    }
    cout<<"done!check it out!";
    return 0;
}
