#include <stdio.h>
#include <string.h>

int main()
{
    // ���ĺ� ���� ��ġ�� ������ ����Ʈ
    int alphabet[26];

    // �迭 �� ��Ҹ� ��� -1�� �����
    for (int i = 0; i < 26; i++){
        alphabet[i] = -1;
    }

    // �Է� ���� ���ڿ�
    char str[100];
    scanf("%s", str);

    // ���ڿ� ���̸� ���� ����
    int size, index = 0;
    size = strlen(str);

    for (int i = 0; i < size; i++){
        index = str[i] - 97;
        
        if (alphabet[index] == -1){
            alphabet[index] = i;
        }
    }

    for (int i = 0; i< 26; i++){
        printf("%d ", alphabet[i]);
    }

    return 0;
}