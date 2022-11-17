
<h1 align="center">
	42-Cursus - get_next_line
</h1>

<p align="center">
	<img src="https://img.shields.io/badge/score-not%20submitted-red" />
	<img src="https://img.shields.io/github/languages/code-size/lbordonal/01-get_next_line" />
	<img src="https://img.shields.io/github/languages/count/lbordonal/01-get_next_line" />
	<img src="https://img.shields.io/github/languages/top/lbordonal/01-get_next_line" />
	<img src="https://img.shields.io/github/last-commit/lbordonal/01-get_next_line" />
</p>

<p align="center">
This repository contains code developed at 42 Porto for get_next_line Project, from 11/11/2022 to ...
</p>

<h2 align="left">
	 :notebook: Subject
</h2>
<a href="https://github.com/lbordonal/01-get_next_line/blob/main/Subject/en.subject.pdf">Click here</a> for the subject of this project.
<br /><br />


<h2 align="left">
	:zap: Function Prototype
</h2>

```c
char	get_next_line(int fd);

```
<br />

<h2 align="left">
	:computer: Usage
</h2>
Compile with: </br>
<code>cc -Wall -Werror -Wextra ../Tests/files/main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=size </code>

<br /><br />

<h2 align="left">
	:medal_sports: Mandatory Part
</h2>

**`get_next_line.c`**

* `get_next_line`	- main function.
* `read_and_save`	- takes the opened file descriptor and saves on a "buffer" variable what readed from it.
* `get_line`		- extract the first line of the file.
* `ft_save`		- stores the updated file with whatever is left from the original file, except the line extracted.

**`get_next_line_utils.c`**

* `ft_strlen`		- find length of string.
* `ft_strchr`		- find first occurence of a character in string.
* `ft_strjoin`		- concatenate two strings into a new string using malloc to alocate memory.
* `ft_calloc`		- allocates memory for an array with '/0'.

**`get_next_line.h`**
<br /><br />

<h2 align="left">
	:trophy: Bonus Part
</h2>

**`get_next_line_bonus.c`**

* `get_next_line`	- main function with bonus part.
* `read_and_save`	- takes the opened file descriptor and saves on a "buffer" variable what readed from it.
* `get_line`		- extract the first line of the file.
* `ft_save`		- stores the updated file with whatever is left from the original file, except the line extracted.

**`get_next_line_utils_bonus.c`**

* `ft_strlen`		- find length of string.
* `ft_strchr`		- find first occurence of a character in string.
* `ft_strjoin`		- concatenate two strings into a new string using malloc to alocate memory.
* `ft_calloc`		- allocates memory for an array with '/0'.

**`get_next_line_bonus.h`**
</br>
