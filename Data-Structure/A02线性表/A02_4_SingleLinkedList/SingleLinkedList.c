//
//  SingleLinkedList.c
//  A02_4_SingleLinkedList
//
//  Created by qingmei2 on 2019/7/24.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#include <stdio.h>
#include "SingleLinkedList.h"
#include "../../A01绪论/Status.h"

Status InitList_L(LinkList *L){
    (*L) = (LinkList)malloc(sizeof(LNode));
    if(!(*L)) {
        exit(OVERFLOW);
    }
    (*L) -> next = NULL;
    return OK;
}

Status ClearList_L(LinkList L){
    LinkList pre, next;
    
    if(!L)
        return ERROR;
    
    pre = L -> next;
    
    while(pre) {
        next = pre -> next;
        free(pre);
        pre = next;
    }
    
    L -> next = NULL;
    
    return OK;
}

void DestroyList_L(LinkList *L) {
    LinkList pre = (*L);
    
    while (pre) {
        pre = (*L) -> next;
        free(*L);
        (*L) = pre;
    }
}

Status ListEmpty_L(LinkList L) {
    // 链表存在且只有头结点
    return (L != NULL && L -> next == NULL) ? TRUE : FALSE;
}

int ListLength_L(LinkList L) {
    LinkList p;
    int i = 0;
    
    if(L) {
        p = L -> next;
        while (p) {
            p = p -> next;
            i++;
        }
    }
    return i;
}

/*════╗
 ║ 算法2.8║
 ╚════*/
Status GetElem_L(LinkList L, int i, LElemType_L *e) {
    LinkList p;
    int j = 1;
    
    p = L -> next;
    while(p && i > j) {
        p = p -> next;
        j++;
    }
    
    if(!p || i < j) return ERROR;
    *e = p -> data;
    return OK;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃(07)返回单链表L中第一个与e满足Compare关系的元素位序。 ┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L)) {
    int i;
    LinkList p;
    
    i = -1;
    
    if (L) {
        p = L -> next;
        i = 0;
        while (p) {
            i++;
            if (Compare(e, p -> data) == OK) {
                break;
            }else{
                p = p -> next;
                if(p == NULL)
                    i++;
            }
        }
    }
    
    return i;
}

/*━━━━━━━━━━━━━━┓
 ┃(08)用pre_e接收cur_e的前驱。┃
 ┗━━━━━━━━━━━━━━*/
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e) {
    LinkList p, suc;
    if(L) {
        p = L -> next;
        if(p -> data != cur_e){     // 第一个结点无前驱，因此需要额外判断
            while(p -> next) {      // 若p结点有后继
                suc = p -> next;    // suc指向p的后继
                if(suc -> data == cur_e){
                    *pre_e = p -> data;
                    return OK;
                }
                p = suc;
            }
        }
    }
    return ERROR;
}

/*━━━━━━━━━━━━━━━┓
 ┃(09)用next_e接收cur_e的后继。 ┃
 ┗━━━━━━━━━━━━━━━*/
Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e) {
    LinkList p, suc;
    if(L) {
        p = L -> next;
        while(p){
            suc = p -> next;
            if(!suc) {
                return ERROR;
            }
            
            if(p -> data == cur_e){
                if(suc) {
                    *next_e = suc -> data;
                    return OK;
                } else {
                    return ERROR;
                }
            }
            p = suc;
        }
    }
    return OK;
}

/*━━━━━━━━━━━━━━━━━━━━━┓
 ┃(10)算法2.9：在单链表L第i个位置之前插入e。┃
 ┗━━━━━━━━━━━━━━━━━━━━━*/
Status ListInsert_L(LinkList L, int i, LElemType_L e) {
    int n = 0;
    LinkList p, s;
    
    p = L;

    while (p && n < i - 1) {
        p = p -> next;
        n++;
    }

    if(!p || n > i - 1){
        return ERROR;
    }

    s = (LinkList)malloc(sizeof(LNode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃(11)算法2.10：删除单链表L第i个位置的值，并用e接收。 ┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/
Status ListDelete_L(LinkList L, int i, LElemType_L *e) {
    int n = 0;
    LinkList p, q;
    
    p = L;

    while (p && n < i - 1) {
        p = p -> next;
        n++;
    }
    
    if(!(p -> next) || n > i - 1)
        return ERROR;
    
    q = p -> next;
    p -> next = q -> next;  // p -> next = NULL;
    *e = q -> data;
    free(q);
    return OK;
}

/*━━━━━━━━━━━━━━┓
 ┃(12)用Visit函数访问单链表L。┃
 ┗━━━━━━━━━━━━━━*/
Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L)) {
    if(!L){
        return ERROR;
    }
    
    LinkList p = L -> next;
    
    while (p) {
        Visit(p -> data);
        p = p -> next;
    }
    
    return OK;
}
