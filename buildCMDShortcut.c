#include <stdio.h>
#include <Windows.h>
int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        char cmd[2048] = "cd \"";
        strcat(cmd, argv[1]);
        strcat(cmd, "\" && build.sh");

        char file_path[2048] = "";
        strcat(file_path, argv[1]);
        strcat(file_path, "/build.sh");

        FILE *f;
        if ((f = fopen(file_path, "r")) != NULL)
        {
            pclose(f);
            printf("Running Build Script...");
            system(cmd);
            return (0);
        }
        else
        {
            printf("No build.sh file target found.");
            return (1);
        }
    }
    else
    {
        FILE *f;
        if ((f = fopen("build.sh", "r")) != NULL)
        {
            pclose(f);
            printf("Running Build Script...");
            system("build.sh");
            return (0);
        }
        else
        {
            printf("No build.sh file target found.");
            return (1);
        }
    }
};