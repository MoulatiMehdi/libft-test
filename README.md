# Libft Tester 🧪

A comprehensive testing suite for your Libft project! This tester helps you verify both the mandatory and bonus functions of your Libft implementation.

## Installation 📥

1. First, clone the tester repository in your home directory:

### For Linux : 
```bash
cd ~
git clone https://github.com/MoulatiMehdi/libft-test.git libft-test
```
> ⚠️ Make sure to clone it as `libft-test` to ensure the default make commands work properly!
> ⚠️ Make sure that all the your functions are in your libft.h!

## Usage 🚀

### Important: Run All Commands From Your Libft Directory
Navigate to your libft directory where all your `.c` files are located:
```bash
cd path/to/your/libft
```

### Testing All Functions
To test all functions in your libft:
```bash
make -f ~/libft-test/Makefile
```

### Testing Specific Functions
To test a specific function or group of functions:
```bash
make -f ~/libft-test/Makefile [function_name]
```

Examples (run these from your libft directory):
```bash
# Test individual functions
make -f ~/libft-test/Makefile atoi     # Tests ft_atoi
make -f ~/libft-test/Makefile strlen   # Tests ft_strlen

# Test function groups
make -f ~/libft-test/Makefile is       # Tests all is* functions (isalpha, isdigit, etc.)
make -f ~/libft-test/Makefile to       # Tests all to* functions (tolower, toupper)
```

## Function List 📝

### Main Functions
- `atoi`
- `bzero`
- `calloc`
- `itoa`
- `lstnew`
- `memchr`
- `memcmp`
- `memcpy`
- `memmove`
- `memset`
- `putchar_fd`
- `putendl_fd`
- `putnbr_fd`
- `putstr_fd`
- `split`
- `strchr`
- `strdup`
- `striteri`
- `strjoin`
- `strlcat`
- `strlcpy`
- `strlen`
- `strmapi`
- `strrchr`
- `strtrim`

### Function Groups
You can test these groups with a single command:

IS Functions (Test all with `make -f ~/libft-test/Makefile is`):
- `isalnum`
- `isalpha`
- `isascii`
- `isdigit`
- `isprint`

TO Functions (Test all with `make -f ~/libft-test/Makefile to`):
- `tolower`
- `toupper`

## Directory Structure 📁
```
~/libft-test/       # Tester location (in home directory)
your/libft/         # Your libft directory with:
  ├── ft_atoi.c
  ├── ft_isalpha.c
  ├── ft_tolower.c
  ├── libft.h
  └── ... (other source files)
```

## Troubleshooting 🔧

If you encounter any issues with the make command, verify that:
1. The tester is cloned in your home directory as `libft-test`
2. You're running the commands from your libft directory where your `.c` files are located
3. Your libft.h header file is properly included
4. All your functions are properly prefixed with `ft_`
5. Your source files are compiled and up to date

## Notes 📌

- The tester assumes your functions follow the 42 naming convention (prefixed with `ft_`)
- All tests must compile without any warnings or errors
- You can test individual functions or use group commands (`is` or `to`)
- Using `is` will test all isalpha, isdigit, isalnum, isascii, and isprint functions
- Using `to` will test both tolower and toupper functions
- Make sure all your source files are saved before running tests

## Feedback & Issues 🐛

If you find any bugs or have suggestions for improvement, please open an issue in the repository!

Happy testing! 🎉
