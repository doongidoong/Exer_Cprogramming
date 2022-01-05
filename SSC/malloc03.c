#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
���� ����ڰ� ������ ���ؼ� �� ���� �Է��� �� �ް� ������ 
���Ӱ� �����Ҵ��� �ϸ� ������ ������ 1000 �� �� �����Ͱ� �ִµ� 1 ���� �߰����� �����͸� ���� 
1001 ���� ���� ������ ���� ������ ��ȿ����,

���� �̸� �ذ��ϴ� ���� �ٷ� '���' */


struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy, struct Node* head);
struct Node* CreateNode(int data);
void PrintNodeFrom(struct Node* from);

struct Node {
  int data;              /* ������ */
  struct Node* nextNode; /* ���� ��带 ����Ű�� �κ� */
};
int main() {
  struct Node* Node1 = CreateNode(100);
  struct Node* Node2 = InsertNode(Node1, 200);
  struct Node* Node3 = InsertNode(Node2, 300);
  /* Node 2 �ڿ� Node4 �ֱ� */
  struct Node* Node4 = InsertNode(Node2, 400);

  PrintNodeFrom(Node1);
  return 0;
}
void PrintNodeFrom(struct Node* from) {
  /* from �� NULL �� �� ����,
     �� �� �κп� ������ �� ���� ��� */
  while (from) {
    printf("����� ������ : %d \n", from->data);
    from = from->nextNode;
  }
}
/* current ��� ��� �ڿ� ��带 ���� ����� �ִ� �Լ� */
struct Node* InsertNode(struct Node* current, int data) {
  /* current ��尡 ����Ű�� �ִ� ���� ��尡 after �̴� */
  struct Node* after = current->nextNode;

  /* ���ο� ��带 �����Ѵ� */
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  /* �� ��忡 ���� �־��ش�. */
  newNode->data = data;
  newNode->nextNode = after;

  /* current �� ���� newNode �� ����Ű�� �ȴ� */
  current->nextNode = newNode;

  return newNode;
} /* ���õ� ��带 �ı��ϴ� �Լ� */
void DestroyNode(struct Node* destroy,
                 struct Node* head) { /* ���� ��带 ����ų ������*/
  struct Node* next = head;           /* head �� �ı��Ϸ� �Ѵٸ� */
  if (destroy == head) {
    free(destroy);
    return;
  }              /* ���� next �� NULL �̸� ���� */
  while (next) { /* ���� next ���� ��尡 destroy ��� next �� destory �� ���*/
    if (next->nextNode == destroy) { /* ���� next �� ���� ���� destory ��
                                        �ƴ϶� destroy �� ���� ��尡 �ȴ�. */
      next->nextNode = destroy->nextNode;
    } /* next �� ���� ��带 ����Ų��. */
    next = next->nextNode;
  }
  free(destroy);
}
/* �� ��带 ����� �Լ� */
struct Node* CreateNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->nextNode = NULL;

  return newNode;
}