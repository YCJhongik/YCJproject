/**********************************
소프트웨어 공학 과제 3
4분반 6조
B511187 정지환
B611128 유창조
B774012 유민지
************************************/
// 헤더 선언
#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
#include "entity.h"

// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;


// 함수 선언
void doTask();
void program_exit();


// 파일 입출력을 위한 파일 포인터 변수 선언.
ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

int main()
{
    doTask();
    return 0;
}


void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;


    ClientCollection allClients;
    ProductCollection totalProducts; //등록된 전체 상품 리스트.
    Client* actor = NULL; //현재 로그인한 사람. 
    Product* selected = NULL; //4.1. 이후 4.2. 선택했을 때 상품 즉시 구매를 위한 포인터

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fin >> menu_level_1 >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {
                CreateClientAccount* client = new CreateClientAccount;
                client->addNewClient(fin, allClients, fout);
                fout << "\n";

                break;
            }
            case 2:
            {
                DeleteClientAccount* dclient = new DeleteClientAccount;
                dclient->deleteClient(fin, allClients, fout);
                fout << "\n";

                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                Login* log = new Login;
                log->tryLogin(fin, allClients, fout); //로그인

                actor = allClients.loginID(); //로그인된 액터 받아오기. 3,4에 꼭 필요
                fout << "\n";
                break;
            }
            case 2:
            {
                Logout* log_out = new Logout;
                log_out->tryLogout(allClients, fout); //로그아웃

                fout << "\n";
                actor = NULL; //로그아웃된 액터 지우기. 
                break;
            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1://3.1 판매 의류 등록
            {
                AddProduct* addProduct = new AddProduct;
                addProduct->run(fin, actor, totalProducts, fout);
                fout << "\n";
                break;
            }
            case 2://3.2 등록 상품 조회
            {
                ProductForSale* productForSale = new ProductForSale;
                productForSale->run(actor, fout);
                fout << "\n";
                break;
            }
            case 3://3.3 판매 완료 상품 조회
            {
                ListSoldProduct* listSoldProduct = new ListSoldProduct;
                listSoldProduct->run(actor, fout);
                fout << "\n";
                break;
            }
            }
            break;
        }
        case 4:
        {
            switch (menu_level_2)
            {

            case 1: // "4.1. 상품 정보 검색" 메뉴 부분 input : 4 1 hat
            {
                //cout << "4.1." << endl;
                Search* search = new Search;
                selected = search->run(fin, totalProducts, selected, fout);
                delete search;
                fout << "\n";
                break;
            }
            case 2: // "4.2. 상품 구매" 메뉴 부분 
            {
                //cout << "4.2." << endl;
                Purchase* purchase = new Purchase;
                actor = purchase->run(selected, actor, fout);
                fout << "\n";
                break;
            }
            case 3: // "4.3. 상품 구매 내역 조회" 메뉴 부분 
            {
                //cout << "4.3." << endl;
                ShowShopping* showShopping = new ShowShopping;
                showShopping->run(actor, fout);
                fout << "\n";
                break;
            }
            case 4: // "4.4. 상품 구매만족도 평가" 메뉴 부분 input : 4 4 hat 3
            {
                //cout << "4.4." << endl;
                SatisfactionScore* satisfactionScore = new SatisfactionScore;
                satisfactionScore->run(fin, actor, fout);
                fout << "\n";
                break;
            }
            }
            break;
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1: //5.1 판매 상품 통계
            {
                //cout << "5.1." << endl;
                ShowStatistic* showStatistic = new ShowStatistic;
                showStatistic->run(actor, fout);
                fout << "\n";
                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {
                program_exit();
                is_program_exit = 1;
                //break;
                return;
            }
            }
            break;
        }
        } //switch 1        
    }
}

void program_exit()
{
    fout << "6.1.종료\n";
    fout << "\n";
    fin.close();
    fout.close();
}