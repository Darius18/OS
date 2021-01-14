//
//  OPT_Algorithm.cpp
//  CppOOPStudy
//
//  Created by ZhangChi on 2021/1/14.
//  Copyright © 2021 edu.HENU. All rights reserved.
//

#include "Algorithm.h"

/**
 最佳页面替换算法
 @param pages 页顺序表, outputFileName 输出文件名
 @return bool 是否执行成功
 */
bool Algorithm::OPT_Algorithm(vector<int> pages, string outputFileName)
{
    vector<int>::iterator it;
    vector<int>::iterator it_next;
    int lackNum = 0;
    int pageNum = 0;
    double lackRate = 0;
    int blockNum = 3;
    block arrayOfBlock[3] = //待优化📚
    {
        block(1,0,0),
        block(2,0,0),
        block(3,0,0)
    };
    
    //    for(int i=0; i<blockNum; i++){ //初始化
    //        arrayOfBlock[i] = block(i,0);}
    
    
    //打开写入文件
    ofstream output_file;
    output_file.open(outputFileName);
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << outputFileName << "!" << endl;
        return false;
    }
    output_file << "页 \t\t 物理块1 \t\t 物理块2 \t\t 物理块3"<< endl;
    
    
    
    for (it = pages.begin(); it != pages.end(); it++)
    {
        pageNum++;
        int islack=true;
        for(int i=0;i<blockNum;i++){
            if(*it == arrayOfBlock[i].getStorePage(arrayOfBlock[i])){
                //说明不缺页
                islack = false;
                break;
            }
            
        }
        if(islack){//缺页就要进行调度
            lackNum++;
            //看看这个数组块满了没有
            bool full = true;
            for(int i=0; i<blockNum; i++){
                if (arrayOfBlock[i].getStorePage(arrayOfBlock[i])==0){//没有存放页面，可以存放
                    arrayOfBlock[i].setStorePage(*it, arrayOfBlock[i]);
                    arrayOfBlock[i].setLife(1);
                    full = false;
                    break;
                }
            }
            
            //replacement
            //向前检查，换掉三个块中页面的next值最大的那一个
            
            //首先设置next的值
            for (it_next = it+1; it_next!=pages.end(); it_next++) {
                for (int i=0; i<blockNum; i++) {
                    if(*it_next == arrayOfBlock[i].getStorePage(arrayOfBlock[i])||arrayOfBlock[i].getnext()==10000){//匹配到了，且是最近的那一个
                        arrayOfBlock[i].setNext(int(it_next - it));//设置next的值，也就是还有多久要再次调用这个块中的页面
                    }
                }
            }
            
            
            
            if (full){//如果块满了
                
                int max_index = 0;
                for (int j=0; j<blockNum; j++) { //选出最大life的block的index
                    if( arrayOfBlock[j].getnext() > arrayOfBlock[max_index].getnext()){
                        max_index = j;
                    }
                }
                
                //进行替换
                
                arrayOfBlock[max_index].setStorePage(*it, arrayOfBlock[max_index]);
                //arrayOfBlock[max_index].setLife(1);
            }
        }
        
        /*
        for(int i=0; i<blockNum; i++){
            if (arrayOfBlock[i].getLife()!=0){ //有东西
                arrayOfBlock[i].setLife(arrayOfBlock[i].getLife()+1);
            }
        }
        */
        
        //写入文件
        //        output_file <<*it<<"\t"<<arrayOfBlock[0].getLife()<<"\t"<<arrayOfBlock[0].getStorePage(arrayOfBlock[0])<<"\t"<<arrayOfBlock[1].getLife()<<"\t"<<arrayOfBlock[1].getStorePage(arrayOfBlock[1])<<"\t"<<arrayOfBlock[2].getLife()<<"\t"<<arrayOfBlock[2].getStorePage(arrayOfBlock[2])<< endl;
        
        output_file <<*it<<"\t\t"<<arrayOfBlock[0].getStorePage(arrayOfBlock[0])<<"\t\t"<<arrayOfBlock[1].getStorePage(arrayOfBlock[1])<<"\t\t"<<arrayOfBlock[2].getStorePage(arrayOfBlock[2])<< endl;
    }
    
    
    lackRate = (lackNum*1.0)/pageNum;
    output_file<<"-----------------------------------------"<<endl;
    output_file<<"总页数为"<<pageNum<<endl;
    output_file<<"缺页数为"<<lackNum<<endl;
    output_file<<"缺页率为："<<lackNum<<"/"<<pageNum<<"（"<<lackRate<<"）"<<endl;
    output_file<<"done!"<<endl;
    output_file.close();
    return true;
}
