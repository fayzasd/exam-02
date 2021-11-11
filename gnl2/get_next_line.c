#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (char *)&str[i];
		str++;
	} 
	return NULL;
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return 0;
	while (str[i] != '\0')
		i++;
	return i;
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *str;
	
	if (!s1)
	{
		s1 = malloc(1*sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return NULL;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+1));
	if (!str)
		return NULL;
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i]; 
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	} 
	str[i] = '\0';
	free(s1);
	return str;
}

char *get_nl(int fd, char *save)
{
	char buf[BUFFER_SIZE + 1];
	int i;

//	buf = malloc(sizeof(char)*(BUFFER_SIZE + 1));
//	if (!buf)
//		return NULL;
	i = 1;
	while (!ft_strchr(save, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
//			free(buf);
			return NULL;
		}
		buf[i] = '\0';
		save = ft_strjoin(save, buf);
	}
//	free(buf);
	return save;
}

char *get_str(char *save)
{
	int i;
	char *str;

	i = 0;
	if (!save[i])
		return NULL;
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(sizeof(char)* i + 2);
	if (!str)
		return NULL;
	i = 0;
	while(save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}	
	str[i] = '\0';
	return str;
}

char *get_save(char *save)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return NULL;
	}
	str = malloc(sizeof(char)*(ft_strlen(save)-i+1));
	if (!str)
		return NULL;
	i++;
	j = 0;
	while(save[i])
	{
		str[j] = save[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(save);
	return str;
}

char *get_next_line(int fd)
{
	static char *save;
	char *str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	save = get_nl(fd, save);
	if (!save)
		return NULL;
	str = get_str(save);
	save = get_save(save);
	return str;
}

int main()	
{
	int fd = open("test.txt",O_RDONLY);
	printf("%s", get_next_line(fd));
}
