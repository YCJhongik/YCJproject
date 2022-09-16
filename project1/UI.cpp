#pragma once
#include <iostream>
#include<algorithm>
#include "UI.h"


//1.1. ȸ�� ����
//�Է� : 1 1 [�̸�] [�ֹι�ȣ] [ID] [PW]
//��� : > [�̸�] [�ֹι�ȣ] [ID] [PW]

// Function : void CreateClientAccountUI::interface(ofstream& fout)
// Description: ȸ������ �������̽��� ����ϴ� �Լ�
// Parameters :  ofstream& fout - ���� ����� ���� parameter
// Return Value : x
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void CreateClientAccountUI::interface(ofstream& fout) {
	fout << "1.1. ȸ������" << endl;

}

// Function : Client* CreateClientAccountUI::enterClientInformation(ifstream& fin, ofstream& fout)
// Description: ȸ������ �������̽����� ������ �Է��Ѵ�.
// Parameters :  ifstream& fin - ���� �Է��� ���� parameter
//                   ofstream& fout -���� ����� ���� parameter
// Return Value : newuser - ȸ�������� ��ü�� ����
// Created: 2022/6/01 8:00 pm
// Author: ��â��

Client* CreateClientAccountUI::enterClientInformation(ifstream& fin, ofstream& fout) {
	string name;
	string SSN;
	string ID;
	string PW;
	fin >> name >> SSN >> ID >> PW;  //ȸ������ ���� �Է�
	Client* newuser = new Client;
	newuser->createClient(name, SSN, ID, PW);
	fout << "> " << name << " " << SSN << " " << ID << " " << PW << " " << "\n";  //ȸ������ ���� ���

	return newuser;
};

// Function : void CreateClientAccount::addNewClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout)
// Description: ȸ�������� ���� controll class
// Parameters :  ifstream& fin,  ���� �Է��� ���� parameter
//                   ClientCollection& ALLclients, ȸ������ �� Client ��ü
//                    ofstream& fout ���� ����� ���� parameter
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author:��â��

void CreateClientAccount::addNewClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout) {
	Client* CCA = new Client;  //ȸ�������� client��ü ����
	CCA_UI = new CreateClientAccountUI;
	CCA_UI->interface(fout);   //�������̽� ���
	CCA = CCA_UI->enterClientInformation(fin, fout); //�Է¹��� ȸ������ ���

	ALLclients.addClient(CCA);
}



//1.2. ȸ�� Ż��
//�Է� : 1 2 
//��� : > [ID] 

// Function : void DeleteClientAccountUI::interface(ofstream& fout)
// Description: ȸ��Ż�� �������̽��� ����ϴ� �Լ�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void DeleteClientAccountUI::interface(ofstream& fout) {
	fout << "1.2. ȸ��Ż��" << endl;
}



// Function : void DeleteClientAccountUI::interface(ofstream& fout)
// Description: �α��� ���� ȸ���� Ż���Ű�� �Լ�
// Parameters :  ofstream& fout -���� ����� ���� parameter
//                    ClientCollection& ALLclients - Ż���� ȸ�� ��ü
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void DeleteClientAccountUI::deleteClientAccount(ClientCollection& ALLclients, ofstream& fout) {

	Client* delete_Client = new Client;

	delete_Client = ALLclients.loginID(); //�α������� ȸ�� ��ü�� Ż���ϱ� ���� �ҷ��´�.

	fout << "> " << delete_Client->getClientID() << " " << "\n"; // ȸ��Ż���� ���̵� ���

	ALLclients.deleteClient(delete_Client);
};


// Function : void DeleteClientAccount::deleteClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout)
// Description: ȸ��Ż�� ���� controll class
// Parameters :  ofstream& fout -���� ����� ���� parameter
//                    ClientCollection& ALLclients - Ż���� ȸ�� ��ü
//ifstream& fin - ���� �Է��� ���� parameter
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: ��â��


void DeleteClientAccount::deleteClient(ifstream & fin, ClientCollection & ALLclients, ofstream & fout) {

	DCA_UI = new DeleteClientAccountUI;
	DCA_UI->interface(fout); //�������̽� ���
	DCA_UI->deleteClientAccount(ALLclients, fout); //Ż���� ȸ�����̵� ���

}



