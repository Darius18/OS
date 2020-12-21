//
//  base.cpp
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/19.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#include "BASE.h"

vector<string> stringToken(string line, string pattern) {
    string::size_type pos;
    vector<string> result;
    line += pattern;//扩展字符串以方便操作
    string::size_type size = line.size();
    for (string::size_type i = 0; i < size; i++)
    {
        pos = line.find(pattern, i);//返回值是字母在母串中的位置(下标记录)
        if (pos < size)
        {
            string s = line.substr(i, pos - i);
            result.push_back(s);//一个新的元素加到vector的最后面
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}

/**
 * 按某种格式分割字符串,返回的是int vector
 * @param line 待分割字符串
 * @param pattern 分割的模式
 * @return 返回分割后的vector
 */
vector<int> stringTokentoInt(string line, string pattern){
    string::size_type pos;
    vector<int> result;
    line += pattern;
    string::size_type size = line.size();
    for(string::size_type i=0; i<size;i++)
    {
        pos = line.find(pattern, i);
        if(pos < size)
        {
            int num = atoi((line.substr(i, pos - i)).c_str());
            //c_str()函数返回一个指向正规C字符串的指针常量，内容与本string串相同
            result.push_back(num);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}
