//
//  block.hpp
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/21.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#ifndef block_hpp
#define block_hpp

#include "BASE.h"

class block{
public:
    block(int blockId, int storePageID, int lifeToSet){//构造函数
        storePage = storePageID;//因为不是从0号开始的，所以默认设置成0号视为没有存放页
        id = blockId;//id从1到3
        life = lifeToSet;//这个块有多久没变了
        next = 10000;//用于最佳置换算法，描述这个页面下一次被访问隔了多久，初始值设置很大认为以后不再访问
    }
    static int getStorePage(block& block);
    static void setStorePage(int page, block& block);
    
    int getLife();
    void setLife(int life);
    
    int getnext();
    void setNext(int next);
    
private:
    int id;
    int storePage;
    int life;
    int next;
};

#endif /* block_hpp */
