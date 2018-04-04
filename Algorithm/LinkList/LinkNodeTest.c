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

void linkNodeTest() {
    reverseListTest();
    mergeSortedListTest();
    rGetKthNodeTest();
    getMiddleNodeTest();
    hasCicleTest();
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

void hasCicleTest() {
    printf("===== 开始测试单链表是否有环 =====\n");
    int array[] = {1, 3, 7, 9, 13, 45};
    single_link *tempLink = createWithArray(array, sizeof(array) / sizeof(array[0]));
    single_link *crossNode = rGetKthNode(tempLink, 4);
    single_link *lastNode = rGetKthNode(tempLink, 1);
    lastNode->p_next = crossNode;
    printf("原链表：\n");
    // printLink(tempLink);  // 此处会陷入死循环，因为打印链表只能是无环链表
    int hasCircleResult = hasCircle(tempLink);
    printf("链表是否有环：%s\n", hasCircleResult != 0 ? "YES" : "NO");
    printf("===== 测试单链表是否有环结束 =====\n");
}

void reverseListTest() {
    printf("===== 开始测试单链表反转 =====\n");
    int array[] = {1, 3, 7, 9, 13, 45};
    single_link *tempLink = createWithArray(array, sizeof(array) / sizeof(array[0]));
    printf("原链表：\n");
    printLink(tempLink);
    single_link *reverseLink = reverse(tempLink);
    printf("反转之后的链表：\n");
    printLink(reverseLink);
    printf("===== 测试单链表反转结束 =====\n");
}

void mergeSortedListTest() {
    printf("===== 开始测试合并两个有序单链表 =====\n");
    int arr3[] = {1, 3, 7, 9, 13};
    int arr4[] = {5, 6, 11, 12, 15};
    int arr3_len = sizeof(arr3) / sizeof(arr3[0]);
    int arr4_len = sizeof(arr4) / sizeof(arr4[0]);
    single_link *tempLink3 = createWithArray(arr3, arr3_len);
    single_link *tempLink4 = createWithArray(arr4, arr4_len);
    printf("原链表：\n");
    printLink(tempLink3);
    printLink(tempLink4);
    single_link *mergeLink2 = mergeSortedList(tempLink3, tempLink4);
    printf("合并之后的链表：\n");
    printLink(mergeLink2);
    printf("===== 测试合并两个有序单链表结束 =====\n");
}

void rGetKthNodeTest() {
    printf("===== 开始测试获取链表的倒数第 3 个节点 =====\n");
    int arr3[] = {1, 3, 7, 9, 13};
    int arr3_len = sizeof(arr3) / sizeof(arr3[0]);
    single_link *tempLink3 = createWithArray(arr3, arr3_len);
    printf("原链表：\n");
    printLink(tempLink3);
    single_link *rKthNode = rGetKthNode(tempLink3, 3);
    printf("倒数第3个节点值为：\n%d\n", rKthNode->value);
    printf("===== 测试获取链表的倒数第 3 个节点结束 =====\n");
}

void getMiddleNodeTest(void) {
    printf("===== 开始测试获取链表的中间节点 =====\n");
    int arr3[] = {1, 3, 7, 9, 13};
    int arr3_len = sizeof(arr3) / sizeof(arr3[0]);
    single_link *tempLink3 = createWithArray(arr3, arr3_len);
    printf("原链表：\n");
    printLink(tempLink3);
    single_link *middelNode = getMiddleNode(tempLink3);
    printf("中间节点值为：\n%d\n", middelNode->value);
    printf("===== 测试获取链表的中间节点结束 =====\n");
}

