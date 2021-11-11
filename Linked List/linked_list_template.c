#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}Node;

Node* create_node(int value){
  
  Node *temp = NULL;
  temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL){
    printf("Memory allocation failed!!\n");
    exit(1);
  }
  
  temp->data = value;
  temp->link = NULL;
  
  return temp;
}
 
// Insert a newly created node into the first place
Node* insert_first(Node *head, int value){
    Node* temp = NULL;

    // 노드 생성
    temp = create_node(value);
    // temp가 생성 되었다면
    if (temp != NULL)
    {
        // 원래 첫번째 노드를 두번째로 만든다.
        temp->link = head;
        
        // temp 노드를 첫번째로 만든다.
        head = temp;
    }

    return head;
}
 
// Delete the first node in the linked list
// If there is only one node, head pointer will be NULL
// Otherwise, head pointer will point to the 2nd Node
Node* delete_first(Node *head){
    Node* temp = head;

    // head가 NULL이라면
    if (temp == NULL)
    {
        printf("Empty list\n");
        exit(0);
    }

    // head의 값이 NULL 아니면 2번째 노드를 가리킴
    head = temp->link;

    // 메모리 해제
    free(temp);
  
    return head;
}

// Insert a newly created node into the last place
Node* insert_last (Node* head, int value) {
    Node* temp = head;

    // 만약 Empty list 라면
    if (temp == NULL)
    {
        // 새로운 노드 생성
        temp = create_node(value);
        head = temp;

        return temp;
    }

    // 만약 Empty list가 아니라면
    // 마지막 노드 찾기
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    // 마지막 노드 연결
    temp->link = create_node(value);

    return head;
}

// 노드를 만들어서 프리가 가리키는 주소 뒤에 넣는다
Node* insert(Node* head, Node* pre, int value) {
    Node* p = (Node*)create_node(value);

    // 만약 p가 NULL 라면
    if (p == NULL)
    {
        // 메모리 할당 오류
        printf("Memory allocation failed");
        exit(0);
    }

    p->link = pre->link;
    pre->link = p;

    return head;
}

// Print all the datas from first through the last node in the list
void print_list(Node* head)
{
    // temp를 첫번째 노드로
    Node* temp = head;

    // list가 비어있다면
    if (temp == NULL)
    {
        printf("List is empty\n");
    }

    // list가 비어있지 않다면
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        // temp를 다음 노드로 옮김
        temp = temp->link;
    }

    printf("\n");
    return;
}

int main() {

    Node *head = NULL;
  
    head = insert_first(head, 10);
    head = insert_first(head, 20);
    head = insert_last(head, 7);
    head = insert_first(head, 30);
    head = insert(head, head->link->link->link, 25);

    print_list(head);

    head = delete_first(head);
    print_list(head);
    head = delete_first(head);
    print_list(head);
    head = delete_first(head);
    print_list(head);
    head = delete_first(head);
    print_list(head);

    head = insert_last(head, 100);

    print_list(head);

    return 0;
}