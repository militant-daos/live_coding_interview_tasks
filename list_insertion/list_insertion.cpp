/*
 * Given: a linked list of ListNode items,
 *        a new ListNode item, N - insert
 *        position.
 * Task: implement a function which inserts
 *       a node into the given linked list.
 */

#include <iostream>

struct ListNode
{
    int data;
    ListNode* next;
};

ListNode* insert_node_at(ListNode* head, ListNode* to_insert, int pos)
{
    if (pos < 0)
    {
        // We insert before the list head.
        to_insert->next = head;
        return to_insert; // Return the new head.
    }

    ListNode* ins_pos = head;

    for (int i = 0; i < pos; ++i)
    {
        if (ins_pos->next == nullptr)
        {
            break;
        }

        ins_pos = ins_pos->next;
    }

    // Do we insert the node after the tail?
    if (ins_pos->next == nullptr)
    {
        ins_pos->next = to_insert;
        return head; // Return the new head.
    }

    auto next_next = ins_pos->next;
    ins_pos->next = to_insert;
    to_insert->next = next_next;

    return head;
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

    std::cout << "Created " << num_nodes << " nodes" << std::endl;
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
    auto l = make_list(10);
    
    std::cout << "Original list: ";
    print_list(l);

    ListNode* node1 = new ListNode;
    node1->data = 42;

    auto r = insert_node_at(l, node1, 8);
    std::cout << "Modified list: ";
    print_list(r);

    delete_list(r);
}