//2.1. �α���
//�Է� : 2 1 [ID] [��й�ȣ] 
//��� : > [ID] [��й�ȣ] 

// Function : void LoginUI::interface(ofstream& fout)
// Description: �α��� �������̽��� ����ϴ� �Լ�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void LoginUI::interface(ofstream& fout) {
	fout << "2.1. �α���" << endl;


}

// Function : string* LoginUI::selectLogin(ifstream& fin, ofstream& fout) 
// Description: �α��� ������ �Է��ϴ� �Լ�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    ifstream& fin - ���� �Է��� ���� parameter
// Return Value : ID,PW�� ��� string �迭
// Created: 2022/6/01 8:00 pm
// Author: ��â��

string* LoginUI::selectLogin(ifstream& fin, ofstream& fout) {
	string ID;
	string PW;
	static string ID_PW[2];

	fin >> ID >> PW;  // �α��� ���� �Է�

	ID_PW[0] = ID;
	ID_PW[1] = PW;

	fout << "> " << ID << " " << PW << " " << "\n";  //�α��� ���� ���

	return ID_PW;   // ID,PW�� ��� string �迭 ��ȯ
}


// Function : void Login::tryLogin(ifstream& fin, ClientCollection& ALLclients, ofstream& fout)
// Description: �α����� ���� controll class  
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    ifstream& fin - ���� �Է��� ���� parameter
//ClientCollection& ALLclients - �α��ε� clinet ��ü
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void Login::tryLogin(ifstream & fin, ClientCollection & ALLclients, ofstream & fout)
{

	Login_UI = new LoginUI;
	Login_UI->interface(fout); //�������̽� ���

	//ID,PW�� �ޱ�
	string* PW = Login_UI->selectLogin(fin, fout);

	// ID,PW ��ġ �ϴ� ���� log_status�� 0���� 1�� �����ϱ� ���� ȣ��
	Client* Login_Client = new Client;

	Login_Client = ALLclients.login(PW[0], PW[1]); //�α����� ���̵� ��ü
	Login_Client->set_log(1); // �α��λ��·� ����

}


//2.2. �α׾ƿ�
//�Է� : 2 2 
//��� : > [ID] 

// Function : void LogoutUI::interface(ofstream& fout) 
// Description: �α׾ƿ� �������̽��� ����ϴ� �Լ�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void LogoutUI::interface(ofstream& fout) {
	fout << "2.2. �α׾ƿ�" << endl;


}

// Function : void LogoutUI::selectLogout(ClientCollection& ALLclients, ofstream& fout) 
// Description: �α׾ƿ��� ���̵� �α׾ƿ� ���·� ����
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    ClientCollection& ALLclients - �α׾ƿ��� client ��ü
//		
// Return Value : x 
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void LogoutUI::selectLogout(ClientCollection& ALLclients, ofstream& fout) {
	Client* Logout_Client = new Client;

	Logout_Client = ALLclients.loginID(); //�α������� ȸ�� ��ü 
	Logout_Client->set_log(0); // �α��λ��·� ����


	fout << "> " << Logout_Client->getClientID() << " " << "\n"; // �α��ƿ� �� ���̵� ���

};


// Function : void Logout::tryLogout(ClientCollection& ALLclients, ofstream& fout) 
// Description: �α׾ƿ��� ���� controll class 
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    ClientCollection& ALLclients - �α׾ƿ��� client ��ü
//		
// Return Value : x 
// Created: 2022/6/01 8:00 pm
// Author: ��â��

void Logout::tryLogout(ClientCollection& ALLclients, ofstream& fout) {

	Logout_UI = new LogoutUI;
	Logout_UI->interface(fout); //�������̽� ���
	Logout_UI->selectLogout(ALLclients, fout); //Ż���� ȸ�����̵� ���

}


//3.1. �Ǹ� �Ƿ� ���
//�Է� : 3 1 [��ǰ��] [����ȸ���] [����] [����] 
//��� : > [��ǰ��] [����ȸ���] [����] [����]  

