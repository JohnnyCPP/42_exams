#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose);

void nice_function(void)
{
    // Esta función no hace nada malo
    return;
}

void bad_function_exit_code(void)
{
    // Esta función termina con código de error
    exit(1);
}

void bad_function_segfault(void)
{
    // Esta función causa segmentation fault
    int *ptr = NULL;
    *ptr = 42;
}

void bad_function_timeout(void)
{
    // Esta función nunca termina
    while (1) {}
}

void bad_function_abort(void)
{
    // Esta función llama abort()
    abort();
}
 
void bad_function_false_timeout(void)
{
    exit(142);
}

static void new_handler(int sig)
{
	(void) sig;
	printf("child custom handler triggered\n");
}

void override_alarm_handler(void)
{
	struct sigaction sa;

	sa.sa_handler = new_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGALRM, &sa, NULL);
}

void very_bad_function_set_handler(void)
{
	override_alarm_handler();
	sleep(10);
    exit(66);
}

int main()
{
    int result;

    printf("Testing nice function:\n");
    result = sandbox(nice_function, 5, true);
    printf("Result: %d\n\n", result);  // Esperado: 1

    printf("Testing bad function (segfault):\n");
    result = sandbox(bad_function_segfault, 5, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

    printf("Testing bad function (exit_code):\n");
    result = sandbox(bad_function_exit_code, 5, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

    printf("Testing bad function (timeout):\n");
    result = sandbox(bad_function_timeout, 2, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

    printf("Testing bad function (abort):\n");
    result = sandbox(bad_function_abort, 2, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

    printf("Testing bad function (false_timeout):\n");
    result = sandbox(bad_function_false_timeout, 60, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

    printf("Testing very bad function (set_handler):\n");
    result = sandbox(very_bad_function_set_handler, 5, true);
    printf("Result: %d\n\n", result);  // Esperado: 0

    return 0;
}
