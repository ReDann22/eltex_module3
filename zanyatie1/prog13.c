

/* Пример создания нового процесса с одинаковой работой процессов ребенка и родителя */


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[], char *envp[])
{
pid_t pid, ppid, chpid;
int a = 0;
 
chpid = fork();
if (chpid == -1)
{
        printf("Error!\n");
}
else if (chpid  == 0)
{
        printf("I'm child\n");
	(void) execle("/bin/cat", "/bin/cat", "prog12.c", 0, envp);
}
else
{
        printf("I'm parent\n");
        sleep(2);
}
/* При успешном создании нового процесса с этого места псевдопараллельно начинают работать 2 процесса: старый и новый */
 

/* Перед выполнением следующего выражения a в обоих процессах равно 0 */

a = a+1; 
 
/* Узнаем идентификаторы текущего и родительского процесса (в каждом из процессов !!!) */

pid = getpid();
ppid = getppid();

/* Печатаем значения PID, PPID и вычисленное значение a (в каждом из процессов !!!) */

printf("My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a); 

return 0;
} 
