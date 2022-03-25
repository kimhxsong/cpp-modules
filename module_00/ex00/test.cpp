#include <criterion/criterion.h>
#include <unistd.h>
#include <string.h>

#include <string>
#include <iostream>

void megaphoneSpeak(int argc, char *argv[]);

char* const case_zero[] = {
  (char[]){"megaphone"},
  NULL
};

char* const case_one[] = {
  (char[]){"megaphone"},
  (char[]){"Hello, World"},
  NULL
};

char* const case_more[] = {
  (char[]){"megaphone"},
  (char[]){"Hello, World"},
  (char[]){" ! "},
  (char[]){"How are you?"},
  NULL
};

Test(megaphone, argc_one) {
  int   pfd[2];
  pid_t pid;

  pipe(pfd);
  pid = fork();

  if (pid == 0) {
    close(pfd[0]);
    dup2(pfd[1], 1);
    close(pfd[1]);
    execve("./megaphone", case_zero, NULL);
  }

  close(pfd[1]);
  dup2(pfd[0], 0);
  close(pfd[0]);
  wait(NULL);
  std::string output;
  std::getline(std::cin, output);
  cr_assert(output == "* LOUD AND UNBEARABLE FEEDBACK NOISE *",
            "case_zero: Failed\n");
}

Test(megaphone, argc_two) {
  int   pfd[2];
  pid_t pid;

  pipe(pfd);
  pid = fork();

  if (pid == 0) {
    close(pfd[0]);
    dup2(pfd[1], 1);
    close(pfd[1]);
    execve("./megaphone", case_one, NULL);
  }

  close(pfd[1]);
  dup2(pfd[0], 0);
  close(pfd[0]);
  wait(NULL);
  std::string output;
  std::getline(std::cin, output);

  cr_assert(output == "HELLO, WORLD", "case_one: Failed\n");
}

Test(megaphone, argc_more) {
  int   pfd[2];
  pid_t pid;

  pipe(pfd);
  pid = fork();

  if (pid == 0) {
    close(pfd[0]);
    dup2(pfd[1], 1);
    close(pfd[1]);
    execve("./megaphone", case_more, NULL);
  }

  close(pfd[1]);
  dup2(pfd[0], 0);
  close(pfd[0]);
  wait(NULL);

  std::string output;
  std::getline(std::cin, output);
  cr_assert(output == "HELLO, WORLD ! HOW ARE YOU?", "case_more: Failed\n");
}
