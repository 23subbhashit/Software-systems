/*
============================================================================
Name : 20.c
Author : Subbhashit 
Description : 
        20. Find out the priority of your running program. Modify the priority with nice command.            
Date: 18th Aug, 2023.
============================================================================
*/
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