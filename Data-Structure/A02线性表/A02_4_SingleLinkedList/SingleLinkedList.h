//
//  SingleLinkedList.h
//  Data-Structure
//
//  Created by qingmei2 on 2019/7/24.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include "../../A01绪论/Status.h"

/* 单链表类型定义 */
#ifndef BANKQUEUING_H       /*后续的模拟银行排队算法中，此类型需要重新定义*/
typedef int LElemType_L;

/* 单链表结构体 */
typedef struct LNode {
    LElemType_L data;
    struct LNode* next;
}LNode;

typedef LNode* LinkList;
#endif

/* 单链表（带头结点）函数列表 */
Status InitList_L(LinkList *L);
/*━━━━━━━━━━┓
 ┃(01)初始化单链表L。 ┃
 ┗━━━━━━━━━━*/

Status ClearList_L(LinkList L);
/*━━━━━━━━━━━━━━━┓
 ┃(02)置空单链表L，头结点保留。 ┃
 ┗━━━━━━━━━━━━━━━*/

void DestroyList_L(LinkList *L);
/*━━━━━━━━━━━━━━━━━━━┓
 ┃(03)销毁单链表L，连同通结点一起销毁。 ┃
 ┗━━━━━━━━━━━━━━━━━━━*/

Status ListEmpty_L(LinkList L);
/*━━━━━━━━━━━━━━━┓
 ┃(04)判断单链表L是否为空。     ┃
 ┗━━━━━━━━━━━━━━━*/

int ListLength_L(LinkList L);
/*━━━━━━━━━━━━┓
 ┃(05)返回单链表L元素个数 ┃
 ┗━━━━━━━━━━━━*/

Status GetElem_L(LinkList L, int i, LElemType_L *e);
/*━━━━━━━━━━━━━━━━━━━┓
 ┃(06)算法2.8：用e接收单链表L中第i个元素┃
 ┗━━━━━━━━━━━━━━━━━━━*/

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L));
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃(07)返回单链表L中第一个与e满足Compare关系的元素位序。 ┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);
/*━━━━━━━━━━━━━━┓
 ┃(08)用pre_e接收cur_e的前驱。┃
 ┗━━━━━━━━━━━━━━*/

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);
/*━━━━━━━━━━━━━━━┓
 ┃(09)用next_e接收cur_e的后继。 ┃
 ┗━━━━━━━━━━━━━━━*/

Status ListInsert_L(LinkList L, int i, LElemType_L e);
/*━━━━━━━━━━━━━━━━━━━━━┓
 ┃(10)算法2.9：在单链表L第i个位置之前插入e。┃
 ┗━━━━━━━━━━━━━━━━━━━━━*/

Status ListDelete_L(LinkList L, int i, LElemType_L *e);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃(11)算法2.10：删除单链表L第i个位置的值，并用e接收。 ┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));
/*━━━━━━━━━━━━━━┓
 ┃(12)用Visit函数访问单链表L。┃
 ┗━━━━━━━━━━━━━━*/

#endif /* SingleLinkedList_h */