// Function : void AddProductUI::startInterface(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft, ofstream& fout)
// Description: �Ǹ��Ƿ� ����� ���� ���� �Է��ϱ� ���� �������̽�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                   (ifstream& fin -���� �Է��� ���� parameter
//                    string& productName, string& companyName, int& cost, int& quantityLeft - ��ǰ��,ȸ���,����,���� 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void AddProductUI::startInterface(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft, ofstream& fout)
{
	fout << "3.1. �Ǹ� �Ƿ� ���" << endl;
	enterInformation(fin, productName, companyName, cost, quantityLeft);
}
// Function : void AddProductUI::enterInformation(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft)
// Description: �Ǹ��Ƿ� ����� ���� ���� �Է¹޴� �������̽�
// Parameters : ifstream& fin -���� �Է��� ���� parameter
//                    string& productName, string& companyName, int& cost, int& quantityLeft - ��ǰ��,ȸ���,����,���� 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ
void AddProductUI::enterInformation(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft)
{
	fin >> productName >> companyName >> cost >> quantityLeft;
}

// Function : void AddProductUI::printNewProduct(ofstream& fout, Product* product)
// Description: ����� �Ƿ��� ���� ���� ���
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                    Product* product - ����� Product ��ü
//                    
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void AddProductUI::printNewProduct(ofstream& fout, Product* product)
{
	string sellerID; //�� ������ �޾ƿ;���
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	int score; //�� ������ �޾ƿ;���

	product->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
	fout << "> " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " " << "\n";

}
// Function : void AddProduct::run(ifstream& fin, Client* actor, ProductCollection& totalProduct, ofstream& fout)
// Description: �Ǹ��Ƿ� ����� ���� controll class 
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                   ifstream& fin,  - ���� �Է��� ���� paramgter
//                    Client* actor, ProductCollection& totalProduct, - ����ϴ� client ��ü�� product�� ��ϵ� productCollection Ŭ����
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void AddProduct::run(ifstream& fin, Client* actor, ProductCollection& totalProduct, ofstream& fout)
{
	//1.interface�ҷ��ͼ� ���� �Է� �ޱ�
	//2. ��ǰ �����ϱ� 
	//3. actor�� �Ǹ����� ��ǰ ��� �߰�
	//4. ��ü ��ǰ ����Ʈ�� �� ��ǰ �߰�.
	//5. fout���� ��ǰ ���� ���. 

	string productName, companyName;
	int cost, quantityLeft;

	AddProductUI* UI = new AddProductUI;
	UI->startInterface(fin, productName, companyName, cost, quantityLeft, fout);
	Product* newProduct = new Product(actor, productName, companyName, cost, quantityLeft);
	actor->addSoldProduct(newProduct);
	totalProduct.addProduct(newProduct);//��ü ��ǰ ����Ʈ�� ���. 

	UI->printNewProduct(fout, newProduct);
}



//3.2. ��� ��ǰ ��ȸ 
//�Է� : 3 2 
//��� : > { [��ǰ��] [����ȸ���] [����] [����] } 

// Function : void ProductForSaleUI::startInterface(ofstream& fout)
// Description: ��ϻ�ǰ ��ȸ �������̽�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ProductForSaleUI::startInterface(ofstream& fout)
{
	fout << "3.2. ��� ��ǰ ��ȸ" << endl;
}


