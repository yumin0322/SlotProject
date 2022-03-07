#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT_USE 10000 //���Ǳ� ��� Ƚ�� ���� ����
#define STOCK 50 //�����  �ʱ� ���

struct drink_slot
{
    char drink_name[10];
    int price, pay, plus_pay, change, total_pay;
};

typedef struct drink_slot DS;

void check_price(DS *slot, int *menu); // ����, ���� ���� �Լ�
void print_pay(DS *slot); // �����Լ�
void check_sale(DS *slot, int menu); //�ǸŰ��� ���� �Լ�
void count_drink(DS *slot); // ���Ȯ��, �����ϴ� �Լ�
void plus_stock(DS *slot); //��� �߰��ϴ� �Լ�
void count_selling(DS *slot); // �Ǹ���� �Լ�

int orange=STOCK;
int banana=STOCK;
int kiwi=STOCK;
int coke=STOCK;
int cider=STOCK; // ����� ��� ����
int orange_sale, banana_sale, kiwi_sale, coke_sale, cider_sale=0; //���Ằ �Ǹ� Ƚ��

int main()
{
    DS slot[LIMIT_USE];
    int menu = 0;
    int flag =0;

    while(!flag)
    {
        printf("\n\n");
        printf("\t--------------------------------------------------------------------\n\n");
        printf("\t|                     ���ϴ� ���Ḧ �����ϼ���.                    |\n\n");
        printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\t|           1. ������ �꽺           2. �ٳ��� �꽺                |\n");
        printf("\t|           3. Ű�� ������           4. �ݶ�                       |\n");
        printf("\t|           5. ���̴�                6. ��� Ȯ��, ����            |\n");
        printf("\t|           7. �Ǹ����              8. ����                       |\n\n");
        printf("\t--------------------------------------------------------------------\n\n");
        printf("\n\t>> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1 : check_price(slot, menu);print_pay(slot);check_sale(slot, menu);getchar();getchar();system("cls");break;
            case 2 : check_price(slot, menu);print_pay(slot);check_sale(slot, menu);getchar();getchar();getchar();system("cls");break;
            case 3 : check_price(slot, menu);print_pay(slot);check_sale(slot, menu);getchar();getchar();getchar();system("cls");break;
            case 4 : check_price(slot, menu);print_pay(slot);check_sale(slot, menu);getchar();getchar();getchar();system("cls");break;
            case 5 : check_price(slot, menu);print_pay(slot);check_sale(slot, menu);getchar();getchar();getchar();system("cls");break;
            case 6 : count_drink(slot);getchar();getchar();system("cls");break;
            case 7 : count_selling(slot);getchar();getchar();system("cls");break;
            case 8 : flag=1;break;
            default : printf("\n\t���� �޴��Դϴ�. \t\n");getchar();getchar();system("cls");break;
        }
    }
    return 0;
}

void check_price(DS *slot, int *menu)
{
    if(menu==1)
    {
        strcpy(slot->drink_name, "������ �꽺");
        slot->price=2000;
    }
    else if(menu==2)
    {
        strcpy(slot->drink_name, "�ٳ��� �꽺");
        slot->price=2000;
    }else if(menu==3)
    {
        strcpy(slot->drink_name, "Ű�� ������");
        slot->price=2500;
    }else if(menu==4)
    {
        strcpy(slot->drink_name, "�ݶ�");
        slot->price=1500;
    }else if(menu==5)
    {
        strcpy(slot->drink_name, "���̴�");
        slot->price=1500;
    }
    printf("\n\t*        %s �� ������ %d �Դϴ�.        * \t\n", slot->drink_name, slot->price);

    return;
}

void print_pay(DS *slot)
{
    printf("\n\t< ��Ҹ� ���Ͻ� ���, 0���� �����ּ���! >\n");
    printf("\n\t���� �ݾ��� �Է����ּ���(ī�� ������ ��Ȯ�� �ݾ��� �Է��ϼ���) : ");
    scanf("%d", &slot->pay);


    if(slot->pay==0)
    {
        slot->price=0; //�Ǹűݾ׿��� �����ؾ��ϱ� ������
        printf("\n\t��� �ϼ̽��ϴ�. �޴��� ���ư��ϴ�. \n");
    }
    else if(slot->pay==slot->price) //ī�峪 �������� ���´� �ݾ��� ���� ���
    {
        printf("\n\t======================================\n");
        printf("\n\t< �������Դϴ�. ��ø� ��ٷ��ּ���~ >\n");
        printf("\n\t���� �Ϸ�ƽ��ϴ�. ���ְ� �弼��! :D \n");
        slot->total_pay+=slot->price;
    }
    else if(slot->pay>slot->price) // �ݾ��� �ʰ��Ͽ� ���� ���
    {
        slot->change=slot->pay-slot->price;
        printf("\n\t======================================\n");
        printf("\n\t< �������Դϴ�. ��ø� ��ٷ��ּ���~ >\n");
        printf("\n\t���� �Ϸ�ƽ��ϴ�. ���ְ� �弼��! :D  \n");
        printf("\t�ܾ� : %d�� \n", slot->change);
        slot->total_pay+=slot->price; //�����Ϸ��� ��� �Ǹŷ� ����Ͽ� ���Ǹž׿� ���Ѵ�.
    }
    else
    {
        while(slot->pay<slot->price) //�����ݾ��� ������ ���
        {
            printf("\n\t�� %d�� �־����ϴ�. %d���� �����մϴ�, �߰� �Է����ּ��� : ", slot->pay, slot->price - slot->pay);
            scanf("%d", &slot->plus_pay);
            slot->pay+=slot->plus_pay;
            if(slot->pay==slot->price)
            {
                printf("\n\t======================================\n");
                printf("\n\t< �������Դϴ�. ��ø� ��ٷ��ּ���~ >\n");
                printf("\n\t���� �Ϸ�ƽ��ϴ�. ���ְ� �弼��! :D \n");
                slot->total_pay+=slot->price;break;
            }
            else if(slot->pay>slot->price)
            {
                slot->change=slot->pay-slot->price;
                printf("\n\t======================================\n");
                printf("\n\t< �������Դϴ�. ��ø� ��ٷ��ּ���~ >\n");
                printf("\n\t���� �Ϸ�ƽ��ϴ�. ���ְ� �弼��! :D \n");
                printf("\n\t�ܾ� : %d�� \n", slot->change);
                slot->total_pay+=slot->price;break;

            }
        }
    }
    return;
}

