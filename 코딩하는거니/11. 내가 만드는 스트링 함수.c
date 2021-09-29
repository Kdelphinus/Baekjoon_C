#include <stdio.h>
#include <string.h>

int myStrlen(char *arr)
{

    int counter = 0;
    char *cp = arr; // arr�� ���� ����

    while (*cp != '\0')
    {
        counter++;
        cp++;
    }
    return counter;
}

char *myStrcat(char *str1, char *str2)
{
    // ù��° ��Ʈ���� �� �ڸ� ã��
    int cnt = 0;
    while (*(str1 + cnt) != '\0')
    {
        cnt++;
    }

    // ù��° ��Ʈ���� �� = �ι�° ��Ʈ�� ���� ����
    int cnt2 = 0;
    while (*(str2 + cnt2) != '\0')
    {
        *(str1 + cnt + cnt2) = *(str2 + cnt2);
        cnt2++;
    }

    // ������ ��Ʈ�� �������� '\0'�� �߰�
    *(str1 + cnt + cnt2) = '\0';

    return str1;
}

int myStrcmp(char *str1, char *str2)
{
    // ó������ ���ʴ�� ��
    while (*str1 == *str2)
    {
        // '\0'�� ������ �����
        if (*str1 == '\0' || *str2 == '\0')
        {
            break;
        }
        str1++;
        str2++;
    }

    //
    if (*str1 == '\0' && *str2 == '\0')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char arr2[100] = "ABCDEFGHIJKLMNOP";
    char arr[100] = "abcdefghijklmnop";

    printf("srtlen: %d", strlen(arr));
    printf("\nmySrtlen: %d", myStrlen(arr));

    printf("\n%s", myStrcat(arr, arr2));

    printf("\n%d", myStrcmp(arr, arr2));

    return 0;
}