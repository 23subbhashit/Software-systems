#include<stdio.h>
#include<unistd.h>
#include <sys/resource.h>
void main()
{
	int p,q;
	p = getpriority(PRIO_PROCESS,0);
    printf("Current Priority = %d\n",p);
    nice(5);
    q = getpriority(PRIO_PROCESS,0);
    printf("New Priority = %d\n",q);

}