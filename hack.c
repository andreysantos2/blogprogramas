#include <stdlib.h>
char cpf[11], cpfFormatado[14], nome[20];
 
void cpf_generator()
{
    int i, j, dig = 0;
    srand(time(NULL));
    for(i = 0; i <= 9; i++)
        cpf[i] = (rand() % 10) + 48;
    for(i = 0, j = 10; i <= strlen(cpf)-2; i++, j--)
        dig += (cpf[i]-48) * j;
    dig %= 11;
    if(dig < 2)
        cpf[9] = 48;
    else
        cpf[9] = (11-dig)+48;
    dig = 0;
    for(i = 0, j = 11; i <= strlen(cpf)-1; i++, j--)
    {
        dig += (cpf[i]-48) * j;
    }
    dig %= 11;
    if(dig < 2)
        cpf[10] = 48;
    else
        cpf[10] = (11-dig)+48;
}
 
main()
{
    int i;
    cpf_generator();
    cpfFormatado[0] = cpf[0];
    cpfFormatado[1] = cpf[1];
    cpfFormatado[2] = cpf[2];
    cpfFormatado[3] = '.';
    cpfFormatado[4] = cpf[3];
    cpfFormatado[5] = cpf[4];
    cpfFormatado[6] = cpf[5];
    cpfFormatado[7] = '.';
    cpfFormatado[8] = cpf[6];
    cpfFormatado[9] = cpf[7];
    cpfFormatado[10] = cpf[8];
    cpfFormatado[11] = '-';
    cpfFormatado[12] = cpf[9];
    cpfFormatado[13] = cpf[10];
    
    scanf("%s", &nome);
    
    sprintf(var, "nmap -sS -sV %s", cpfFormatado);
    system(var);
    
    system("pause");
    return 0;
}
