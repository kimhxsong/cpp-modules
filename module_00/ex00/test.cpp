#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

void    megaphoneSpeak(int argc, char *argv[]);

char *const case00[] = {
  (char[]){"megaphone"},
  (char[]){"Hello, World"},
  (char[]){" ! "},
  (char[]){"How are you?"},
  NULL
};

Test(megaphone, test) {
  int   pfd[2];
  pid_t pid;

  pipe(pfd);
  pid = fork();
  if (pid == 0)
  {
    close(pfd[0]);
    dup2(pfd[1], 1);
    close(pfd[1]);
    execve("./megaphone"\
          , case00, NULL);
  }
  close(pfd[1]);
  dup2(pfd[0], 0);
  close(pfd[0]);
  wait(NULL);
  std::string output;
  std::getline(std::cin, output);
  const char  *c_output = output.c_str();
  cr_assert(std::strcmp("HELLO, WORLD ! HOW ARE YOU?", c_output) == 0\
                      , "CASE_00: Failed\n");
}