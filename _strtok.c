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
	printf("estos es j %i\n", j);
	return (j);
}
char **_strtok(char *string, char delimit, char * funct)
{
	unsigned int i = 0, j = 0, k = 0, m = 0, split = 0, len = 0, /*lenfunct*/;
	char **rstring;

	j = len_pat(string, delimit);
/*	lenfunct = strlen(funct) + 1;*/
	printf("lenfunct %u\n", lenfunct);
	printf("este es path %s\n", string);
	rstring = (char **)(malloc(sizeof(char *) * j));
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == delimit)
		{
			printf("int%i y k%i\n", i, k);
			len = i - split;
			split = i + 1;
			rstring[k] = (char *)(malloc(sizeof(char) * (len + lenfunct)));
			k++;
		}
	}
	printf("creo que me salgo aqui y k = %i y j =%i \n", k, j);
/*	rstring[k] = (char *)(malloc(sizeof(char) * (len)));*/
	printf("esto es i3");
	split = 0, k = 0;
	printf("esto es i2");
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] != delimit && string[i] != '\0')
			rstring[k][i - split] = string[i];
		else
		{
			rstring[k][i - split] = '/';
			for (m = 0; m < 2; i++)
				rstring[k][i - split + 1 + m] = funct[m];
			k++;
			split = i + 1;
			}
	}

	for (i = 0; i <= k; i++)
		printf("%s\n",rstring[i]);
	for (i = 0; i <= k; i++)
		free(rstring[i]);
	free(rstring);
	return (NULL);
}

int main(void)
{


	_strtok(_getenv("PATH"), ':', "ls");
	printf("hol");

	return (0);
}
