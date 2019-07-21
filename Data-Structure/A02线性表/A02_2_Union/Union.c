//
//  Union.c
//  A02_2_Union
//
//  Created by qingmei2 on 2019/7/21.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#ifndef UNION_C
#define UNION_C

#include <stdio.h>
#include "Union.h"
#include "../A02_1_SequenceList/SequenceList.c"

void Union(SqList *La, SqList Lb) {
    int La_len = ListLength_Sq(*La);
    int Lb_len = ListLength_Sq(Lb);
    LElemType_Sq e;
    
    for (int i = 1; i<= Lb_len; i++) {
        GetElem_Sq(Lb, i, &e);
        if (!LocateElem_Sq(*La, e,equal)) {
            ListInsert_Sq(La, ++La_len, e);
        }
    }
}

Status equal(LElemType_Sq e1,LElemType_Sq e2){
    return e1 == e2 ? TRUE : FALSE;
}

#endif
