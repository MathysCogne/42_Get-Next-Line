<div align="center">
<h1>42 - Get Next Line (GNL)</h1>
<p><strong>Because putnbr and putstr aren’t enough</strong></a></p>
<p><a href="https://github.com/MathysCogne/42_Get-Next-Line/blob/main/subject/gnl.pdf"><strong>Subject</strong></a></p>
</br>
</div>

## Description

Get Next Line (GNL) is a project to read a line from a file descriptor, returning it one line at a time.

The primary goal is to create a function that efficiently reads and returns lines from a file or standard input without memory leaks.

</br>

## Usage
To use the `get_next_line` function in your project, include the header file and call the function with a file descriptor:

```c
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("your_file.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}

```
</br>

## Disclaimer
> At 42 School, most projects must comply with the [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).
