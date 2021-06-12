/* Name: Aditi Sejal
   Roll_Number: 2019228 */
#define _GNU_SOURCE
#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#define SYS_sh_task_info 440

int main()
{
  long stats;
  pid_t pid;
  char errmsg[500];
  pid = getppid();	//by default pass this to check 
  // pid = -3; //for invalid pid error
  // pid = 10000; //for process not running error 
  stats = syscall(SYS_sh_task_info, pid, "myinfo.txt"); //by default correct code
  // stats = syscall(SYS_sh_task_info, pid, "."); //for is a dir error
  // stats = syscall(SYS_sh_task_info, pid, "/myinfo.txt"); //for permission denied 
  printf("System call sh_task_info returned %ld.\n", stats);
  sprintf(errmsg, "Error %d", errno);
  if(stats != 0){
  	perror(errmsg);
  }
  return 0;
}

