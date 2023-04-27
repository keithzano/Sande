#include "shell.h"

int main(int argc, char **argv)
{
    int fd = 2;
    info_t info = INFO_INIT;

    // Increment the value of fd by 3 using inline assembly
    __asm__ __volatile__ ("mov %1, %0\n\tadd $3, %0" : "=r" (fd) : "r" (fd));

    if (argc == 2)
    {
        // Open file specified in argv[1] and set it as the readfd
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            // Handle error cases
            if (errno == EACCES)
                exit(126);
            else if (errno == ENOENT)
            {
                eputs(argv[0]);
                eputs(": 0: Can't open ");
                eputs(argv[1]);
                eputchar('\n');
                eputchar(BUF_FLUSH);
                exit(127);
            }
            else
                return EXIT_FAILURE;
        }
        info.readfd = fd;
    }

    // Populate environment variables list and read command history
    populate_env_list(&info);
    read_history(&info);

    // Start the shell
    hsh(&info, argv);

    // Exit the program
    return EXIT_SUCCESS;
}
