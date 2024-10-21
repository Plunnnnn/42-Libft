# ft_print - README

## 1. Introduction

The **ft_print** project is about recreating a simplified version of the `printf` function from the C standard library. The goal is to handle various formatted inputs and correctly display them on the standard output, managing different data types like integers, strings, characters, and pointers.

The original `printf` function is complex and supports many features. Here, we focus on a limited subset, which is a great exercise in string manipulation, memory management, and handling variable arguments.

## 2. Concept

The concept behind this project is to understand and implement how `printf` works internally. The `printf` function takes a format string that can contain format specifiers like `%d`, `%s`, `%c`, etc., which are replaced by corresponding values during execution. It also uses a variable argument list, meaning the number of arguments is not fixed in advance.

The main goals are to:
1. Parse the format string.
2. Identify the format specifiers.
3. Retrieve the corresponding arguments.
4. Format those arguments and display them.

## 3. Algorithm

Here is a general approach to the **ft_print** function algorithm:

### Main Steps:

1. **Initialization**:
   - Create a function `ft_print(format, ...)`.
   - Use a variable argument list to retrieve parameters after the format string.

2. **Format String Parsing**:
   - Traverse the format string character by character.
   - When a `%` character is encountered, identify the format specifier that follows (e.g., `%d`, `%s`, `%c`, etc.).

3. **Argument Retrieval**:
   - Based on the format specifier, retrieve the corresponding argument from the variable argument list.
   - For example, `%d` retrieves an integer, `%s` retrieves a string.

4. **Formatted Output**:
   - Once the argument is retrieved, format it accordingly.
   - For example, an integer must be converted to a string to be displayed.
   - After formatting, output the result to the standard output.

5. **Error Handling**:
   - Handle cases where a format specifier is misused (e.g., encountering `%x` when the program doesn't support it).
   - Return the total number of printed characters.

### Algorithm Pseudo-Code:

function ft_print(format, ...) initialize the argument list initialize character_count to 0

```for each character in format:
    if the character is '%':
        read the next character as specifier
        if specifier == 'd':
            retrieve the integer from the argument list
            convert the integer to a string
            print the string and increment character_count
        else if specifier == 's':
            retrieve the string from the argument list
            print the string and increment character_count
        else if specifier == 'c':
            retrieve the character from the argument list
            print the character and increment character_count
        else:
            print an error message or ignore
    else:
        print the character and increment character_count

return character_count```

## 4. Code Structure

### 4.1. Main Function

- **ft_print**: The main function that takes the format string and a list of arguments. It handles the format string parsing, specifier identification, and argument printing.

### 4.2. Helper Functions

- **ft_parse_specifier**: This function identifies the type of format specifier and returns the corresponding type (integer, string, character, etc.).
- **ft_handle_integer**: Function to handle integer conversion into strings for printing.
- **ft_handle_string**: Function to handle string output.
- **ft_handle_char**: Function to handle the printing of a single character.

### Code Structure Pseudo-Code:
