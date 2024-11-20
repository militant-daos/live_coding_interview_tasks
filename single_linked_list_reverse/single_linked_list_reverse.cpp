/*
 * Given: a singly-linked list.
 * Task: reverse the given list with
 *       O(n) complexity algorithm.
 */
#include <iostream>

struct ListNode
{
    int data;
    ListNode* next;
};

ListNode* reverse_list(ListNode* list_head)
{
    ListNode* current = list_head;
    ListNode* prev = nullptr;
    ListNode* next = current->next;

    while (true)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        
        if (next == nullptr)
        {
            break;
        }

        current = next;
    }

    return current;
}

ListNode* make_list(int num_nodes)
{
    ListNode* head = nullptr;
    ListNode* curr = nullptr;

    for (int i = 0; i < num_nodes; ++i)
    {
        ListNode* p = new ListNode;
        p->data = i; // Dummy payload;
        if (curr == nullptr)
        {
            curr = p;
            curr->next = nullptr;
            head = curr;
        }
        else
        {
            curr->next = p; // Make current pointing at the allocated
                            // next node p.
            curr = p; // Advance the current node to the next = p.
        }
    }

    return head;
}

void print_list(ListNode* head)
{
    while(head != nullptr)
    {
        std::cout << head->data << "->";
        head = head->next;
    }

    std::cout << "NULL" << std::endl;
}

void delete_list(ListNode* head)
{
    auto ptr = head;
    auto next = head;
    int num = 0;
    
    while(ptr != nullptr)
    {
        next = ptr->next;
        delete ptr;
        ptr = next;
        ++num;
    }

    std::cout << "Deleted " << num << " nodes" << std::endl;
}

int main()
{
    auto l = make_list(30);
    
    std::cout << "Original list: ";
    print_list(l);

    auto r = reverse_list(l);
    std::cout << "Reversed list: ";
    print_list(r);

    delete_list(r);
}
