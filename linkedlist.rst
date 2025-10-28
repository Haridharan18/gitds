Linked List Implementation
==========================

The project demonstrates the implementation of a singly linked list in C.

**Functions:**
- createNode()
- insertAtBeginning()
- insertAtEnd()
- deleteNode()
- displayList()

**Usage Example:**

.. code-block:: c

    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 5);
    displayList(head);

**Compilation:**

.. code-block:: bash

    gcc main.c linked_list.c -o linkedlist
    ./linkedlist
