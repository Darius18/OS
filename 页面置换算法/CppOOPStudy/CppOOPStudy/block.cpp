//
//  block.cpp
//  CppOOPStudy
//
//  Created by ZhangChi on 2020/12/21.
//  Copyright © 2020 edu.HENU. All rights reserved.
//

#include "block.hpp"

/**
 获取储存的页码
 @return 页码
 */

int block::getStorePage(block& block){
    return block.storePage;
}

/**
 设置储存的页码
 @param page 页id
 */

void block::setStorePage(int page, block& block){
    block.storePage = page;
}

/**
 获取block的life
 @return life
 */
int block::getLife(){
    return life;
};

/**
 设置block的life
 @param lifeToSet 要设置的life置
 */
void block::setLife(int lifeToSet){
    life = lifeToSet;
}
