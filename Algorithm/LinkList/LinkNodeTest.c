//
//  LinkNodeTest.c
//  Algorithm
//
//  Created by zte's iMac on 2018/3/30.
//  Copyright © 2018年 zte's iMac. All rights reserved.
//

#include "LinkNodeTest.h"

// 创建一个长度为 len 的链表
single_link * create(unsigned int len) {
    single_link *head, *p, *q;
    head = (single_link *)malloc(sizeof(single_link));
    head->p_next = NULL;
    q = head;
    for (int i = 1; i < len; i++) {
        p = (single_link *)malloc(sizeof(single_link));
        p->p_next = NULL;
        p->value = i;
        q->p_next = p;
        q = p;
    }
    return head;
}

void linkNodeTest() {
    single_link *tempLink = create(10);
    printLink(tempLink);
    single_link *reverseLink = reverse(tempLink);
    printLink(reverseLink);
    single_link *rKthNode = rGetKthNode(reverseLink, 6);
    printLink(rKthNode);
    single_link *middelNode = getMiddleNode(rKthNode);
    printLink(middelNode);
}
