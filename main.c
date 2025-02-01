#include <stdio.h>

#define i8 int8_t
#define u8 u_int8_t
#define i32 u_int32_t

u8 table_reset_print(u8 *table)
{
    i32 i;
    for (i = 0; i < 9; ++i) {
        table[i] = i + 1;
        if (i % 3 == 0)
            printf("\n");
        printf("%d", table[i]);
    }
    printf("\n");
    return 0;
}

u8 table_print(const u8 *table)
{
    i32 i;
    for (i = 0; i < 9; ++i) {
        if (i % 3 == 0)
            printf("\n");
        if (table[i] > 9)
            printf("%c", table[i]);
        else
            printf("%d", table[i]);
    }
    printf("\n");
    return 0;
}

u8 table_check(const u8 *table)
{
    /* XXX
     * 345
     * 678
     */
    if (table[0] == table[1] && table[0] == table[2])
        return 1;
    /* 012
     * XXX
     * 678
     */
    if (table[3] == table[4] && table[3] == table[5])
        return 1;
    /* 012
     * 345
     * XXX
     */
    if (table[6] == table[7] && table[6] == table[8])
        return 1;


    /* X12
     * X45
     * X78
     */
    if (table[0] == table[3] && table[0] == table[6])
        return 1;
    /* 0X2
     * 3X5
     * 6X8
     */
    if (table[1] == table[4] && table[1] == table[7])
        return 1;
    /* 01X
     * 34X
     * 67X
     */
    if (table[2] == table[5] && table[2] == table[8])
        return 1;

    /* X12
     * 3X5
     * 67X
     */
    if (table[0] == table[4] && table[0] == table[8])
        return 1;
    /* 01X
     * 3X5
     * X78
     */
    if (table[2] == table[4] && table[2] == table[6])
        return 1;

    return 0;
}

i32 input_get_choice(i32 *choice)
{
    printf("Choose a spot\n");
    scanf("%d", choice);

    printf("you chose %d", *choice);
    return 0;
}

int main(void)
{
    u8 table[9];
    i32 choice;
    u8 exit;
    i32 i;
    u8 turn;
    turn = 0;
    exit = 0;
    table_reset_print(table);


    while (!exit) {
        for (i = 0; i < 9; i++) {
            input_get_choice(&choice);
            if (turn) {
                table[choice - 1] = 'O';
                turn = 0;
            } else {
                table[choice - 1] = 'X';
                turn = 1;
            }

            table_print(table);

            if (table_check(table)) {
                if (turn) {
                    printf("X WINS!!!\n");
                } else {
                    printf("O WINS!!!\n");
                }
            }

        }
        printf("contineue?\n");
        scanf("%s", &exit);
    }


    return 0;
}
