//
//  SequenceList.c
//  A02_1_SequenceList
//
//  Created by qingmei2 on 2019/5/7.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#ifndef SequenceList_c
#define SequenceList_c

#include <SequenceList.h>

Status InitList_Sq(SqList *L)
{
    (*L).elem = (LElemType_Sq*) malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
    if(!(*L).elem)
        exit(OVERFLOW);     // 内存分配失败
    (*L).length = 0;                // 初始化顺序表长度为0
    (*L).listsize = LIST_INIT_SIZE; // 顺序表初始内存分配量
    return OK;
}
