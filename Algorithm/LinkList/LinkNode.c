//
//  LinkNode.c
//  Algorithm
//
//  Created by zte's iMac on 2018/3/30.
//  Copyright © 2018年 zte's iMac. All rights reserved.
//

#include "LinkNode.h"

/**
 * 顺序打印链表
 */
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

/**
 * 从尾到头打印(倒序打印)
 * 递归调用，调换最后两句代码可改为正序打印。
 */
void rPrintLink(single_link *pHead) {
    if (pHead == NULL) {
        return;
    }
    rPrintLink(pHead->p_next);
    printf("%d ", pHead->value);
}

/**
 * 获取链表长度（节点个数）
 */
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

/**
 * 反转单链表
 */
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

/**
 * 获取链表的倒数第 k 个节点
 */
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

/**
 * 获取单链表中间节点，若链表长度为 n, 则返回第 n/2+1 个节点
 */
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

/**
 * 将两个各自有序的单链表合并为一个有序的单链表
 */
single_link *mergeSortedList(single_link *pFirstNode, single_link *pSecondNode) {
    if (pFirstNode == NULL) {
        return pSecondNode;
    }
    if (pSecondNode == NULL) {
        return pFirstNode;
    }
    single_link *mergeList = NULL;
    if (pFirstNode->value < pSecondNode->value) {
        mergeList = pFirstNode;
        pFirstNode = pFirstNode->p_next;
        mergeList->p_next = NULL;
    }
    else {
        mergeList = pSecondNode;
        pSecondNode = pSecondNode->p_next;
        mergeList->p_next = NULL;
    }
    single_link *tempLink = mergeList;
    while (pFirstNode != NULL && pSecondNode != NULL) {
        if (pFirstNode->value < pSecondNode->value) {
            tempLink->p_next = pFirstNode;
            pFirstNode = pFirstNode->p_next;
            tempLink = tempLink->p_next;
            tempLink->p_next = NULL;
        }
        else {
            tempLink->p_next = pSecondNode;
            pSecondNode = pSecondNode->p_next;
            tempLink = tempLink->p_next;
            tempLink->p_next = NULL;
        }
    }
    if (pFirstNode != NULL) {
        tempLink->p_next = pFirstNode;
    }
    else if (pSecondNode != NULL) {
        tempLink->p_next = pSecondNode;
    }
    return mergeList;
}

/**
 *  将数组转为链表返回
 */
single_link * createWithArray(int arr[], int len) {
    single_link *result_Link, *tempLink;
    result_Link = (single_link *)malloc(sizeof(single_link));
    result_Link->p_next = NULL;
    tempLink = result_Link;
    for (int i = 0; i < len; i++) {
        single_link *link = (single_link *)malloc(sizeof(single_link));
        link->p_next = NULL;
        link->value = arr[i];
        tempLink->p_next = link;
        tempLink = link;
    }
    result_Link = result_Link->p_next;
    return result_Link;
}

/**
 *  判断一个单链表中是否有环
 *  返回结果：
 *      1 -> YES; 0 -> NO;
 */
int hasCircle(single_link *pHead) {
    single_link *pFast = pHead;
    single_link *pSlow = pHead;
    while (pFast != NULL && pSlow != NULL) {
        pFast = pFast->p_next->p_next;
        pSlow = pSlow->p_next;
        if (pFast == pSlow) {
            return 1;
        }
    }
    return 0;
}

/**
 *  判断两个单链表是否相交
 *  返回结果：
 *      1 -> YES; 0 -> NO;
 */
int isIntersected(single_link *pFirtst, single_link *pSecond) {
    if (pFirtst == NULL || pSecond == NULL) {
        return 0;
    }
    single_link *pTrailFirst = pFirtst;
    while (pTrailFirst->p_next != NULL) {
        pTrailFirst = pTrailFirst->p_next;
    }
    single_link *pTrailSecond = pSecond;
    while (pTrailSecond->p_next != NULL) {
        pTrailSecond = pTrailSecond->p_next;
    }
    return pTrailSecond == pTrailFirst;
}

