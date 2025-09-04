# Console

A simple console tool that contains all commands without using external programs.

Supported Commands:

- `cat` - shows the content of a file (text or binary)
- `cd` - changes the directory
- `echo` - prints text to the console
- `exit` - quits the console
- `ls` - shows all files in a directory
- `pwd` - shows the current path

To compile it on your computer, follow this steps:

1. Clone the project:

```bash
git clone https://github.com/Tuxchen/Console.git
```

2. Change to the directory

```bash
cd Console
```


3. Compile

```bash
g++ -O3 Commands/*.cpp *.cpp -o Console
```

4. Start the programm

```bash
./Console
```