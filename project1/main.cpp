/**********************************
����Ʈ���� ���� ���� 3
4�й� 6��
B511187 ����ȯ
B611128 ��â��
B774012 ������
************************************/
// ��� ����
#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
#include "entity.h"

// ��� ����
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;


// �Լ� ����
void doTask();
void program_exit();


// ���� ������� ���� ���� ������ ���� ����.
ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

int main()
{
    doTask();
    return 0;
}


void doTask()
{
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;


    ClientCollection allClients;
    ProductCollection totalProducts; //��ϵ� ��ü ��ǰ ����Ʈ.
    Client* actor = NULL; //���� �α����� ���. 
    Product* selected = NULL; //4.1. ���� 4.2. �������� �� ��ǰ ��� ���Ÿ� ���� ������

    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        fin >> menu_level_1 >> menu_level_2;

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. ȸ�����ԡ� �޴� �κ�
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
                log->tryLogin(fin, allClients, fout); //�α���

                actor = allClients.loginID(); //�α��ε� ���� �޾ƿ���. 3,4�� �� �ʿ�
                fout << "\n";
                break;
            }
            case 2:
            {
                Logout* log_out = new Logout;
                log_out->tryLogout(allClients, fout); //�α׾ƿ�

                fout << "\n";
                actor = NULL; //�α׾ƿ��� ���� �����. 
                break;
            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1://3.1 �Ǹ� �Ƿ� ���
            {
                AddProduct* addProduct = new AddProduct;
                addProduct->run(fin, actor, totalProducts, fout);
                fout << "\n";
                break;
            }
            case 2://3.2 ��� ��ǰ ��ȸ
            {
                ProductForSale* productForSale = new ProductForSale;
                productForSale->run(actor, fout);
                fout << "\n";
                break;
            }
            case 3://3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ
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

            case 1: // "4.1. ��ǰ ���� �˻�" �޴� �κ� input : 4 1 hat
            {
                //cout << "4.1." << endl;
                Search* search = new Search;
                selected = search->run(fin, totalProducts, selected, fout);
                delete search;
                fout << "\n";
                break;
            }
            case 2: // "4.2. ��ǰ ����" �޴� �κ� 
            {
                //cout << "4.2." << endl;
                Purchase* purchase = new Purchase;
                actor = purchase->run(selected, actor, fout);
                fout << "\n";
                break;
            }
            case 3: // "4.3. ��ǰ ���� ���� ��ȸ" �޴� �κ� 
            {
                //cout << "4.3." << endl;
                ShowShopping* showShopping = new ShowShopping;
                showShopping->run(actor, fout);
                fout << "\n";
                break;
            }
            case 4: // "4.4. ��ǰ ���Ÿ����� ��" �޴� �κ� input : 4 4 hat 3
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
            case 1: //5.1 �Ǹ� ��ǰ ���
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
            case 1:   // "6.1. ���ᡰ �޴� �κ�
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
    fout << "6.1.����\n";
    fout << "\n";
    fin.close();
    fout.close();
}