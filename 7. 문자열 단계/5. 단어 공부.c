#include <stdio.h>
#include <string.h>

int main()
{
    int size, index, max = 0, word;
    char sentnece[1000001];
    int alphabet[26] = {
        0,
    };
    scanf("%s", sentnece);

    //strupr(sentnece); // �빮�ڷ� �� �ٲ���
    size = strlen(sentnece);

    for (int i = 0; i < size; i++)
    {
        if (sentnece[i] <= 'Z' && sentnece[i] >= 'A')
        {
            index = sentnece[i] - 'A';
            alphabet[index] += 1;
        }

        else if (sentnece[i] <= 'z' && sentnece[i] >= 'a')
        {
            index = sentnece[i] - 'a';
            alphabet[index] += 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > max)
        {
            max = alphabet[i];
            word = i + 65; // 65�� �ƽ�Ű �ڵ�� A��
        }
        else if (alphabet[i] == max)
        {
            word = 63; // 63�� �ƽ�Ű�ڵ�� ?��
        }
    }

    printf("%c", word);

    return 0;
}