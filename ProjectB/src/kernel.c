int VIDEO_MEMORY_START_ADDR = 0x8000;
int VIDEO_MEM_PARAM = 0xB000;

void writeString(int, char[], char);
void writeChar(int, char, char);
void printChar(char);
void printString(char[]);
void readString(char[]);

int main()
{ 
    /* char line[80]; */
    /* char line[80];
    printString("Enter a line: \0");
    readString(line);
    printString(line); */

   /*  char buffer[512];
    readSector(buffer, 30);
    printString(buffer); */

    makeInterrupt21();
    loadProgram();
    /* syscall_readString(line);
    syscall_printString(line); */

    for(;;){}
    return 0;
}

void printError()
{
    printString("Incorrect interrupt call.");
}

void readString(string)
char string[];
{
    char* init = string;
    int iter = 0;
    while (iter < 80)
    {
        char tmp = readChar();
       /*  if (string == endOfArr)
        {
            *string = 0x0;
            break;
        } */
        if (tmp == 0x8 && string != init)
        {
            printChar(tmp);
            *string = 0x8;
            /* iter--; */
            string -= 1;
        }
        else if(tmp == 0x8 && string == init)
        {
        }
        else if (tmp == 0xd)
        {
            /* string += (79-iter); */
            printChar(tmp);
            *string = 0x0;
            break;
        }
        else
        {
            printChar(tmp);
            *string = tmp;
            string++;
            /* iter++; */
        }
    }
    string[79] = 0x0;
    printChar('\n');
}

/* void writeChar(line, character, color)
int line;
char character;
char color;
{
    int address = 80 * (line - 1);
    address *= 2;
    putInMemory(VIDEO_MEM_PARAM, VIDEO_MEMORY_START_ADDR + address, character);
    putInMemory(VIDEO_MEM_PARAM, VIDEO_MEMORY_START_ADDR + address + 1, color);
} */

/* void writeString(line, string, color)
int line;
char string[];
char color;
{
    int address = 80 * (line - 1);
    address *= 2;
    while (*string != '\0')
    {
        putInMemory(VIDEO_MEM_PARAM, VIDEO_MEMORY_START_ADDR + address, *string);
        putInMemory(VIDEO_MEM_PARAM, VIDEO_MEMORY_START_ADDR + address + 1, color);
        string++;
        address += 2;
    }
} */

void printString(character)
char character[];
{
    while(*character != '\0')
    {
        printChar(*character);
        character++;
    }
}
