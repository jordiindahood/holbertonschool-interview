#include <stdlib.h>
#include <string.h>
#include "substring.h"

/* Build dictionary of unique words + counts */
static int build_dict(char const **words, int nb, char ***dw, int **dc)
{
	int i, j, size = 0;

	*dw = malloc(nb * sizeof(char *));
	*dc = malloc(nb * sizeof(int));
	if (!*dw || !*dc)
		return (-1);

	for (i = 0; i < nb; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (strcmp(words[i], (*dw)[j]) == 0)
			{
				(*dc)[j]++;
				break;
			}
		}
		if (j == size)
		{
			(*dw)[size] = (char *)words[i];
			(*dc)[size] = 1;
			size++;
		}
	}
	return (size);
}

/* Find index of word in dictionary */
static int dict_index(char const *w, char **dw, int size)
{
	int i;

	for (i = 0; i < size; i++)
		if (strcmp(w, dw[i]) == 0)
			return (i);
	return (-1);
}

/* Sliding window logic for one offset */
static void slide_window(char const *s, int s_len, int w_len,
						 char **dw, int *dc, int dsz,
						 int nb_words, int offset,
						 int **res, int *n)
{
	int left = offset, right = offset, count = 0, idx;
	int *seen = calloc(dsz, sizeof(int));
	char tmp[w_len + 1];

	while (right + w_len <= s_len)
	{
		strncpy(tmp, s + right, w_len);
		tmp[w_len] = '\0';
		right += w_len;

		idx = dict_index(tmp, dw, dsz);
		if (idx == -1)
		{
			memset(seen, 0, dsz * sizeof(int));
			count = 0;
			left = right;
			continue;
		}

		seen[idx]++, count++;

		while (seen[idx] > dc[idx])
		{
			strncpy(tmp, s + left, w_len);
			tmp[w_len] = '\0';
			seen[dict_index(tmp, dw, dsz)]--;
			count--;
			left += w_len;
		}

		if (count == nb_words)
		{
			*res = realloc(*res, (*n + 1) * sizeof(int));
			(*res)[(*n)++] = left;
		}
	}
	free(seen);
}

/* Main entry function */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, w_len, total, i, dsz;
	char **dw = NULL;
	int *dc = NULL, *res = NULL;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	w_len = strlen(words[0]);
	s_len = strlen(s);
	total = w_len * nb_words;
	if (s_len < total)
		return (NULL);

	dsz = build_dict(words, nb_words, &dw, &dc);
	if (dsz < 0)
		return (NULL);

	for (i = 0; i < w_len; i++)
		slide_window(s, s_len, w_len, dw, dc, dsz,
					 nb_words, i, &res, n);

	free(dw), free(dc);
	return (*n > 0 ? res : (free(res), NULL));
}
