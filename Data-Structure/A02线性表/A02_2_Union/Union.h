//
//  Union.h
//  Data-Structure
//
//  Created by qingmei2 on 2019/7/21.
//  Copyright © 2019 qingmei2. All rights reserved.
//

#ifndef UNION_H
#define UNION_H

#include <stdlib.h>             // 提供malloc、realloc、free、exit原型
#include "../A02_1_SequenceList/SequenceList.h"

/* 并集函数列表 */
void Union(SqList *La, SqList Lb);
/*━━━━━━━━━━━┓
 ┃(01)算法2.1：A=A∪B。 ┃
 ┗━━━━━━━━━━━*/

Status equal(LElemType_Sq e1, LElemType_Sq e2);
/*━━━━━━━━━━━━┓
 ┃(02)判断两元素是否相等。┃
 ┗━━━━━━━━━━━━*/

#endif /* Union_h */
