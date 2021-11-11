#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
char *ft_strjoin(char *str, char buf, int i)
{
	char *s;
	int j;
	
	j = 0;
	i++;
	s = malloc(sizeof(char)*(i+1));
	while (str[j])
	{
		s[j] = str[j];
		j++;
	}
	if(buf)
		s[j] = buf;
	j++;
	s[j] = '\0';
	free(str);
	return s;
}


char *get_nl(int fd)
{
	int i;
	int count;
	char *buf;
	char *str;

	i = 1;
	count = 0;
	str = malloc(1);
	buf = malloc(sizeof(char)*(2));
	buf[1] = '\0';
	str[0] = '\0';
	while (i != 0)
	{
		i = read(fd, buf, 1);
		if (buf[0] != '\n' && buf[0] != '\0')
			str = ft_strjoin(str, buf[0], count);
		else
			break;	
	}
	free(buf);
	return str;
}

char *get_next_line(int fd)
{
	char *str;
	if(fd < 0)
		return NULL;
	str = get_nl(fd);
	return str;		
}

#include <stdio.h>

int main()
{
	int fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	
}
