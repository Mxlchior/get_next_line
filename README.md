*This project has been created as part of the 42 curriculum by megrelli.*

💡 Description

get_next_line is a C programming project whose goal is to implement a function that reads and returns a single line from a file descriptor each time it is called.

This project introduces important concepts such as:

	- Static variables
	- File descriptors
	- read/open

The function must:

	- Return a line ending with \n (when present) or NULL if there is nothing to read or if something went wrong
	- Handle files of any size
	- Work with different BUFFER_SIZE values
	- Support reading from both files and standard input (stdin)
	- Manage memory correctly without leaks

For the bonus part, get_next_line should manage multiple file descriptors at the same time

🚀 Instructions

Compile the project and specify the BUFFER_SIZE you want (it sets the BUFFER_SIZE at 25 if you dont):
	cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
To compile the bonus version :
	cc -Wall -Werror -Wextra get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=42

📚 Resources

- "Termine et Push get_next_line en 3h" Video by suhulla : https://www.youtube.com/watch?v=jT9N8gY36Os
- "Comprendre get_next_line" Video by Nikito : https://www.youtube.com/watch?v=-Mt2FdJjVno
- Gitbook for 42 by Laura and Simon : https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
- AI (Gemini/GPT) was used for clarification of specific concepts and structuration of this README.md file.

🔨 Algorithm

The logic is divided into three steps using a static variable to persist data between calls:

    ft_read_and_stash: Reads from the FD in chunks of BUFFER_SIZE and joins them into the stash until a \n or EOF is reached.
    ft_extract_line: Isolates and returns the string from the start of the stash up to the first \n or to the end if there is none.
    ft_clean_stash: Deletes the extracted line from the stash, preserving only the "leftover" characters (if there are some) for the next function call.

Bonus part:

	A static array of strings is used instead of a single pointer. This allows the function to store independent buffers for up to 1024 file descriptors simultaneously, ensuring that reading from one file does not interfere with another.
