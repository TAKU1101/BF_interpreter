# My_library

Implementation of standard C library and original functions

## Original functions

All original functions are in the 'ori' directory

### ft_split

char **ft_split(char const *str, char c)

Splitting a string  
str: Target to split  
c: split character  
return value: Array of strings after splitting

### ft_strjoin

char *ft_strjoin(char const *s1, char const *s2)

String concatenation  
s1, s2: strings  
return value: the concatenated string.

### ft_strmap

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))

Add processing one character at a time  
s: Target to process  
f: Operation contents  
return value: the string after processing

### ft_strtrim

char *ft_strtrim(char const *s1, char const *set)

Eliminate the preceding and following characters  
s1: Target  
set: Target to eliminate  
return value: the string after processing

### ft_substr

char *ft_substr(char const *s, unsigned int start, size_t len)

Cut off a string  
s: Target to cut  
start: Start position of the string to be cut.  
return value: the cut string

### ft_isintoverflow

int	ft_isintoverflow(const char *str)

Check that the number in the string does not overflow the int type.  
str: The number in the string  
return value: 1 if the number overflows

### ft_put*_fd

Output a string to the specified file descriptor.

### ft_lst*_fd

Function for concatenated lists
