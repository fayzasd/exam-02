#include <unistd.h> 

void get_count(int *ascii, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ascii[(int)str[i]] = 1;
        i++;
    }
}

void print_count(int *ascii, char *str)
{
    int i;
    char c;
    
    i = 0;
    while (str[i])
    {
        c = str[i];
        if (ascii[(int)str[i]] == 1)
            {
                write(1, &c, 1);
                ascii[(int)str[i]] = 0;
            }
        i++;
    }
}

int main(int argc, char **argv)
{
    int ascii[127] = {0, };

    if (argc != 3)
        write(1,"/n",1);
    else
    {
        get_count(ascii, argv[1]);
        get_count(ascii, argv[2]);
        print_count(ascii, argv[1]);
        print_count(ascii, argv[2]);
    }
}
