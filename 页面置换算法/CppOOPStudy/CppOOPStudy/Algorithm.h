//
//  Algorithm.h
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/20.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#ifndef Algorithm_h
#define Algorithm_h

#include "Utils.h"
#include "block.hpp"

class Algorithm{
public:
    /**
     最近最久未使用算法
     @param pages 页顺序表, outputFileName 输出文件名
     @return bool 是否执行成功
     */
    static bool LRU_Algorithm(vector<int> pages, string outputFileName);
    
    /**
     先进先替换算法
     @param pages 页顺序表, outputFileName 输出文件名
     @return bool 是否执行成功
     */
    static bool FIFO_Algorithm(vector<int> pages, string outputFileName);
    
    /**
     最佳页面替换算法
     @param pages 页顺序表, outputFileName 输出文件名
     @return bool 是否执行成功
     */
    static bool OPT_Algorithm(vector<int> pages, string outputFileName);
};
#endif /* Algorithm_h */
