#ifndef _SHELL_
#define _SHELL_


extern char **environ;


#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, finto(c)))


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>



char *_strtokn(char *str, const char *tok);
unsigned int cdlim(char c, const char *str);
char *copys(char *dest, char *src, int n);
int finto(char *s);
int _putchar(char c);
int _atoi(char *s);
void _place(char *str);
int ptree(char *s1, char *s2);
int sala(int c);
void cntre(char *arr, int len);
int mtel(int num);
char *bob(unsigned int n);
char *mcat(char *dest, char *src);
char *utd(char *dest, char *src);
char *strii(char *s, char c);
int moon(const char *s1, const char *s2, size_t n);
char *wsup(char *str);


void jev(char **env);
void *sunray(void *a, int el, unsigned int len);
char *mcopy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *relocate(void *ptr, unsigned int old_size, unsigned int new_size);
void release_mem(char **input, char *line);

void prompt(void);
void sign(int sig);
char *getl(void);

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_b(char **cmd, int er);
void access_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_b(char **cmd);
void crea_env(char **envi);
int check_check(char **tokens, char *line, int count, char **argv);
void sort_file(char *line, int counter, FILE *fd, char **argv);
void close_bulf(char **cmd, char *line, FILE *fd);

void tag_handl(char *buff);
int history(char *input);
int historyf_dis(char **cmd, int er);
int di_environ(char **cmd, int er);
int cd_dir(char **cmd, int er);
int user_help(char **cmd, int er);
int echo_bult(char **cmd, int er);
void close_obul(char **cmd, char *input, char **argv, int c);
int prt_echo(char **cmd);

void print_number(unsigned int n);
void prt_num(int n);
void print_error(char *line, int c, char **argv);
void _proerr(char **argv, int c, char **cmd);


/**
 * struct bulltin - contains handles
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
