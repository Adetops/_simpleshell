#ifndef FUJI_HEADER
#define FUJI_HEADER

#include <stdarg.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
/**
 * struct builtins - builtin command and functions for shell
 * @cmd: cmd name
 * @f: pointer to builtin functions
 *
 * Description: struct for builtin functions
 */
typedef struct builtins
{
	char *cmd;
	int (*f)(char **args, char **env);
} built_t;

/* Function Declarations for builtin shell commands */
int fuji_env(char **args, char **env);
int fuji_exit(char **args, char **env);
int fuji_built(char **args, char **env);

void free_array(char **array);
void free_cptrn(int, const unsigned int n, ...);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name, char **env);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
int _strcmp2(const char *s1, const char *s2);
char **strtow(char *str);
void get_word(char **array, char *str);
int word_count(char *str);
void cpy_str(int end, char *s, char **word_box);
char *str_concat(char *s1, char *s2);
void check_path(char **string, char **env);
void signal_handler(int signo);
void err_exit(char *, int status);
int prompt(char **ptr);
int _atoi(char *s);
#endif
