//
//  Executor.h
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/20.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#ifndef Executor_h
#define Executor_h

#include "Utils.h"
#include "Algorithm.h"

class Executor {
public:
    /**
     * 根据传入的参数执行相应的算法
     * @param chose 选择的算法对应的id
     * @return 0表示程序程序执行结束；1表示算法执行成功；-1表示算法执行失败
     */
    static int exe(int chose);
};

#endif /* Executor_h */
