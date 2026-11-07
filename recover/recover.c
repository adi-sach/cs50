#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int blocksize = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    uint8_t buffer[blocksize];
    FILE *outptr = NULL;
    int file_count = 0;
    char filename[8];

    while (fread(buffer, 1, blocksize, card) == 512)
    {
        if (buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&   // ✅ CORRECT
                buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)
            {
               if (outptr != NULL)
                {
                    fclose(outptr);
                }

                sprintf(filename, "%03i.jpg", file_count);
                outptr = fopen(filename, "w");
                file_count++;
            }

            if (outptr != NULL)
            {
                fwrite (buffer ,1 ,512, outptr);
            }
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose (card);
}