// Function : void ProductForSaleUI::showProductForSales(ProductCollection products, ofstream& fout)
// Description: ����� ��ǰ�� ����ϴ� �Լ�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                 ProductCollection products - ��ϵ� ��ǰ�� ã�� ���� productCollection
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ProductForSaleUI::showProductForSales(ProductCollection products, ofstream& fout)
{
	if (products.getSize() == 0)
	{
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	int score;

	products.sortList();

	for (int i = 0; i < products.getSize(); ++i)
	{
		if (products.getProduct(i)->getQuantityLeft() != 0) //��� 0�� �ƴϸ�
		{
			products.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
			fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << "\n";
		}
	}
}

// Function : void ProductForSale::run(Client* actor, ofstream& fout)
// Description: ��ǰ ����� ���� controll class
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                  Client* actor, - ��� ��ǰ ��ȸ�� ���� client ��ü
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ProductForSale::run(Client* actor, ofstream& fout)
{
	ProductForSaleUI* UI = new ProductForSaleUI;
	UI->startInterface(fout);
	ProductCollection list = actor->getSoldProductList();
	UI->showProductForSales(list, fout);
}

//3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ 
//�Է� : 3 3
//��� : > {[��ǰ��] [����ȸ���] [����] [�Ǹŵ� ����] [��� ���Ÿ�����] }*

// Function : void ListSoldProductUI::startInterface(ofstream& fout)
// Description: �Ǹ� �Ϸ� ��ǰ ��ȸ �������̽�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ListSoldProductUI::startInterface(ofstream& fout)
{
	fout << "3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;
}

// Function : void ListSoldProductUI::showSoldProductList(ProductCollection products, ofstream& fout)
// Description: �Ǹ� �Ϸ� ��ǰ�� ����ϴ� �Լ�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                   ProductCollection products - �ǸſϷ� ��ǰ�� ã�� ���� productcollection class
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ListSoldProductUI::showSoldProductList(ProductCollection products, ofstream& fout)
{
	if (products.getSize() == 0)
	{
		cout << "�Ǹ� �Ϸ� ��ǰ ����" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	int score;
	int quantitySold;

	products.sortList();//�������� ���

	for (int i = 0; i < products.getSize(); ++i)
	{
		if (products.getProduct(i)->getQuantityLeft() == 0) //��� 0�̸�
		{
			products.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
			quantitySold = products.getProduct(i)->getQuantitySold();
			fout << "> " << productName << " " << companyName << " " << productCost << " " << quantitySold << " " << score << "\n";
		}
	}
}

// Function : void ListSoldProduct::run(Client* actor, ofstream& fout)
// Description: �Ǹ� �Ϸ� ��ǰ ��ȸ�� ���� controll class
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                   Client* actor - �Ǹ��� ��ü
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ListSoldProduct::run(Client* actor, ofstream& fout)
{
	ListSoldProductUI* UI = new ListSoldProductUI;
	UI->startInterface(fout);
	ProductCollection list = actor->getSoldProductList();
	UI->showSoldProductList(list, fout);
}


//4.1. ��ǰ ���� �˻� ����
//�Է� : 4 1 [��ǰ��] 
//��� : > [�Ǹ���ID] [��ǰ��] [����ȸ���] [����] [��������] [��� ���Ÿ�����]

// Function : void SearchUI::startInterface(ifstream& fin, ofstream& fout)
// Description: ��ǰ���� �˻� �������̽�
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                  ifstream& fin - ���� �Է��� ���� parameter	
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: ������

void SearchUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "4.1. ��ǰ ���� �˻�" << endl;

	string productName;
	fin >> productName;
	this->productName = productName;
}

// Function : void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) 
// Description: ��ǰ���� �˻� �� ��ǰ���� ���
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                  Search* search, -������ ��ü class
//          	ProductCollection products - Product�� ��Ƴ��� class
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: ������

void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //��ǰ ���� �˻� 2.
{
	string sellerID;
	string name;
	string companyName;
	int productCost;
	int quantityLeft;
	int score;

	this->selected = search->searchProduct(this->productName, products);
	if (selected->getQuantityLeft() == 0) return; //��� ������ �˻���������.
	selected->getProductDetails(sellerID, name, companyName, productCost, quantityLeft, score);
	fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " " << score << "\n";
}


// Function : Product* SearchUI::selectPurchase()
// Description: ��ǰ���� �˻� �� ��ǰ���� ���
// Parameters :  x
//          	
// Return Value : ������ ��ü 
// Created: 2022/5/30 8:00 pm
// Author: ������

Product* SearchUI::selectPurchase()
{
	return selected;
}

// Function : Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout)
// Description: ��ǰ���� �˻��� ���� controll class 
// Parameters :  ofstream& fout- ���� ����� ���� parameter
//                  ifstream& fin - ���� �Է��� ���� parameter
//                  ProductCollection products, Product*& selected // product collection ��ü, ���õ� ��ü
// Return Value :  ���õ� product ���Ź�ư ��ȯ 
// Created: 2022/5/30 8:00 pm
// Author: ������

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout)
{

	searchUI = new SearchUI;
	searchUI->startInterface(fin, fout); //��ǰ�� �Է� ����
	searchUI->enterProductName(this, products, fout); //�Է¹��� ��ǰ ���� ��� 

	selected = searchUI->selectPurchase(); //���� ��ư ��ȯ.
	if (selected->getQuantityLeft() == 0) return NULL;
	
	return selected;
}
// Function : Product* Search::searchProduct(string productName, ProductCollection products) 
// Description: ��ǰ���� �˻��� ���� controll class 
// Parameters :  string productName, - ��ǰ��
//		ProductCollection products - ��ǰ�� ��Ƴ��� class
// Return Value : ��ǰ�� �ش��ϴ� product ��ü
// Created: 2022/5/30 8:00 pm
// Author: ������

