#include <iostream>
#include <stdio.h>
#include <string.h>
char *strfind(const char *src, const char *des, int n);
int main()
{
    char cerDN[] = "CN=041@Zgegwe@gegwe@00000001, OU=Enterprises, OU=myou, O=allo, C=cn";
    const char *pNewStr = strfind(cerDN, const_cast<char *>("OU="), 2); 
    const char *p1 = pNewStr + 3;
    char dn[20];
    memset(dn, 0x00, sizeof(dn));
    strcpy(dn, p1);
    char *p2 = strfind(dn, ",", 1);
    *p2 = '\0';
    std::cout << "dn = [" << dn << "]" << std::endl;
    return 0;
}

char *strfind(const char *src, const char *des, int n)
{
    if (src == NULL)
    {
        return NULL; 
    }

    if (des == NULL)
    {
        return (char *)src; 
    }

    if (n <= 0)
    {
        return (char *)src; 
    }

    const char *p_src = src;
    int i = 0;
    int nFind = 0;
    for(;*p_src != '\0'; p_src++)
    {
        for(i = 0;*(p_src + i) == *(des + i); i++) 
        {
            if (*(des + i + 1) == '\0') 
            {
                nFind = nFind + 1;
                if (nFind == n)
                {
                    return (char *)p_src; 
                }
            }
        }
    }

    return NULL;
}
