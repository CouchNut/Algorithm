//
//  LinkNodeTest.c
//  Algorithm
//
//  Created by zte's iMac on 2018/3/30.
//  Copyright © 2018年 zte's iMac. All rights reserved.
//

#include "LinkNodeTest.h"

/**
 *  创建一个长度为 len 的链表
 *  single_link 节点的 value 值即下标值
 */
single_link * create(unsigned int len) {
    single_link *head, *p, *q;
    head = (single_link *)malloc(sizeof(single_link));
    head->p_next = NULL;
    q = head;
    for (int i = 0; i < len; i++) {
        p = (single_link *)malloc(sizeof(single_link));
        p->p_next = NULL;
        p->value = i;
        q->p_next = p;
        q = p;
    }
    return head;
}

/**
 *  创建一个长度为 len 的链表
 *  single_link 节点的 value 值即数组的值
 */
single_link * createWithArray(unsigned int len, int arr[]) {
    single_link *head, *p, *q;
    q = NULL;
    for (int i = 0; i < len; i++) {
        p = (single_link *)malloc(sizeof(single_link));
        p->p_next = NULL;
        p->value = arr[i];
        if (q == NULL) {
            q = (single_link *)malloc(sizeof(single_link));
            q = p;
        }
        else {
            single_link *tempLink = q;
            tempLink->p_next = p;
            q->p_next = tempLink;
        }
    }
    return q;
}

void linkNodeTest() {
    single_link *tempLink1 = create(10);
    single_link *tempLink2 = create(5);
    single_link *mergeLink = mergeSortedList(tempLink1, tempLink2);
    printLink(mergeLink);
    
    int arr3[3] = {1, 3, 5};
    int arr4[5] = {3, 6, 9, 11, 15};
    single_link *tempLink3 = createWithArray(3, arr3);
    single_link *tempLink4 = createWithArray(5, arr4);
    single_link *mergeLink2 = mergeSortedList(tempLink3, tempLink4);
    printLink(mergeLink2);
    
//    printLink(tempLink);
//    rPrintLink(tempLink);
//    single_link *reverseLink = reverse(tempLink);
//    printLink(reverseLink);
//    single_link *rKthNode = rGetKthNode(reverseLink, 6);
//    printLink(rKthNode);
//    single_link *middelNode = getMiddleNode(rKthNode);
//    printLink(middelNode);
}
