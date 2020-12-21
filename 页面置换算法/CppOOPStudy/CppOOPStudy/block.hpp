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
    }
    static int getStorePage(block& block);
    static void setStorePage(int page, block& block);
    
    int getLife();
    void setLife(int life);
private:
    int id;
    int storePage;
    int life;
};

#endif /* block_hpp */