void check_sale(DS *slot, int menu)
{
    if(menu==1)
    {
        if(slot->pay!=0)// ������Ҹ� �������� ��� �����ؾ��ϱ� ������
        {
            orange_sale++;
        }
    }
    else if(menu==2)
    {
        if(slot->pay!=0)
        {
            banana_sale++;
        }
    }else if(menu==3)
    {
        if(slot->pay!=0)
        {
            kiwi_sale++;
        }
    }else if(menu==4)
    {
        if(slot->pay!=0)
        {
            coke_sale++;
        }
    }else if(menu==5)
    {
        if(slot->pay!=0)
        {
            cider_sale++;
        }
    }
    return;
}
void count_drink(DS *slot)
{
    int manage=0;

    printf("\t(1) . ��� Ȯ��   |     (2) . ��� �߰�      |    (3) . �޴��� ���ư��� ");
    scanf("%d", &manage);

    switch(manage)

    {

        case 1 :
                printf("\n\t++++++++++++++++++++++++++++++++++++++++++++\n");
                printf("\n\t+������ �꽺�� %d�� �ȷȰ� %d�� ���ҽ��ϴ�. +\n", orange_sale, orange-orange_sale);
                printf("\n\t+�ٳ��� �꽺�� %d�� �ȷȰ� %d�� ���ҽ��ϴ�. +\n", banana_sale, banana-banana_sale);
                printf("\n\t+Ű�� ������� %d�� �ȷȰ� %d�� ���ҽ��ϴ�. +\n", kiwi_sale, kiwi-kiwi_sale);
                printf("\n\t+�ݶ�� %d�� �ȷȰ� %d�� ���ҽ��ϴ�.        +\n", coke_sale, coke-coke_sale);
                printf("\n\t+���̴ٴ� %d�� �ȷȰ� %d�� ���ҽ��ϴ�.      +\n", cider_sale, cider-cider_sale);
                printf("\n\t++++++++++++++++++++++++++++++++++++++++++++\n");
                break;

        case 2 : plus_stock(slot);break;

        case 3 : printf("\n\t�޴��� ���ư��ϴ�. \n");

    }

    return;
}

void plus_stock(DS *slot)
{
    int drink_sort=0;
    int plus_drink=0;
    int flag =0;

    while(!flag)

    {
        printf("\n\t�߰��� ���Ḧ �����ϼ���. \n");
        printf("\n\t1. ������ �꽺    2. �ٳ��� �꽺  3. ü�����̵� \n");
        printf("\n\t4. �ݶ�           5. ���̴�       6. ����       >> ");
        scanf("%d", &drink_sort);
        printf("\n");


        if(drink_sort==6)

        {
            flag=1;
        }
        else
        {
            printf("\n\t�߰� ������ �Է��ϼ���. >>");
            scanf("%d", &plus_drink);

            switch(drink_sort)

            { //��� �߰�, ���� �Է��� plus_drink�� ��� ��ü�� +=
                case 1 : orange+=plus_drink;printf("\n\t������ �꽺 %d�� �߰� �Ǿ� ���� ������ �꽺 ��� : %d \n", plus_drink, orange-orange_sale);break;

                case 2 : banana+=plus_drink;printf("\n\t�ٳ��� �꽺 %d�� �߰� �Ǿ� ���� �ٳ��� �꽺 ��� : %d \n", plus_drink, banana-banana_sale);break;

                case 3 : kiwi+=plus_drink;printf("\n\tŰ�� ������ %d�� �߰� �Ǿ� ���� Ű�� ������ �꽺 ��� : %d \n", plus_drink, kiwi-kiwi_sale);break;

                case 4 : coke+=plus_drink;printf("\n\t�ݶ� %d�� �߰� �Ǿ� ���� �ݶ� �꽺 ��� : %d \n", plus_drink, coke-coke_sale);break;

                case 5 : cider+=plus_drink;printf("\n\t���̴� %d�� �߰� �Ǿ� ���� ���̴� ��� : %d \n", plus_drink, cider-cider_sale);break;

            }

        }

    }
    return;
}

void count_selling(DS *slot)
{
    printf("\n\t======================================================================\n");
    printf("\n\t������ �꽺 �Ǹ� ���� : %d \t", orange_sale);
    printf("\t�ٳ��� �꽺 �Ǹ� ���� : %d \t", banana_sale);
    printf("\n\n\tŰ�� ������ �Ǹ� ���� : %d \t", kiwi_sale);
    printf("\t�ݶ� �꽺 �Ǹ� ���� : %d \t", coke_sale);
    printf("\n\n\t���̴� �꽺 �Ǹ� ���� : %d \n\n", cider_sale);
    printf("\n\t======================================================================\n");

    printf("\t�� �ǸŰ��� : %d�� \n", orange_sale+banana_sale+kiwi_sale+coke_sale+cider_sale);

    printf("\n\t�� �Ǹž� : %d��", slot->total_pay);

    return;
}
