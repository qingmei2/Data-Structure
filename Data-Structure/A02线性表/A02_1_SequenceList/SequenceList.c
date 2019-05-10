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

// 算法2.3
Status InitList_Sq(SqList *L)
{
    (*L).elem = (LElemType_Sq*) malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
    if(!(*L).elem)
        exit(OVERFLOW);     // 内存分配失败
    (*L).length = 0;                // 初始化顺序表长度为0
    (*L).listsize = LIST_INIT_SIZE; // 顺序表初始内存分配量
    return OK;
}

void ClearList_Sq(SqList *L)
{
    (*L).length = 0;
}

void DestoryList_Sq(SqList *L)
{
    free((*L).elem);
    
    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listsize = 0;
}

Status ListEmpty_Sq(SqList L)
{
    return L.length == 0 ? TRUE : FALSE;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

Status GetElem_Sq(SqList q, int i, LElemType_Sq *e)
{
    if(i < 1 || i > q.length)
        return ERROR;
    else
        *e = q.elem[i-1];
    
    return OK;
}

// 算法2.6 返回顺序表L中首个与e满足Compare关系的元素位序
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
{
    int i = 1;
    
    while (i <= L.length && !Compare(e, L.elem[i-1])) {
        ++i;
    }
    
    if(i <= L.length){
        return i;
    }
    return 0;
}

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
    if(L.elem[0] != cur_e) {    // 第一个节点没有前驱
        int i = 1;
        while(i < L.length && L.elem[i] != cur_e){
            i++;
        }
        
        if(i < L.length){
            *pre_e = L.elem[i - 1];   // 用pre_e接收cur_e的前驱
            return OK;
        }
    }
    
    return ERROR;
}

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
    int i = 0;
    
    while(i < L.length && L.elem[i] != cur_e)
        i++;
    
    
    if(i < L.length - 1){   // 最后一个节点无后继
        *next_e = L.elem[i + 1];
        return OK;
    }
    
    return ERROR;
}

// 算法2.4 在顺序表的第i个位置上插入e
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
    LElemType_Sq *newbase;
    LElemType_Sq *p, *q;
    
    if(i < 1 || i > (*L).length + 1)
        return ERROR;                   // i值不合法
    
    if((*L).length >= (*L).listsize)
    {
        newbase = realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(LElemType_Sq));
        
        if(!newbase)
            return OVERFLOW;
        
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    
    q = &(*L).elem[i - 1];  // q为插入位置
    
    for(p = &(*L).elem[(*L).length - 1]; p >= q; --p)
        *(p+1) = *p;
    
    *q = e;
    (*L).length++;
    return OK;
}

// 算法2.5 删除顺序表上第i个元素，并用e返回
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq e)
{
    LElemType_Sq *p, *q;
    
    if(i < 1 || i > (*L).length)
        return ERROR;
    
    p = &(*L).elem[i - 1];
//    *p = (*L).elem[i - 1];
    *e = *p;
    q = (*L).elem + (*L).length - 1;
    
    for(++p; p <= q; p++)
        *(p - 1) = *p;
    
    (*L).length--;
    
    return OK;
}

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq))
{
    int i;
    
    for (i = 0; i < L.length; i++) {
        Visit(L.elem[i]);
    }
    
    return OK;
}

#endif
