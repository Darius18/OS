//
//  Utils.cpp
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/19.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#include "Utils.h"

/**
 把文件中读取到的转换成数组
 @param pageString 文件中读到的一行
 */
void Utils::setPages(Utils& tool,string pageString){
    tool.pages = stringTokentoInt(pageString,",");
}

/**
 从文件中获得页面数组
 @return pagesVector
 */
vector<int> Utils::getPages(Utils& tool){
    return tool.pages;
};

/**
 * 从文件中获取页集
 * @param filename 文件名
 * @return pages
 */
vector<int> Utils::getPagesFromFiles(string filename){
    vector<int> pages;
    char line[LINE_MAX];
    Utils tool;
    ifstream file;//input file stream
    file.open(filename, ios::in);
    
    //判断是否成功打开
    if(!file.is_open())
    {
        cout<<"can not open the file: "<<filename<<endl;
        return pages;
    }

    
    while (file.peek()!=EOF) { //end of file
        file.getline(line, LINE_MAX);
        string lineString;
        lineString = line;//char[]->string
        cout<<"本次读取的行： string "<<lineString<<endl;
        Utils::setPages(tool, lineString);
    }
    file.close();
    
    return Utils::getPages(tool);
}
