# Simple shell

This is a simple UNIX command interpreter.

# Usage

1- Compile source code
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

2- Usage in interractive mode

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

3- Non interractive mode

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

```