Product* Search::searchProduct(string productName, ProductCollection products)
{
	Product* product = products.findProduct(productName);
	//product->getProductDetails(); 
	return product;
}


//4.2. ��ǰ ���� ����
//�Է� : 4 2
//��� : > [�Ǹ���ID] [��ǰ��]

// Function : void PurchaseUI::startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase)
// Description: ��ǰ���� �˻� �������̽�
// Parameters :  Product* product, Client* actor, ofstream& fout, Purchase* purchase
//                        ������ ��ǰ  ,   ������ ȸ�� , ����� ���� parameter,  	���Ź�ư
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: ������

void PurchaseUI::startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase)
{
	fout << "4.2. ��ǰ ����\n";
	if (!product) return; //�˻����� ���� ���(��� ���� ���) �Ǹ� �Ұ�. 
	if (product->getQuantityLeft() == 0)return; //������ ��� �Ǹ� �Ұ�. 
	this->purchase = purchase;
	purchaseProduct();
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //�Ǹ��� ���̵�� ��ǰ��.
}

// Function : void PurchaseUI::purchaseProduct() 
// Description: ��ǰ���� �� �������ϴ� �Լ�
// Parameters :  X
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: ������

void PurchaseUI::purchaseProduct()
{
	purchase->purchaseProduct();
}

// Function : Client* Purchase::run(Product* product, Client* actor, ofstream& fout)
// Description: ���Ÿ� ���� controll class
// Parameters :  Product* product, Client* actor, - ������ ��ǰ, ������ ȸ��
// 		ofstream& fout - ����� ���� parameter
// Return Value : ������ ȸ�� ��ü
// Created: 2022/5/30 8:00 pm
// Author: ������

Client* Purchase::run(Product* product, Client* actor, ofstream& fout)
{
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(product, actor, fout, this); //4.1.

	return actor;
}
// Function : void Purchase::purchaseProduct()
// Description: �����ڿ��� �������� �߰� �� ��� ����
// Parameters :  x
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: ������

void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.�����ڿ��� ���� ���� �߰�
	product->stockCorrection(); //4.1.1.1.2.��� ����
}

//4.3. ��ǰ ���� ���� ��ȸ
//�Է� : 4 3
//��� : >{ [�Ǹ���ID] [��ǰ��] [����ȸ���] [����] [��������] [��� ���Ÿ�����] } *

// Function : void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
// Description: ��ǰ ���ų��� ��ȸ �������̽�
// Parameters :  ProductCollection list, - ��ǰ ����Ʈ
//		ofstream& fout - ����� ���� parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: ������

