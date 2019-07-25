//
//  MergeLinkedList.h
//  A02_5_MergeLinkList
//
//  Created by qingmei2 on 2019/7/25.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#ifndef MergeLinkedList_h
#define MergeLinkedList_h


#include <stdlib.h>                                        //提供malloc、realloc、free、exit原型
#include "../A02_4_SingleLinkedList/SingleLinkedList.h"    //**▲02 线性表**//

/*━━━━━━━━━━━━━━━━━━━━━━━━┓
 ┃(01)算法2.12：C=A+B，且保持元素相对位置不变。   ┃
 ┃    Lc利用La的头结点，Lb中结点均插入新链表Lc中。┃
 ┗━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 单链表归并函数列表 */
void MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc);

#endif /* MergeLinkedList_h */
