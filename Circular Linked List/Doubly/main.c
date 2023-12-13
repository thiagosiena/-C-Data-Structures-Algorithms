#include "List.h"
#include <stdio.h>

int main()
{
    List *list = list_create();

    list_add(list, 10);
    list_add(list, 20);
    list_add(list, 30);

    printf("List: ");
    list_display(list);

    list_set(list, 1, 25);


    printf("List after setting index 1 to 25: ");
    list_display(list);

    list_insert(list, 2, 15);

    printf("List after inserting 15 at index 2: ");
    list_display(list);

    int removed = list_remove(list, 1);

    printf("List after removing index 1 (value removed: %d): ", removed);
    list_display(list);

    list_free(list);

    system("pause");
    
    return 0;
}