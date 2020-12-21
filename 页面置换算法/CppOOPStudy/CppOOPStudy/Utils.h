//
//  Utils.h
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/19.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#ifndef Utils_h
#define Utils_h

#include "BASE.h"
/**
 * 工具类
 */

class Utils{
public:
    
    /**
     控制台打印菜单，用户选择算法
     @return;
     */
    static int choseAlgorithm();
    
    /**
     从文件中获得页面数组
     @param filename 文件名
     @return pagesString
     */
    static vector<int> getPagesFromFiles(string filename);
    
    /**
     从文件中获得页面数组
     @return pagesVector
     */
    static vector<int> getPages(Utils&); //设置成静态对象，不需要实例化
    
    /**
     把文件中读取到的转换成数组
     @param pageString 文件中读到的一行
     */
    static void setPages(Utils&, string pageString);
    
private:
    vector<int> pages;
};

#endif /* Utils_h */
