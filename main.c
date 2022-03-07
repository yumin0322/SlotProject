#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT_USE 10000 //자판기 사용 횟수 임의 지정
#define STOCK 50 //음료들  초기 재고값

struct drink_slot
{
    char drink_name[10];
    int price, pay, plus_pay, change, total_pay;
};

typedef struct drink_slot DS;

void check_price(DS *slot, int *menu); // 음료, 가격 지정 함수
void print_pay(DS *slot); // 결제함수
void check_sale(DS *slot, int menu); //판매개수 연산 함수
void count_drink(DS *slot); // 재고확인, 관리하는 함수
void plus_stock(DS *slot); //재고 추가하는 함수
void count_selling(DS *slot); // 판매통계 함수

int orange=STOCK;
int banana=STOCK;
int kiwi=STOCK;
int coke=STOCK;
int cider=STOCK; // 음료들 재고 지정
int orange_sale, banana_sale, kiwi_sale, coke_sale, cider_sale=0; //음료별 판매 횟수

int main()
{
    DS slot[LIMIT_USE];
    int menu = 0;
    int flag =0;

    while(!flag)
    {
        printf("\n\n");
        printf("\t--------------------------------------------------------------------\n\n");
        printf("\t|                     원하는 음료를 선택하세요.                    |\n\n");
        printf("\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
        printf("\t|           1. 오렌지 쥬스           2. 바나나 쥬스                |\n");
        printf("\t|           3. 키위 스무디           4. 콜라                       |\n");
        printf("\t|           5. 사이다                6. 재고 확인, 관리            |\n");
        printf("\t|           7. 판매통계              8. 종료                       |\n\n");
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
            default : printf("\n\t없는 메뉴입니다. \t\n");getchar();getchar();system("cls");break;
        }
    }
    return 0;
}

void check_price(DS *slot, int *menu)
{
    if(menu==1)
    {
        strcpy(slot->drink_name, "오렌지 쥬스");
        slot->price=2000;
    }
    else if(menu==2)
    {
        strcpy(slot->drink_name, "바나나 쥬스");
        slot->price=2000;
    }else if(menu==3)
    {
        strcpy(slot->drink_name, "키위 스무디");
        slot->price=2500;
    }else if(menu==4)
    {
        strcpy(slot->drink_name, "콜라");
        slot->price=1500;
    }else if(menu==5)
    {
        strcpy(slot->drink_name, "사이다");
        slot->price=1500;
    }
    printf("\n\t*        %s 의 가격은 %d 입니다.        * \t\n", slot->drink_name, slot->price);

    return;
}

