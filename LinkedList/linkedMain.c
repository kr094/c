#include <time.h>
#include <pthread.h>
#include "List.h"
#include "cgetl.h"

int main(void)
{
	unsigned int total_time_ticks = 0;
	
	//Begin tracking time
	clock_t time_a = clock();
	
    List* list = (List*) malloc(sizeof(List));
    list->head = 0;
    list->size = 0;
    int i;
    
    add_b(list, 3);
    add_b(list, 25);
    
    for(i = 0; i < 35000; i++)
    {
          int r = (rand() % 350000) + 1;
          add(list, r);
		  printf("%d\n", list->size);
    }
    
    //Stop
    clock_t time_b = clock();
    
    if (time_a == ((clock_t)-1) || time_b == ((clock_t)-1))
	{
	    perror("Unable to calculate elapsed time");
	}
	else
	{
	    total_time_ticks = (unsigned int)(time_b - time_a);
	}
    printf("Done!\r\nTotal Time: %dms.\n", total_time_ticks);
    //printList(list);  
    cleanUp(list);
    cgetl();
    return 0;
}
