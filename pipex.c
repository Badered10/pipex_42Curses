/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/01/20 23:29:03 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int strings_count(char **str)
{
    char **save;

    save = str;
    while (*str)
        str++;
    return(str - save);  
}
static void free_double(char **ptr)
{
    char **save;

    save = ptr;
    while (*save)
    {
        free(*save);
        save++;
    }
    free(ptr);
}
static char **get_env_paths(char **env)
{
    char **res;
    while (*env && !ft_strnstr(*env,"PATH",5))
        env++;
    if (!*env)
        return (NULL);
    res = ft_split(*env , ':');
    *res = ft_strchr(*res, '/');

    return(res);
}

static char *check_path(char *path , char *cmd)
{
    char *a_path;
    char *fullpath;

        a_path = (ft_strjoin(path,"/"));
            fullpath = ft_strjoin( a_path ,cmd);
            // if (!fullpath)
            // {
            //     free(a_path);
            //     ft_putstr_fd("pipex: permission denied:\n",2);
            //     exit(1);
            // }
          if (!access(fullpath, X_OK))
                return (free (a_path),fullpath);
            else
            return (free(fullpath),free(a_path),NULL);
}
static void show_err(char *argv)
{
    char *err;
    char *display;
    
    err = ft_strjoin("pipex: command not found: ",argv);
        display = ft_strjoin(err,"\n");
        write(2,display,ft_strlen(display));
        free(err);
        free(display);
}
static char* cmd_path(char **argv,char **env)
{
    int paths_num;
    char **cmd;
    char **paths;
    char *err;
    char **errs;
    char *fullpath;
    int i;

    i = 0;
    paths = get_env_paths(env);
    paths_num = strings_count(paths);
    cmd = ft_split(*(argv), ' ');
    if(!*cmd)
        return (ft_strdup(""));
    if (*(*argv) == '/' && access(*cmd, X_OK) == 0)
        return (ft_strdup(*cmd));
    else
        while(paths_num-- > 0)
        {
            fullpath = check_path(paths[i++] , *cmd);
            if (fullpath)
                return (fullpath);
        }
        
        show_err(*argv);
        exit(1);
}
void child(char *infile ,char **argv_copy ,char **env,int *pipefd)
{
    char **cmd;
    char *founded_path;
    int infile_fd;

    infile_fd = open(infile, O_RDONLY);
    if (infile_fd < 0)
    {
        ft_putstr_fd(strerror(errno),2);
        exit(1);
    }
    cmd = ft_split(*argv_copy , ' ');
    founded_path = cmd_path(argv_copy, env);
    // printf("in child ------------> founded_path : |%s| ,cmd : |%s|\n",founded_path,*cmd);
    close(pipefd[0]);
    dup2(infile_fd,0);
    dup2(pipefd[1], 1);
    execve(founded_path,cmd,NULL);
    close(pipefd[1]);
}
void parent(char *outfile,char **argv_copy ,char **env,int *pipefd)
{
    char **cmd;
    char *founded_path;
    int outfile_fd;
    char **cat;
    
    cat = malloc(2 * sizeof(char *));
    cat[0] = "cat";
    cat[1] = NULL;
    outfile_fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (outfile_fd < 0)
    {
        ft_putstr_fd(strerror(errno),2);
        exit(1);
    }
    wait(NULL);
    argv_copy++;
    founded_path = cmd_path(argv_copy, env);
    cmd = ft_split(*argv_copy , ' ');
    printf("in parent ------------> founded_path : |%s| ,cmd : |%s| , argv_copy : |%s|\n",founded_path,*cmd ,*argv_copy);
    close(pipefd[1]);
    dup2(outfile_fd,1);
    dup2(pipefd[0], 0);
    //  while(1)
    // ;
    //   if (*founded_path == '\0')
    //     execve(cmd_path(cat,env),ft_split("cat", ' '),NULL);
    if(*(*argv_copy) == '\0')
         execve(cmd_path(cat, env),cat,NULL);
    execve(founded_path,cmd,NULL);
    close(pipefd[0]);
}
int main (int argc , char **argv, char **env )  // ./pipex inputfile1 cmd1 cmd2 .... outputfile2 // execv(path,)
{
    char **argv_copy;
    int id;
    int pipefd[2];
    
    argv_copy  = argv;
    argv_copy += 2;
    
    if (pipe(pipefd))
        return(ft_putstr_fd(strerror(errno),2),errno);
    if (argc < 5)
        return(ft_putstr_fd("Not enough arguments !\n",2),1);
    id = fork();
    if (id < 0)
            return(ft_putstr_fd(strerror(errno),2),errno);
        if (id == 0)
            child(argv[1],argv_copy ,env, pipefd);
        else
            parent(argv[4],argv_copy ,env, pipefd);
}
