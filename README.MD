
자판기 프로그램 목표 : 음료를 선택, 결제, 취소, 결제완료 안내
                      음료 종류별- 팔린 개수, 남은 개수(초기 음료 개수, 50개씩)
		      음료 재고 확인, 채우기(재고 관리)
                      총 판매개수, 매출

[＊] 변수 설정
=>구조체 drink_slot
          {음료의 이름 : drink_name
          결제 변수 : price(음료가격), pay(결제금액), plus_pay(추가결제금액), change(잔            액), total_pay(총 결제금액=총 매출)}
=>전역변수 : 음료별 초기 재고 : int 음료이름=STOCK;
             판매된 음료 개수 : 음료이름_sale 초기값 부여

[1] 메뉴 선택
//반복문(flag사용), switch case문 사용

1-1) 원하는 음료 선택 메뉴// 변수 : menu 로 입력받기
=> check_price 함수 : 메뉴 선택에 따른 음료 종류와 가격 안내
=> print_pay 함수 : 결제 과정(취소값 받기[0]), 추가결제, 잔액, 결제 완료 안내
=> check_sale 함수 : 판매된 음료 개수 확인하는 함수

1-2) 재고 관리, 판매통계 메뉴
=>count_drink 함수 :　재고관리(재고 확인, 재고 추가)
=>count_selling 함수 : 판매통계(음료별 판매개수, 총 판매개수, 총 판매액)

1-3) 프로그램 종료
=>flag=1;

[2] check_price 함수
=> 메뉴 선택에 따라 음료 이름과 가격을 보여준다
// if~ else if문 사용

[3] print_pay 함수
=> 결제 금액에 따라 추가결제 or 잔액 or 결제 완료
if(pay=0){취소값, 입력된 금액 0으로 초기화}
else if(pay==price){결제완료안내, 총 결제 금액(total_pay) 계산}
else if(pay>price){결제완료안내, 잔액(change) 안내, 총 결제 금액(total_pay) 계산}
else(pay<price){ (pay>=price) 될 때까지 추가 결제(plus_pay) 반복문, 위와 동일하게 결제안내, 잔액안내, 총결제 금액 계산}


[4] check_sale 함수
=> 메뉴선택(음료종류)과 결제금액에 따라(결제금액 취소값이 아닌 경우에만(!=0))
판매된 음료 개수 증가 연산 : 음료이름_sale++;

[5]count_drink 함수
=> 재고확인, 재고 추가, 메뉴 돌아가기 (변수 manage로 선택 입력받기)
=> switch case문으로 안내
=> 재고확인 : check_sale함수와 초기 재고값을 이용하여 그대로 출력
=> 재고를 추가하는 기능을 하는 plus_stock 함수 입력

[6]plus_stock 함수
=> 추가할 음료 입력받기(변수 drink_sort)
(!=종료값) 반복문, 조건문, switch case 문
=> 추가 수량 입력받기(변수 plus_drink)
case에 따라 음료 총 재고에 plus_drink을 덧셈 연산, 추가값과 현재고 안내 출력

[7]count_selling 함수
=>check_sale함수와 print_pay함수에서 나온 값을 활용하여
  음료 종류별 판매 개수와 총 판매개수, 총 판매액을 출력
