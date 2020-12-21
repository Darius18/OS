//
//  BASE.h
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/19.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#ifndef BASE_h
#define BASE_h

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/**
 * 按某种格式分割字符串
 * @param line 待分割字符串
 * @param pattern 分割的模式
 * @return 返回分割后的字符串集
 */
vector<string> stringToken(string line, string pattern);


/**
 * 按某种格式分割字符串,返回的是int vector
 * @param line 待分割字符串
 * @param pattern 分割的模式
 * @return 返回分割后的vector
 */
vector<int> stringTokentoInt(string line, string pattern);

#endif /* BASE_h */
