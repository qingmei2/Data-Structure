//
//  MergeLinkedList.c
//  A02_5_MergeLinkList
//
//  Created by qingmei2 on 2019/7/25.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#include <stdio.h>

#include "MergeLinkedList.h"
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃(01)算法2.12：C=A+B，且保持元素相对位置不变。   ┃
 ┃    Lc利用La的头结点，Lb中结点均插入新链表Lc中。┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 单链表归并函数列表 */
void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc) {
    
    // 已知单链线性表La Lb 元素按值非递减排列
    LinkList pa, pb, pc;
    
    pa = (*La) -> next;
    pb = (*Lb) -> next;
    
    while (pa && pb) {
        if (pa -> data <= pb -> data) {
            pc -> next = pa;
            pa = pa -> next;
        } else {
            pc -> next = pb;
            pb = pb -> next;
        }
        pc = pc -> next;
    }
    pc -> next = pa ? pa : pb;
    free(*La);
    free(*Lb);
}