void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
{
	fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
	if (list.getSize() == 0)
	{
		cout << "���� ���� ����" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	int score;

	list.sortList();

	for (int i = 0; i < list.getSize(); ++i)
	{
		list.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
		fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " " << score << "\n";
	}
}


// Function : void ShowShopping::run(Client* actor, ofstream& fout)
// Description: ��ǰ ���ų��� ��ȸ�� ���� controll class
// Parameters :   Client* actor, - ��ȸ�� ȸ�� ��ü
//		ofstream& fout - ����� ���� parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: ������

void ShowShopping::run(Client* actor, ofstream& fout)
{
	ProductCollection list;
	ShowShoppingListUI UI;
	list = actor->getPurchasedProductList(); //���� ���� �ҷ�����.

	UI.startInterface(list, fout); //���ų��� interface�� ����. 
}


//4.4. ��ǰ ���� ������ ��
//�Է� : 4 4 [��ǰ��] [���Ÿ�����]
//��� : > [�Ǹ���ID] [��ǰ��] [���Ÿ�����] 

// Function : void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
// Description: ��ǰ ���Ÿ����� �� �������̽�
// Parameters :  string& productName, int& score, - ��ǰ��� ������ ����
//		ofstream& fout - ����� ���� parameter
// 		ifstream& fin, - �Է��� ���� parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: ������

void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
{
	fout << "4.4. ��ǰ ���� ������ ��\n";
	enterNameAndScore(fin, productName, score);
}

// Function : void SatisfactionScoreUI::printScore(string sellerID, string productName, int score, ofstream& fout)
// Description: ��ǰ ���Ÿ�����print �Լ�
// Parameters :  string sellerID, string productName, int score - �Ǹ��� ID, ��ǰ��, ���Ÿ�����
//		ofstream& fout - ����� ���� parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: ������

void SatisfactionScoreUI::printScore(string sellerID, string productName, int score, ofstream& fout)
{
	fout << "> " << sellerID << " " << productName << " " << score << "\n";
}

// Function : void SatisfactionScoreUI::enterNameAndScore(ifstream& fin, string& productName, int& score)
// Description: ��ǰ��� ���Ÿ����� ������ �Է¹޴� �Լ�. 
// Parameters :  ifstream& fin : �Է��� ���� parameter
//				 string& productName, int& score : ��ǰ��, ����
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: ������
void SatisfactionScoreUI::enterNameAndScore(ifstream& fin, string& productName, int& score) 
{
	fin >> productName >> score; //��ǰ��� ���� ������ �Է� ����
}
// Function : void SatisfactionScore::run(ifstream& fin, Client* actor, ofstream& fout)
// Description: ��ǰ ���Ÿ����� �򰡸� ���� controll class 
// Parameters :  Client* actor - ȸ�� ��ü
//		ofstream& fout - ����� ���� parameter
//		ifstream& fin - �Է��� ���� parameter		
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: ������

void SatisfactionScore::run(ifstream& fin, Client* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score, fout); //UI���� ��ǰ��� ������ �Է�. 

	ProductCollection list;
	list = actor->getPurchasedProductList(); //���� ����Ʈ �ҷ�����.
	Product* product;
	product = list.findProduct(productName); //��ǰ������ ��ǰ ã��.
	product->setScore(score); //��� ������ ����

	UI->printScore(product->getSellerID(), productName, score, fout); //UI���� �Ǹ��� ID, ��ǰ��, ��� ������ ���.

}

//
//5.1. �Ǹ� ��ǰ ���
//�Է� : 5 1
//��� : >{ [��ǰ��] [��ǰ �Ǹ� �Ѿ�] [��� ���� ������] }*

// Function : void ShowStatisticsUI::startInterface(ofstream& fout)
// Description: �ǸŻ�ǰ ��� �������̽�
// Parameters :  ofstream& fout - ����� ���� parameter
//
// Return Value : x
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ShowStatisticsUI::startInterface(ofstream& fout)
{
	fout << "5.1. �Ǹ� ��ǰ ���" << endl;
}

// Function : void ShowStatisticsUI::showStatistics(ProductCollection list, ofstream& fout)
// Description: �ǸŻ�ǰ ��踦 ����ϴ� �Լ�
// Parameters :  ofstream& fout - ����� ���� parameter
//		ProductCollection list- ��ǰ ����Ʈ
// Return Value : x
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ

void ShowStatisticsUI::showStatistics(ProductCollection list, ofstream& fout)
{
	string productName;
	int totalCost;
	int score;

	for (int i = 0; i < list.getSize(); ++i)
	{
		productName = list.getProduct(i)->getName();
		totalCost = list.getProduct(i)->calculateProfit();
		score = list.getProduct(i)->getScore();
		fout << productName << " " << totalCost << " " << score << "\n";
	}
}

// Function : void ShowStatisticsUI::showStatistics(ProductCollection list, ofstream& fout)
// Description: �ǸŻ�ǰ ��踦 ����. controll class
// Parameters :  ofstream& fout - ����� ���� parameter
//		Client* actor -ȸ�� ��ü
// Return Value : x
// Created: 2022/5/31 8:00 pm
// Author: ����ȯ
void ShowStatistic::run(Client* actor, ofstream& fout)
{
	ShowStatisticsUI* UI = new ShowStatisticsUI;
	UI->startInterface(fout);

	ProductCollection list = actor->getSoldProductList();
	UI->showStatistics(list, fout);

}