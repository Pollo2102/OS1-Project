int VIDEO_MEMORY_START_ADDR = 0x8000;
int VIDEO_MEM_PARAM = 0xB000;

void writeString(int, char[], char);
void writeChar(int, char, char);

int main()
{ 
    writeString(1, "                           SISTEMAS OPERATIVOS I      ", 0x7); 
    writeString(2, "               UNIVERSIDAD TECNOLOGICA CENTROAMERICANA (UNITEC)", 0x7); 
    writeString(3, "                        21711267 - DIEGO VALENZUELA", 0x7); 
    writeString(4, "                        MI PRIMER SISTEMA OPERATIVO", 0x7); 
    writeString(5, "--------------------------------------------------------------------------------", 0x7); 
    writeString(6, "****************************** Hola Mundo !! ***********************************", 0x7); 
    writeString(7, "****************************** Hello World !! **********************************", 0x7); 
    writeString(8, "****************************** Ola Mundo !! ************************************", 0x7); 
    writeString(9, "****************************** Hello Wereld !! *********************************", 0x7); 
    writeString(10, "****************************** Hallo Welt !! ***********************************", 0x7); 
    writeString(11, "****************************** Salam dunya !! **********************************", 0x7); 
    writeString(12, "****************************** Zdravo svijetu !! *******************************", 0x7); 
    writeString(13, "****************************** Hola mon !! *************************************", 0x7); 
    writeString(14, "****************************** Kumusta kalibutan !! ****************************", 0x7); 
    writeString(15, "****************************** Ahoj svete !! ***********************************", 0x7); 
    writeString(16, "****************************** Moni Dziko Lapansi !! ***************************", 0x7); 
    writeString(17, "****************************** Hola mondu !! ***********************************", 0x7); 
    writeString(18, "****************************** Alo mond !! *************************************", 0x7); 
    writeString(19, "****************************** Pozdrav svijete !! ******************************", 0x7); 
    writeString(20, "****************************** Hej Verden !! ***********************************", 0x7); 
    writeString(21, "****************************** Ahoj svet !! ************************************", 0x7); 
    writeString(22, "****************************** Saluton mondo !! ********************************", 0x7); 
    writeString(23, "****************************** Hei maailma !! **********************************", 0x7); 
    writeString(24, "****************************** Bonjour le monde !! *****************************", 0x7); 
    writeString(25, "****************************** Hallo wrald !! **********************************", 0x7); 

    return 0;
}

void writeChar(line, character, color)
int line;
char character;
char color;
{
    int address = 80 * (line - 1);
    address *= 2;
    putInMemory(VIDEO_MEM_PARAM, VIDEO_MEMORY_START_ADDR + address, character);
    putInMemory(VIDEO_MEM_PARAM, VIDEO_MEMORY_START_ADDR + address + 1, color);
}

void writeString(line, string, color)
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
}