/**
 *  获取两个单链表相交的第一个节点
 */
single_link *getFirstCommonNode(single_link *pFirtst, single_link *pSecond) {
    if (pFirtst == NULL || pSecond == NULL) {
        return NULL;
    }
    unsigned int firstLen = 0;
    single_link *pTrailFirst = pFirtst;
    while (pTrailFirst->p_next != NULL) {
        pTrailFirst = pTrailFirst->p_next;
        firstLen++;
    }
    unsigned int secondLen = 0;
    single_link *pTrailSecond = pSecond;
    while (pTrailSecond->p_next != NULL) {
        pTrailSecond = pTrailSecond->p_next;
        secondLen++;
    }
    if (pTrailFirst != pTrailSecond) {
        return NULL;
    }
    single_link *pNode1 = pFirtst;
    single_link *pNode2 = pSecond;
    if (firstLen > secondLen) {
        int k = firstLen - secondLen;
        while (k--) {
            pNode1 = pNode1->p_next;
        }
    }
    else {
        int k = secondLen - firstLen;
        while (k--) {
            pNode2 = pNode2->p_next;
        }
    }
    while (pNode2 != pNode1) {
        pNode2 = pNode2->p_next;
        pNode1 = pNode1->p_next;
    }
    return pNode1;
}

/**
 *  已知一个单链表中存在环，求进入环中的第一个节点
 */
single_link *getFitstNodeInCircle(single_link *pHead) {
    if (pHead == NULL || pHead->p_next == NULL) {
        return NULL;
    }
    single_link *pFastNode = pHead;
    single_link *pSlowNode = pHead;
    while (pFastNode != NULL || pFastNode->p_next != NULL) {
        pFastNode = pFastNode->p_next->p_next;
        pSlowNode = pSlowNode->p_next;
        if (pFastNode == pSlowNode) {
            break;
        }
    }
    if (pSlowNode == NULL || pSlowNode->p_next == NULL) {
        return NULL;
    }
    single_link *pAssumedTrail = pSlowNode;
    single_link *pHead1 = pHead;
    single_link *pHead2 = pAssumedTrail->p_next;
    single_link *pNode1 = pHead1;
    unsigned int node1Len = 0;
    while (pNode1 != pAssumedTrail) {
        pNode1 = pNode1->p_next;
        node1Len ++;
    }
    single_link *pNode2 = pHead2;
    unsigned int node2Len = 0;
    while (pNode2 != pAssumedTrail) {
        pNode2 = pNode2->p_next;
        node2Len ++;
    }
    pNode1 = pHead1;
    pNode2 = pHead2;
    if (node1Len > node2Len) {
        unsigned int k = node1Len - node2Len;
        while (k--) {
            pNode1 = pNode1->p_next;
        }
    }
    else {
        unsigned int k = node2Len - node1Len;
        while (k--) {
            pNode2 = pNode2->p_next;
        }
    }
    while (pNode1 != pNode2) {
        pNode1 = pNode1->p_next;
        pNode2 = pNode2->p_next;
    }
    return pNode1;
}

/**
 *  删除链表中的某个节点
 */
void deleteNode(single_link *pHead, single_link *toBeDeleteNode) {
    if (toBeDeleteNode == NULL) {
        return;
    }
    if (toBeDeleteNode->p_next != NULL) {
        toBeDeleteNode->value = toBeDeleteNode->p_next->value;
        toBeDeleteNode->p_next = toBeDeleteNode->p_next->p_next;
    }
    else {
        if (pHead == toBeDeleteNode) {
            pHead = NULL;
        }
        else {
            single_link *pNode = pHead;
            while (pNode->p_next != toBeDeleteNode) {
                pNode = pNode->p_next;
            }
            pNode->p_next = NULL;
        }
    }
}
