#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

/* to read and write to buffers */
#define RD_BUFF_SIZE 1024
#define WR_BUFF_SIZE 1024
#define BUFF_FLUSH -1

/* for chaining commands */
#define CMD_CHAIN	3
#define CMD_AND	2
#define CMD_OR	1
#define CMD_NORM	0

/* convert_num() */
#define CONVERT_LWCASE	1
#define CONVERT_UNSIGNED	2

/* for getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simpleShellHistory"
#define HIST_MAX	4096

/**
 * struct list - single-linked list
 * @numb: the number of nodes
 * @string: a string
 * @next: pointer to the next node
 */
typedef struct list
{
	int numb;
	char *string;
	struct list *next;
} list_t;

extern char **environ;

/**
 * struct passInfo - contains pseudo-arguments to be passed into a function,
 * this will allow uniform prototype for func-ptr struct.
 * @arg: a str generated from getline which contain arguments.
 * @argv: an array of str generated from arg.
 * @path: str path for current program.
 * @argc: arg count
 * @err_count: the error count.
 * @err_numb: error code for exit().
 * @linecount_flag: indicates the line to count
 * @fName: program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env.
 * @hist: the history node.
 * @alias: the alias node
 * @env_change: turn on if environ changes.
 * @status: return status of last executed command
 * @cmd_buff: pointer address, turn on if chaining
 * @cmd_buff_type: command type ||, &&, ;.
 * @readfileD: the file descriptor from which to read line input.
 * @histCount: the history line number count.
 */
typedef struct passInfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int err_count;
	int err_numb;
	int linecount_flag;
	char *fName;
	list_t *env;
	list_t *hist;
	list_t *alias;
	char **environ;
	int env_change;
	int status;
	char **cmd_buff;
	int cmd_buff_type;
	int readfileD;
	int histCount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - contains a builtin string and related functions
 * @type: builtin command flag
 * @func: funtion
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_tab;

int hsh(info_t *, char **);
int findBuiltin(info_t *);
void findCmd(info_t *);
void forkCmd(info_t *);

/* errors handlers */
void _input(char *);
int _putchr(char c);
int _putfileD(char c, int fileD);
int _putsfileD(char *str, int fileD);

/* heritageParser */
int isCmd(info_t *, char *);
char *dupChr(char *, int, int);
char *findPath(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* string functions */
int _strlen(char *);
int _strcmp(char *, char *);
char *startWith(const char *, const char *);
char *_strcat(char *, char *);

/* other string functions */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char c);

/* exit functions */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* Tokenizers */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* functions for reallocation */
char *_memset(char *, char, unsigned int);
void _free(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory func */
int frees(void **);

/* atoi converters */
int interactive(info_t *);
int _delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* error handling functions */
int err_atoi(char *);
void print_err(info_t *, char *);
int printD(int, int);
char *convert_numb(long int, int, int);
void rem_comments(char *);

/* builtin funcs */
int _exits(info_t *);
int chDir(info_t *);
int _help(info_t *);

int _history(info_t *);
int _alias(info_t *);

/* my getline functions */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void signalHandler(int);

/* get info func */
void clrInfo(info_t *);
void setInfo(info_t *, char **);
void freeInfo(info_t *, int);

/* var chain */
int _ischain(info_t *, char *, size_t *);
void _checkchain(info_t *, char *, size_t *, size_t, size_t);
int _aliasreplace(info_t *);
int _varreplace(info_t *);
int _strreplace(char **, char *);

/* funct used to get environ var */
char *_getenv(info_t *, const char *);
int _env(info_t *);
int _setenv(info_t *);
int _unsetenv(info_t *);
int populateEnvList(info_t *);

char **getEnviron(info_t *);
int unsetEnv(info_t *, char *);
int setEnv(info_t *, char *, char *);

/* history func */
char *getHistFile(info_t *inf);
int writeHist(info_t *inf);
int readHist(info_t *inf);
int buildHistList(info_t *inf, char *buff, int count);
int reNumbHist(info_t *info);

/* func for list.c */
list_t *addNode(list_t **, const char *, int);
list_t *appendNode(list_t **, const char *, int);
/* size_t printList(const list_t *); */
int delNode(list_t **, unsigned int);
void freeList(list_t **);

size_t listLen(const list_t *);
char **listStr(list_t *);
size_t prList(const list_t *);
list_t *nodeStartsWith(list_t *, char *, char);
ssize_t getNode(list_t *, list_t *);

#endif /* SHELL_H */
