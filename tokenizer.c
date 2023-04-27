#include "shell.h"

/**
 * count_words - counts the number of words in a string
 * @str: the input string
 * @delim: the delimiter string
 * Return: the number of words in the string
 */
static size_t count_words(const char *str, const char *delim)
{
	size_t count = 0;
	bool in_word = false;

	while (*str) {
		if (strchr(delim, *str)) {
			in_word = false;
		} else {
			if (!in_word) {
				count++;
				in_word = true;
			}
		}
		str++;
	}

	return count;
}

/**
 * split_string - splits a string into words
 * @str: the input string
 * @delim: the delimiter string
 * Return: a dynamically allocated array of strings, or NULL on failure
 */
static char **split_string(const char *str, const char *delim)
{
	size_t num_words = count_words(str, delim);
	char **words = malloc((num_words + 1) * sizeof(*words));
	if (!words) {
		return NULL;
	}

	size_t word_len;
	bool in_word = false;

	for (size_t i = 0, j = 0; i < num_words; j++) {
		if (strchr(delim, str[j])) {
			in_word = false;
			continue;
		}

		if (!in_word) {
			in_word = true;
			word_len = 0;
			words[i] = NULL;
			i++;
		}

		word_len++;
		words[i - 1] = realloc(words[i - 1], (word_len + 1) * sizeof(**words));
		if (!words[i - 1]) {
			while (i-- > 0) {
				free(words[i]);
			}
			free(words);
			return NULL;
		}
		words[i - 1][word_len - 1] = str[j];
		words[i - 1][word_len] = '\0';
	}

	words[num_words] = NULL;
	return words;
}

/**
 * strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
	if (!str || !*str) {
		return NULL;
	}

	return split_string(str, d ? d : " ");
}

/**
 * strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	if (!str || !*str) {
		return NULL;
	}

	char delim[2] = { d, '\0' };
	return split_string(str, delim);
}
