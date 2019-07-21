//
//  MergeSqList.c
//  A02_3_MergeSqList
//
//  Created by qingmei2 on 2019/7/21.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#include "MergeSqList.h"
#include "../A02_1_SequenceList/SequenceList.c"

void MergeSqList1(SqList la, SqList lb, SqList *lc) {
    int i,j,k;
    int La_len,Lb_len;
    
    InitList_Sq(lc);
    
    i = j = 1;
    k = 0;
    
    La_len = ListLength_Sq(la);
    Lb_len = ListLength_Sq(lb);
    
    LElemType_Sq elem_a, elem_b;
    
    while ((i <= La_len) && (j <= Lb_len)) {  // La Lb 均非空
        GetElem_Sq(la, i, &elem_a);
        GetElem_Sq(lb, j, &elem_b);
        
        if (elem_a <= elem_b) {
            ListInsert_Sq(lc, ++k, elem_a);
            i++;
        } else {
            ListInsert_Sq(lc, ++k, elem_b);
            j++;
        }
    }
    
    while (i <= La_len) {
        GetElem_Sq(la, i++, &elem_a);
        ListInsert_Sq(lc, ++k, elem_a);
    }
    
    while (j <= Lb_len) {
        GetElem_Sq(lb, j++, &elem_b);
        ListInsert_Sq(lc, ++k, elem_b);
    }
}

void MergeSqList2(SqList la, SqList lb, SqList *lc) {
    LElemType_Sq *pa, *pb, *pc;         // 三个list头元素的指针
    LElemType_Sq *pa_last, *pb_last;    // la、lb尾部元素的指针
    
    pa = la.elem;       // 初始化头指针
    pb = lb.elem;
    
    pa_last = la.elem + la.length - 1;
    pb_last = lb.elem + lb.length - 1;
    
    (*lc).listsize = (*lc).length = la.length + lb.length;
    pc = (*lc).elem = (LElemType_Sq *)malloc((*lc).listsize * sizeof(LElemType_Sq));
    
    while (pa <= pa_last && pb <= pb_last) {
        if(*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
}
