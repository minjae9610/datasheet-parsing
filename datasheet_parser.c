#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

// typedef union datasheet_parser
// {
//     struct
//     {
//         uint16_t weight;
//         uint16_t passbook_password;
//         uint16_t desired_salary;
//         uint8_t favorite_foods[4];
//         uint8_t favorite_drink[4];
//     } data;
//     uint8_t raw[14];
// } Parser;

typedef struct datasheet_parser
{
    uint16_t weight;
    uint16_t passbook_password;
    uint16_t desired_salary;
    uint8_t favorite_foods[4];
    uint8_t favorite_drink[4];
} Parser;

int main()
{
    FILE *fp = fopen("binary", "rb");

    uint8_t buf[14];
    fread(buf, 1, 14, fp);

    fclose(fp);

    printf("Offset\t");
    for (int i = 0; i < 14; i++)
        printf("%02X ", i);
    printf("\n");
    printf("Value\t");
    for (int i = 0; i < 14; i++)
        printf("%02x ", buf[i]);
    printf("\n");

    Parser *parser = (Parser *)buf;

    printf("======== DEC ========\n");
    printf("Weight: %d\n", parser->weight);
    printf("Passbook Password: %d\n", parser->passbook_password);
    printf("Desired Salary: %d\n", parser->desired_salary);
    printf("Favorite Foods: ");
    for (int i = 3; i >= 0; --i)
        printf("%d ", parser->favorite_foods[i]);
    printf("\n");
    printf("Favorite Drinks: ");
    for (int i = 3; i >= 0; --i)
        printf("%d ", parser->favorite_drink[i]);
    printf("\n");

    printf("======== HEX ========\n");
    printf("Weight: %04X\n", parser->weight);
    printf("Passbook Password: %04X\n", parser->passbook_password);
    printf("Desired Salary: %04X\n", parser->desired_salary);
    printf("Favorite Foods: ");
    for (int i = 3; i >= 0; --i)
        printf("%X ", parser->favorite_foods[i]);
    printf("\n");
    printf("Favorite Drinks: ");
    for (int i = 3; i >= 0; --i)
        printf("%X ", parser->favorite_drink[i]);
    printf("\n");

    printf("======== ASCII ========\n");
    printf("Favorite Foods: ");
    for (int i = 3; i >= 0; --i)
        printf("%c", parser->favorite_foods[i]);
    printf("\n");
    printf("Favorite Drinks: ");
    for (int i = 3; i >= 0; --i)
        printf("%c", parser->favorite_drink[i]);
    printf("\n");

    return 0;
}