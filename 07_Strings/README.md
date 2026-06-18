# 07 - Strings in C

Strings are character arrays ending with '\0'.
In embedded systems: UART messages, LCD text, command parsing.

## Files

| File | Topic |
|------|-------|
| 01_string_basics.c | Declaration, access, null terminator |
| 02_string_functions.c | strlen, strcpy, strcmp, strcat, strtok |
| 03_string_reverse.c | Two methods to reverse |
| 04_string_palindrome.c | Palindrome check |
| 05_string_operations.c | Upper/lower, vowel count, word count |

## Interview Notes
- C strings MUST end with `\0` (null terminator)
- `strlen()` does NOT count `\0`, but `sizeof()` does
- `strcmp()` returns 0 if equal — don't use `==` for strings!
- `strcpy()` can cause buffer overflow — prefer `strncpy()` in production
- `strtok()` modifies the original string — be careful!
