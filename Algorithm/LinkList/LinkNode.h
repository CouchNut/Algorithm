//
//  LinkNode.h
//  Algorithm
//
//  Created by zte's iMac on 2018/3/30.
//  Copyright © 2018年 zte's iMac. All rights reserved.
//

#ifndef LinkNode_h
#define LinkNode_h

#include <stdio.h>

struct LinkNode {
    int value;
    struct LinkNode *p_next;
};

typedef struct LinkNode single_link;

/**
 * 顺序打印链表
 */
void printLink(single_link *pHead);

/**
 * 从尾到头打印(倒序打印)
 */
void rPrintLink(single_link *pHead);

/**
 * 获取链表长度（节点个数）
 */
unsigned int length(single_link *pHead);

/**
 * 反转单链表
 */
single_link * reverse(single_link *pHead);

/**
 * 获取链表的倒数第 k 个节点
 */
single_link * rGetKthNode(single_link *pHead, unsigned int k);

/**
 * 获取单链表中间节点，若链表长度为 n, 则返回第 n/2+1 个节点
 */
single_link *getMiddleNode(single_link *pHead);

/**
 * 将两个各自有序的单链表合并为一个有序的单链表
 */
single_link *mergeSortedList(single_link *pFirstNode, single_link *pSecondNode);

/**
 *  将数组转为链表返回
 */
single_link * createWithArray(int arr[], int len);

#endif /* LinkNode_h */