void print_pay(DS *slot)
{
    printf("\n\t< 취소를 원하실 경우, 0번을 눌러주세요! >\n");
    printf("\n\t결제 금액을 입력해주세요(카드 결제시 정확한 금액을 입력하세요) : ");
    scanf("%d", &slot->pay);


    if(slot->pay==0)
    {
        slot->price=0; //판매금액에서 제외해야하기 때문에
        printf("\n\t취소 하셨습니다. 메뉴로 돌아갑니다. \n");
    }
    else if(slot->pay==slot->price) //카드나 현금으로 딱맞는 금액을 냈을 경우
    {
        printf("\n\t======================================\n");
        printf("\n\t< 결제중입니다. 잠시만 기다려주세요~ >\n");
        printf("\n\t결제 완료됐습니다. 맛있게 드세요! :D \n");
        slot->total_pay+=slot->price;
    }
    else if(slot->pay>slot->price) // 금액을 초과하여 냈을 경우
    {
        slot->change=slot->pay-slot->price;
        printf("\n\t======================================\n");
        printf("\n\t< 결제중입니다. 잠시만 기다려주세요~ >\n");
        printf("\n\t결제 완료됐습니다. 맛있게 드세요! :D  \n");
        printf("\t잔액 : %d원 \n", slot->change);
        slot->total_pay+=slot->price; //결제완료일 경우 판매로 계산하여 총판매액에 더한다.
    }
    else
    {
        while(slot->pay<slot->price) //결제금액이 부족할 경우
        {
            printf("\n\t총 %d원 넣었습니다. %d원이 부족합니다, 추가 입력해주세요 : ", slot->pay, slot->price - slot->pay);
            scanf("%d", &slot->plus_pay);
            slot->pay+=slot->plus_pay;
            if(slot->pay==slot->price)
            {
                printf("\n\t======================================\n");
                printf("\n\t< 결제중입니다. 잠시만 기다려주세요~ >\n");
                printf("\n\t결제 완료됐습니다. 맛있게 드세요! :D \n");
                slot->total_pay+=slot->price;break;
            }
            else if(slot->pay>slot->price)
            {
                slot->change=slot->pay-slot->price;
                printf("\n\t======================================\n");
                printf("\n\t< 결제중입니다. 잠시만 기다려주세요~ >\n");
                printf("\n\t결제 완료됐습니다. 맛있게 드세요! :D \n");
                printf("\n\t잔액 : %d원 \n", slot->change);
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
        if(slot->pay!=0)// 결제취소를 선택했을 경우 제외해야하기 때문에
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

    printf("\t(1) . 재고 확인   |     (2) . 재고 추가      |    (3) . 메뉴로 돌아가기 ");
    scanf("%d", &manage);

    switch(manage)

    {

        case 1 :
                printf("\n\t++++++++++++++++++++++++++++++++++++++++++++\n");
                printf("\n\t+오렌지 쥬스는 %d개 팔렸고 %d개 남았습니다. +\n", orange_sale, orange-orange_sale);
                printf("\n\t+바나나 쥬스는 %d개 팔렸고 %d개 남았습니다. +\n", banana_sale, banana-banana_sale);
                printf("\n\t+키위 스무디는 %d개 팔렸고 %d개 남았습니다. +\n", kiwi_sale, kiwi-kiwi_sale);
                printf("\n\t+콜라는 %d개 팔렸고 %d개 남았습니다.        +\n", coke_sale, coke-coke_sale);
                printf("\n\t+사이다는 %d개 팔렸고 %d개 남았습니다.      +\n", cider_sale, cider-cider_sale);
                printf("\n\t++++++++++++++++++++++++++++++++++++++++++++\n");
                break;

        case 2 : plus_stock(slot);break;

        case 3 : printf("\n\t메뉴로 돌아갑니다. \n");

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
        printf("\n\t추가할 음료를 선택하세요. \n");
        printf("\n\t1. 오렌지 쥬스    2. 바나나 쥬스  3. 체리에이드 \n");
        printf("\n\t4. 콜라           5. 사이다       6. 종료       >> ");
        scanf("%d", &drink_sort);
        printf("\n");


        if(drink_sort==6)

        {
            flag=1;
        }
        else
        {
            printf("\n\t추가 수량을 입력하세요. >>");
            scanf("%d", &plus_drink);

            switch(drink_sort)

            { //재고에 추가, 감소 입력한 plus_drink를 재고 자체에 +=
                case 1 : orange+=plus_drink;printf("\n\t오렌지 쥬스 %d개 추가 되어 현재 오렌지 쥬스 재고 : %d \n", plus_drink, orange-orange_sale);break;

                case 2 : banana+=plus_drink;printf("\n\t바나나 쥬스 %d개 추가 되어 현재 바나나 쥬스 재고 : %d \n", plus_drink, banana-banana_sale);break;

                case 3 : kiwi+=plus_drink;printf("\n\t키위 스무디 %d개 추가 되어 현재 키위 스무디 쥬스 재고 : %d \n", plus_drink, kiwi-kiwi_sale);break;

                case 4 : coke+=plus_drink;printf("\n\t콜라 %d개 추가 되어 현재 콜라 쥬스 재고 : %d \n", plus_drink, coke-coke_sale);break;

                case 5 : cider+=plus_drink;printf("\n\t사이다 %d개 추가 되어 현재 사이다 재고 : %d \n", plus_drink, cider-cider_sale);break;

            }

        }

    }
    return;
}

void count_selling(DS *slot)
{
    printf("\n\t======================================================================\n");
    printf("\n\t오렌지 쥬스 판매 개수 : %d \t", orange_sale);
    printf("\t바나나 쥬스 판매 개수 : %d \t", banana_sale);
    printf("\n\n\t키위 스무디 판매 개수 : %d \t", kiwi_sale);
    printf("\t콜라 쥬스 판매 개수 : %d \t", coke_sale);
    printf("\n\n\t사이다 쥬스 판매 개수 : %d \n\n", cider_sale);
    printf("\n\t======================================================================\n");

    printf("\t총 판매개수 : %d개 \n", orange_sale+banana_sale+kiwi_sale+coke_sale+cider_sale);

    printf("\n\t총 판매액 : %d원", slot->total_pay);

    return;
}
