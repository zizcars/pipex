
# 🧵 Pipex

> A reproduction of the Unix pipeline behavior using process forking, piping, and file descriptors — part of the 42 Common Core curriculum.

---

## 📚 Project Overview

**Pipex** is a simplified clone of shell pipelines. Given a file and a sequence of commands, the program executes the commands just like the shell does:

```bash
<infile cmd1 | cmd2 >outfile
````

Your program handles input/output redirection, process creation, and execution of shell commands via `execve`.

---

## ✅ Mandatory Part

### Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

* Executes `cmd1` with `infile` as input
* Pipes output of `cmd1` to `cmd2`
* Redirects final output to `outfile`

### Example

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

Equivalent to:

```bash
< input.txt grep hello | wc -l > output.txt
```

---

## 🌟 Bonus Part

Supports **here\_doc**:

### Usage

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" ... "cmdN" outfile
```

Reads from stdin until a line matching `LIMITER` is found, then executes the commands like:

```bash
cmd1 | cmd2 | ... | cmdN >> outfile
```

### Example

```bash
./pipex here_doc EOF "cat" "grep hello" output.txt
```

---

## 🔧 Compilation

```bash
make        # Compiles the mandatory part
make bonus  # Compiles the bonus part (with here_doc)
make clean  # Removes object files
make fclean # Cleans all binaries and object files
make re     # fclean + make
```

---

## 📁 Project Structure

```
pipex/
├── includes/        # Header files
├── src/             # Mandatory source files
├── bonus/           # Bonus source files (here_doc)
├── lib/             # Custom lib (e.g. libft)
├── Makefile         # Build rules
└── README.md        # Documentation
```

---

## 🚀 Skills Learned

* File descriptors, piping, redirections
* Process creation and execution (`fork`, `execve`, `waitpid`)
* Handling environment paths and memory
* Writing a clean and modular Makefile

---

## 📦 Resources

* [man execve](https://man7.org/linux/man-pages/man2/execve.2.html)
* [man fork](https://man7.org/linux/man-pages/man2/fork.2.html)
* [man pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
* [GNU Shell Commands](https://www.gnu.org/software/bash/manual/)


