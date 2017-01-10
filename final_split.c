#include "fillit.h"

int	tbllen(char **tbl)
{
	int	i;

	i = 0;
	while (*tbl)
	{
		i++;
		tbl++;
	}
	return (i);
}

char	***final_split(char **tbl)
{
	char	***tf;
	int		i;

	i = 0;
	tf = NULL;
	if ((tf = (char ***)malloc(sizeof(char **) * (tbllen(tbl)))) == NULL)
		return (NULL);
	while (i < tbllen(tbl))
	{
		tf[i] = ft_strsplit(tbl[i], '\n');
		i++;
	}
	tf[i] = NULL;
	return (tf);
}
