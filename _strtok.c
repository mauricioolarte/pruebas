#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0, j = 0, lenname = 0, flag = 0;

	while (name[lenname])
		lenname++;
	while (environ[i] != NULL)
	{
		while (name[j])
		{
			if (name[j] == environ[i][j])
				j++;
			else
				break;
		}
		if (j == lenname && environ[i][j] == '=')
		{
			flag++;
			return (environ[i]);
		}
		j = 0;
		i++;
	}
	if (flag == 0)
		printf("variable no found\n");
	return (NULL);
}
int len_pat(char *string, char delimit)
{
	int i, j = 0;
	for (i = 0; string[i]; i++)
	{
		if (string[i] == delimit)
			j++;
	}
	return (j);
}
char **_strtok(char *string, char delimit, char *funct)
{
	unsigned int i = 0, j = 0, k = 0, split = 5, len = 0, lenstring, lenfunct, m;
	char **rstring;
	int *tem;
/* i and split inizializate in 5 for eliminate word "PATH="*/
	j = len_pat(string, delimit) + 1;
	lenfunct = strlen(funct) + 1;
	tem = (int *)(malloc(sizeof(int) * (j + 1)));
	lenstring = strlen(string);
	for (i = 5; string[i] != '\0'; i++)
	{
		if (string[i] == delimit)
		{
			len = i - split;
			tem[k] = len + lenfunct;
			split = i + 1;
			k++;
		}
		if (i == lenstring - 1)
		{
			len = i + 1 - split;
			tem[k] = len + lenfunct;
			split = i + 1;
		}
	}
	rstring = (char **)(malloc(sizeof(char *) * j));
	for (i = 0; i < j; i++)
		rstring[i] = (char *)(malloc(sizeof(char) * tem[i] + 1));
	split = 5, k = 0;
	for (i = 5; string[i] != '\0'; i++)
	{
		if (string[i] != delimit)
			rstring[k][i - split] = string[i];
		else
		{
			for (m = 0; funct[m] != '\0'; m++)
			{
				rstring[k][i - split] = '/';
				rstring[k][i + 1 - split + m] = funct[m];
			}
			rstring[k][i - split + m + 1] = '\0';
			split = i + 1;
			k++;
		}
		if (i == lenstring -1)
		{
			for (m = 0; funct[m] != '\0'; m++)
			{
				rstring[k][i - split] = '/';
				rstring[k][i + 1 - split + m] = funct[m];
			}
			rstring[k][i - split + m + 1] = '\0';
		}
	}
/*	rstring[k][i - split] = '\0';*/
	free (tem);

	return (rstring);
}

int  main(void)
{
	int i;
	char **r;


	r = _strtok(_getenv("PATH"), ':', "ls");

	for (i = 0; i < len_pat(_getenv("PATH"), ':') + 1; i++)
	{
		printf("%s\n", r[i]);
		free(r[i]);
	}
	free(r);
	printf("hol");

	     return (0);
}
