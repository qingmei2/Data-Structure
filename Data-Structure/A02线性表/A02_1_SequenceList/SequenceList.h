//
//  顺序表相关操作列表
//
//  Created by qingmei2 on 2019/5/7.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>
#include <stdlib.h>             // 提供malloc、realloc、free、exit原型
#include "../../A01绪论/Status.h"

// 宏定义
#define LIST_INIT_SIZE 100      // 顺序表存储空间的初始分配量
#define LISTINCREMENT  10       // 顺序表存储空间的分配增量

#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct {
    LElemType_Sq *elem;     // 存储空间基址（指向第一个节点的指针）
    int length;             // 当前顺序表长度
    int listsize;           // 当前分配的存储容量
} SqList;                   // 顺序表0号单元正常使用

// 算法2.3 初始化空顺序表
Status InitList_Sq(SqList *L);

// 清空顺序表
void ClearList_Sq(SqList *L);

// 销毁顺序表
void DestoryList_Sq(SqList *L);

// 判断顺序表是否为空
Status ListEmpty_Sq(SqList L);

// 获取顺序表中的元素个数
int ListLength_Sq(SqList L);

// 用e接收顺序表中的第i个元素
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);

// 算法2.6 返回顺序表L中首个与e满足Compare关系的元素位序
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));

// 用pre_e接收cur_e的前驱
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);

// 用next_e接收cur_e的后继
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);

// 算法2.4 在顺序表的第i个位置上插入e
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

// 算法2.5 删除顺序表上第i个元素，并用e返回
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);

// 用visit函数访问数据表L
Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq));

#endif /* SequenceList_h */
