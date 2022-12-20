#include <stdio.h>
#include <string.h>

int main()
{

    int test_num, cnt;
    scanf("%d", &test_num);

    cnt = test_num;

    for (int i = 0; i < test_num; i++)
    {
        int j = 0, size, index, alpha_cnt = 0;
        char alphabet[26] = {
            0,
        },
             word[100], tem = '!';
        scanf("%s", word);

        size = strlen(word);

        while(j < size)
        {
            index = word[j] - 'a';
 
            if (word[j] != tem)
            {
                tem = word[j];
                alphabet[index] += 1;
            }

            if (alphabet[index] > 1)
            {
                cnt--;
                break;
            }

            j++;
        }
    }

    printf("%d", cnt);

    return 0;
}