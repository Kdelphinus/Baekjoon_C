#include <stdio.h>
#include <string.h>

int main()
{
    char arr[100] = "gunny";
    char copy[100] = "asdfwerjiogsas";
    char ch = 'u';
    char *pos;
    int box, same;

    // ���ڿ� ũ�⸦ �����ִ� �Լ�
    box = strlen(arr);
    printf("%d\n", box);

    // ���ڿ� ����
    strcpy(copy, arr);    // (�ٿ��ֱ� �� ����Ʈ, ������ ����Ʈ)
    printf("%s\n", copy); // gunny�� ����

    // ���ڿ��� ������ ��, ������ 0, �ٸ��� 0���� ���ڸ� ����
    same = strcmp(arr, copy);

    if (same == 0) //if (!same)�� ���� �ǹ�, 0�� False�� �ǹ��ϱ� ����
    {
        printf("Same String\n");
    }
    else
    {
        printf("Different String\n");
    }

    // ��Ʈ�� �߰�, ��ġ��
    strcat(arr, copy); //(�������� ����Ʈ, ��ĥ ������ �ִ� ����Ʈ)
    printf("%s\n", arr);

    // ��Ʈ�� �ȿ� ���� ã��
    pos = strchr(arr, ch);     // ó�� �߰��� ��ġ�� �����͸� ����
    printf("%s\n", pos);       // �ּҸ� ã���ֱ⿡ �߰��� ���ں��� ���� ���ڵ��� ���� ����
    printf("%d\n", pos - arr); // �̸� Ȱ���Ͽ� �ε����� ���� �� �ִ�

    // ����
    // �� ���� �迭 �ܿ� ���� �Ǵ� ���ڸ� �ϳ� �Է� �޴´�
    // �� ���ڸ�ŭ�� ���ϰų� ī���Ѵ�
    // strncat
    // strncmp
    // strncpy

    // �ڿ������� ���ڸ� ã���ش�
    // strrchr

    return 0;
}