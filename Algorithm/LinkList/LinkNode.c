//
//  LinkNode.c
//  Algorithm
//
//  Created by zte's iMac on 2018/3/30.
//  Copyright © 2018年 zte's iMac. All rights reserved.
//

#include "LinkNode.h"

// 输出链表
void printLink(single_link *pHead) {
    if (pHead == NULL) {
        printf("NULL\n");
        return;
    }
    single_link *temp = pHead;
    while (temp != NULL) {
        if (temp->p_next == NULL)
            printf("%d\n", temp->value);
        else
            printf("%d ", temp->value);
        temp = temp->p_next;
    }
}

// 获取链表长度（节点个数）
unsigned int length(single_link *pHead) {
    if (pHead == NULL)
        return 0;
    unsigned int length = 0;
    single_link *temp_link = pHead;
    while (temp_link != NULL) {
        length ++;
        temp_link = temp_link->p_next;
    }
    return length;
}

// 反转单链表
single_link * reverse(single_link *pHead) {
    if (pHead == NULL || pHead->p_next == NULL)
        return pHead;
    single_link *reverseLink = NULL;
    single_link *currentLink = pHead;
    while (currentLink != NULL) {
        single_link *tempLink = currentLink;
        currentLink = currentLink->p_next;
        tempLink->p_next = reverseLink;
        reverseLink = tempLink;
    }
    return reverseLink;
}

// 获取链表的倒数第 k 个节点
single_link * rGetKthNode(single_link *pHead, unsigned int k) {
    if (k == 0 || pHead == NULL)
        return NULL;
    single_link *pAhead = pHead;
    single_link *pBehind = pHead;
    while (k > 1 && pAhead != NULL) {
        pAhead = pAhead->p_next;
        k--;
    }
    if (k > 1 || pAhead == NULL)
        return NULL;
    while (pAhead->p_next != NULL) {
        pBehind = pBehind->p_next;
        pAhead = pAhead->p_next;
    }
    return pBehind;
}

// 获取单链表中间节点，若链表长度为 n, 则返回第 n/2+1 个节点
single_link *getMiddleNode(single_link *pHead) {
    if (pHead == NULL || pHead->p_next == NULL)
        return pHead;
    single_link *pAhead = pHead;
    single_link *pBehind = pHead;
    while(pAhead->p_next != NULL) {
        pAhead = pAhead->p_next;
        pBehind = pBehind->p_next;
        if (pAhead->p_next != NULL)
            pAhead = pAhead->p_next;
    }
    return pBehind;
}
