//
//  LinkNodeTest.c
//  Algorithm
//
//  Created by zte's iMac on 2018/3/30.
//  Copyright © 2018年 zte's iMac. All rights reserved.
//

#include "LinkNodeTest.h"

int Random(int start, int end){
    int dis = end - start;
    return rand() % dis + start;
}


/**
 *  创建一个长度为 len 的链表
 *  single_link 节点的 value 值随机生成
 */
single_link * create(unsigned int len) {
    single_link *head, *p, *q;
    head = (single_link *)malloc(sizeof(single_link));
    head->p_next = NULL;
    q = head;
    for (int i = 0; i < len; i++) {
        p = (single_link *)malloc(sizeof(single_link));
        p->p_next = NULL;
        p->value = i + Random(0, 65535);
        q->p_next = p;
        q = p;
    }
    return head;
}

void linkNodeTest() {
//    single_link *tempLink1 = create(10);
//    single_link *tempLink2 = create(5);
//    single_link *mergeLink = mergeSortedList(tempLink1, tempLink2);
//    printLink(mergeLink);
    
    int arr3[] = {1, 3, 7, 9, 13};
    int arr4[] = {5, 6, 11, 12, 15};
    int arr3_len = sizeof(arr3) / sizeof(arr3[0]);
    int arr4_len = sizeof(arr4) / sizeof(arr4[0]);
    single_link *tempLink3 = createWithArray(arr3, arr3_len);
    single_link *tempLink4 = createWithArray(arr4, arr4_len);
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
