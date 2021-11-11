#include <stdlib.h>
#include <unistd.h>

char *ft_strchr(char *save, char c)
{
	int i;
	i = 0;
	if (!save)
		return NULL;
	while (save[i] != '\0')
	{
		if (save[i] == c)
			return (char *)&save[i];
		i++;
	}
	return NULL;
}

int ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return 0;
	while (str[i] != '\0')
		i++;
	return i;
}

char *ft_strjoin(char *save, char *buf)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!save)
	{
		save = malloc(sizeof(char)*1);
		save[0] = '\0';
	}
	if (!save || !buf)
		return NULL;
	str = malloc(sizeof(char)*(ft_strlen(save) + ft_strlen(buf) + 1));
	while (save[i])
	{
		str[i] = save[i];
		i++;
	}
	while (buf[j])
	{
		str[i] = buf[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return str;
}

char *get_str(char *save)
{
	char *str;
	int i = 0;
	int j = 0;

	while (save[i] && save[i] != '\n')
		i++;
	str = malloc (sizeof(char) * i + 2);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[j] = save[i];
		i++;
		j++;
	}
	if (save[i] == '\n')
	{
		str[j] = '\n';
		j++;
	}
	str[j] = '\0';
	return str;
}

char *get_nl(int fd, char *save)
{
	int i;
	char buf[BUFFER_SIZE + 1];

	i = 1;
	while (!ft_strchr(save, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return NULL;
		buf[i] = '\0';
		save = ft_strjoin(save, buf);
	}
	return save;
}

char *get_save(char *save)
{
	char *str;
	int i = 0;
	int j = 0;
	
	
	while (save[i] && save[i] != '\n')
		i++;
	if(!save[i])
	{
		free(save);
		return NULL;
	}
	str = malloc (sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return NULL;
	i++;
	while(save[i])
	{
		str[j] = save[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(save);
	return str;
}

char *gnl(int fd)
{
	static char *save;
	char *str;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;	
	save = get_nl(fd, save);
	if (!save)
		return NULL;
	str = get_str(save);
	save = get_save(save);
	return str;
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
	printf("%s",gnl(fd));
}
