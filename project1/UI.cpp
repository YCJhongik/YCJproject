#pragma once
#include <iostream>
#include<algorithm>
#include "UI.h"


//1.1. 회원 가입
//입력 : 1 1 [이름] [주민번호] [ID] [PW]
//출력 : > [이름] [주민번호] [ID] [PW]

// Function : void CreateClientAccountUI::interface(ofstream& fout)
// Description: 회원가입 인터페이스를 출력하는 함수
// Parameters :  ofstream& fout - 파일 출력을 위한 parameter
// Return Value : x
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void CreateClientAccountUI::interface(ofstream& fout) {
	fout << "1.1. 회원가입" << endl;

}

// Function : Client* CreateClientAccountUI::enterClientInformation(ifstream& fin, ofstream& fout)
// Description: 회원가입 인터페이스에서 정보를 입력한다.
// Parameters :  ifstream& fin - 파일 입력을 위한 parameter
//                   ofstream& fout -파일 출력을 위한 parameter
// Return Value : newuser - 회원가입할 객체를 리턴
// Created: 2022/6/01 8:00 pm
// Author: 유창조

Client* CreateClientAccountUI::enterClientInformation(ifstream& fin, ofstream& fout) {
	string name;
	string SSN;
	string ID;
	string PW;
	fin >> name >> SSN >> ID >> PW;  //회원가입 정보 입력
	Client* newuser = new Client;
	newuser->createClient(name, SSN, ID, PW);
	fout << "> " << name << " " << SSN << " " << ID << " " << PW << " " << "\n";  //회원가입 정보 출력

	return newuser;
};

// Function : void CreateClientAccount::addNewClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout)
// Description: 회원가입을 위한 controll class
// Parameters :  ifstream& fin,  파일 입력을 위한 parameter
//                   ClientCollection& ALLclients, 회원가입 될 Client 객체
//                    ofstream& fout 파일 출력을 위한 parameter
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author:유창조

void CreateClientAccount::addNewClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout) {
	Client* CCA = new Client;  //회원가입할 client객체 생성
	CCA_UI = new CreateClientAccountUI;
	CCA_UI->interface(fout);   //인터페이스 출력
	CCA = CCA_UI->enterClientInformation(fin, fout); //입력받은 회원정보 출력

	ALLclients.addClient(CCA);
}



//1.2. 회원 탈퇴
//입력 : 1 2 
//출력 : > [ID] 

// Function : void DeleteClientAccountUI::interface(ofstream& fout)
// Description: 회원탈퇴 인터페이스를 출력하는 함수
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void DeleteClientAccountUI::interface(ofstream& fout) {
	fout << "1.2. 회원탈퇴" << endl;
}



// Function : void DeleteClientAccountUI::interface(ofstream& fout)
// Description: 로그인 중인 회원을 탈퇴시키는 함수
// Parameters :  ofstream& fout -파일 출력을 위한 parameter
//                    ClientCollection& ALLclients - 탈퇴할 회원 객체
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void DeleteClientAccountUI::deleteClientAccount(ClientCollection& ALLclients, ofstream& fout) {

	Client* delete_Client = new Client;

	delete_Client = ALLclients.loginID(); //로그인중인 회원 객체를 탈퇴하기 위해 불러온다.

	fout << "> " << delete_Client->getClientID() << " " << "\n"; // 회원탈퇴할 아이디 출력

	ALLclients.deleteClient(delete_Client);
};


// Function : void DeleteClientAccount::deleteClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout)
// Description: 회원탈퇴를 위한 controll class
// Parameters :  ofstream& fout -파일 출력을 위한 parameter
//                    ClientCollection& ALLclients - 탈퇴할 회원 객체
//ifstream& fin - 파일 입력을 위한 parameter
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: 유창조


void DeleteClientAccount::deleteClient(ifstream & fin, ClientCollection & ALLclients, ofstream & fout) {

	DCA_UI = new DeleteClientAccountUI;
	DCA_UI->interface(fout); //인터페이스 출력
	DCA_UI->deleteClientAccount(ALLclients, fout); //탈퇴한 회원아이디 출력

}



//2.1. 로그인
//입력 : 2 1 [ID] [비밀번호] 
//출력 : > [ID] [비밀번호] 

// Function : void LoginUI::interface(ofstream& fout)
// Description: 로그인 인터페이스를 출력하는 함수
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void LoginUI::interface(ofstream& fout) {
	fout << "2.1. 로그인" << endl;


}

// Function : string* LoginUI::selectLogin(ifstream& fin, ofstream& fout) 
// Description: 로그인 정보를 입력하는 함수
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    ifstream& fin - 파일 입력을 위한 parameter
// Return Value : ID,PW가 담긴 string 배열
// Created: 2022/6/01 8:00 pm
// Author: 유창조

string* LoginUI::selectLogin(ifstream& fin, ofstream& fout) {
	string ID;
	string PW;
	static string ID_PW[2];

	fin >> ID >> PW;  // 로그인 정보 입력

	ID_PW[0] = ID;
	ID_PW[1] = PW;

	fout << "> " << ID << " " << PW << " " << "\n";  //로그인 정보 출력

	return ID_PW;   // ID,PW가 담긴 string 배열 반환
}


// Function : void Login::tryLogin(ifstream& fin, ClientCollection& ALLclients, ofstream& fout)
// Description: 로그인을 위한 controll class  
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    ifstream& fin - 파일 입력을 위한 parameter
//ClientCollection& ALLclients - 로그인될 clinet 객체
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void Login::tryLogin(ifstream & fin, ClientCollection & ALLclients, ofstream & fout)
{

	Login_UI = new LoginUI;
	Login_UI->interface(fout); //인터페이스 출력

	//ID,PW값 받기
	string* PW = Login_UI->selectLogin(fin, fout);

	// ID,PW 일치 하는 계정 log_status값 0에서 1로 변경하기 위해 호출
	Client* Login_Client = new Client;

	Login_Client = ALLclients.login(PW[0], PW[1]); //로그인할 아이디 객체
	Login_Client->set_log(1); // 로그인상태로 변경

}


//2.2. 로그아웃
//입력 : 2 2 
//출력 : > [ID] 

// Function : void LogoutUI::interface(ofstream& fout) 
// Description: 로그아웃 인터페이스를 출력하는 함수
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    
// Return Value : X
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void LogoutUI::interface(ofstream& fout) {
	fout << "2.2. 로그아웃" << endl;


}

// Function : void LogoutUI::selectLogout(ClientCollection& ALLclients, ofstream& fout) 
// Description: 로그아웃할 아이디를 로그아웃 상태로 변경
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    ClientCollection& ALLclients - 로그아웃할 client 객체
//		
// Return Value : x 
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void LogoutUI::selectLogout(ClientCollection& ALLclients, ofstream& fout) {
	Client* Logout_Client = new Client;

	Logout_Client = ALLclients.loginID(); //로그인중인 회원 객체 
	Logout_Client->set_log(0); // 로그인상태로 변경


	fout << "> " << Logout_Client->getClientID() << " " << "\n"; // 로구아웃 한 아이디 출력

};


// Function : void Logout::tryLogout(ClientCollection& ALLclients, ofstream& fout) 
// Description: 로그아웃을 위한 controll class 
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    ClientCollection& ALLclients - 로그아웃할 client 객체
//		
// Return Value : x 
// Created: 2022/6/01 8:00 pm
// Author: 유창조

void Logout::tryLogout(ClientCollection& ALLclients, ofstream& fout) {

	Logout_UI = new LogoutUI;
	Logout_UI->interface(fout); //인터페이스 출력
	Logout_UI->selectLogout(ALLclients, fout); //탈퇴한 회원아이디 출력

}


//3.1. 판매 의류 등록
//입력 : 3 1 [상품명] [제작회사명] [가격] [수량] 
//출력 : > [상품명] [제작회사명] [가격] [수량]  

// Function : void AddProductUI::startInterface(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft, ofstream& fout)
// Description: 판매의류 등록을 위한 정보 입력하기 위한 인터페이스
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                   (ifstream& fin -파일 입력을 위한 parameter
//                    string& productName, string& companyName, int& cost, int& quantityLeft - 상품명,회사명,가격,수량 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void AddProductUI::startInterface(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft, ofstream& fout)
{
	fout << "3.1. 판매 의류 등록" << endl;
	enterInformation(fin, productName, companyName, cost, quantityLeft);
}
// Function : void AddProductUI::enterInformation(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft)
// Description: 판매의류 등록을 위한 정보 입력받는 인터페이스
// Parameters : ifstream& fin -파일 입력을 위한 parameter
//                    string& productName, string& companyName, int& cost, int& quantityLeft - 상품명,회사명,가격,수량 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환
void AddProductUI::enterInformation(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft)
{
	fin >> productName >> companyName >> cost >> quantityLeft;
}

// Function : void AddProductUI::printNewProduct(ofstream& fout, Product* product)
// Description: 등록한 의류에 대한 정보 출력
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                    Product* product - 등록할 Product 객체
//                    
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void AddProductUI::printNewProduct(ofstream& fout, Product* product)
{
	string sellerID; //안 쓰지만 받아와야함
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	int score; //안 쓰지만 받아와야함

	product->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
	fout << "> " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " " << "\n";

}
// Function : void AddProduct::run(ifstream& fin, Client* actor, ProductCollection& totalProduct, ofstream& fout)
// Description: 판매의류 등록을 위한 controll class 
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                   ifstream& fin,  - 파일 입력을 위한 paramgter
//                    Client* actor, ProductCollection& totalProduct, - 등록하는 client 객체와 product가 등록될 productCollection 클래스
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void AddProduct::run(ifstream& fin, Client* actor, ProductCollection& totalProduct, ofstream& fout)
{
	//1.interface불러와서 정보 입력 받기
	//2. 상품 생성하기 
	//3. actor에 판매중인 상품 목록 추가
	//4. 전체 상품 리스트에 새 상품 추가.
	//5. fout으로 상품 정보 출력. 

	string productName, companyName;
	int cost, quantityLeft;

	AddProductUI* UI = new AddProductUI;
	UI->startInterface(fin, productName, companyName, cost, quantityLeft, fout);
	Product* newProduct = new Product(actor, productName, companyName, cost, quantityLeft);
	actor->addSoldProduct(newProduct);
	totalProduct.addProduct(newProduct);//전체 상품 리스트에 등록. 

	UI->printNewProduct(fout, newProduct);
}



//3.2. 등록 상품 조회 
//입력 : 3 2 
//출력 : > { [상품명] [제작회사명] [가격] [수량] } 

// Function : void ProductForSaleUI::startInterface(ofstream& fout)
// Description: 등록상품 조회 인터페이스
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void ProductForSaleUI::startInterface(ofstream& fout)
{
	fout << "3.2. 등록 상품 조회" << endl;
}


// Function : void ProductForSaleUI::showProductForSales(ProductCollection products, ofstream& fout)
// Description: 등록한 상품을 출력하는 함수
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                 ProductCollection products - 등록된 상품을 찾기 위한 productCollection
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

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
		if (products.getProduct(i)->getQuantityLeft() != 0) //재고가 0이 아니면
		{
			products.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
			fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << "\n";
		}
	}
}

// Function : void ProductForSale::run(Client* actor, ofstream& fout)
// Description: 상품 등록을 위한 controll class
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                  Client* actor, - 등록 상품 조회를 위한 client 객체
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void ProductForSale::run(Client* actor, ofstream& fout)
{
	ProductForSaleUI* UI = new ProductForSaleUI;
	UI->startInterface(fout);
	ProductCollection list = actor->getSoldProductList();
	UI->showProductForSales(list, fout);
}

//3.3. 판매 완료 상품 조회 
//입력 : 3 3
//출력 : > {[상품명] [제작회사명] [가격] [판매된 수량] [평균 구매만족도] }*

// Function : void ListSoldProductUI::startInterface(ofstream& fout)
// Description: 판매 완료 상품 조회 인터페이스
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                 
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void ListSoldProductUI::startInterface(ofstream& fout)
{
	fout << "3.3. 판매 완료 상품 조회" << endl;
}

// Function : void ListSoldProductUI::showSoldProductList(ProductCollection products, ofstream& fout)
// Description: 판매 완료 상품을 출력하는 함수
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                   ProductCollection products - 판매완료 상품을 찾기 위한 productcollection class
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void ListSoldProductUI::showSoldProductList(ProductCollection products, ofstream& fout)
{
	if (products.getSize() == 0)
	{
		cout << "판매 완료 상품 없음" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	int score;
	int quantitySold;

	products.sortList();//오름차순 출력

	for (int i = 0; i < products.getSize(); ++i)
	{
		if (products.getProduct(i)->getQuantityLeft() == 0) //재고가 0이면
		{
			products.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
			quantitySold = products.getProduct(i)->getQuantitySold();
			fout << "> " << productName << " " << companyName << " " << productCost << " " << quantitySold << " " << score << "\n";
		}
	}
}

// Function : void ListSoldProduct::run(Client* actor, ofstream& fout)
// Description: 판매 완료 상품 조회를 위한 controll class
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                   Client* actor - 판매자 객체
// Return Value : X
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void ListSoldProduct::run(Client* actor, ofstream& fout)
{
	ListSoldProductUI* UI = new ListSoldProductUI;
	UI->startInterface(fout);
	ProductCollection list = actor->getSoldProductList();
	UI->showSoldProductList(list, fout);
}


//4.1. 상품 정보 검색 구현
//입력 : 4 1 [상품명] 
//출력 : > [판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도]

// Function : void SearchUI::startInterface(ifstream& fin, ofstream& fout)
// Description: 상품정보 검색 인터페이스
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                  ifstream& fin - 파일 입력을 위한 parameter	
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void SearchUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "4.1. 상품 정보 검색" << endl;

	string productName;
	fin >> productName;
	this->productName = productName;
}

// Function : void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) 
// Description: 상품정보 검색 후 상품정보 출력
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                  Search* search, -선택한 객체 class
//          	ProductCollection products - Product를 모아놓은 class
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //상품 정보 검색 2.
{
	string sellerID;
	string name;
	string companyName;
	int productCost;
	int quantityLeft;
	int score;

	this->selected = search->searchProduct(this->productName, products);
	if (selected->getQuantityLeft() == 0) return; //재고가 없을시 검색되지않음.
	selected->getProductDetails(sellerID, name, companyName, productCost, quantityLeft, score);
	fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " " << score << "\n";
}


// Function : Product* SearchUI::selectPurchase()
// Description: 상품정보 검색 후 상품정보 출력
// Parameters :  x
//          	
// Return Value : 선택한 객체 
// Created: 2022/5/30 8:00 pm
// Author: 유민지

Product* SearchUI::selectPurchase()
{
	return selected;
}

// Function : Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout)
// Description: 상품정보 검색을 위한 controll class 
// Parameters :  ofstream& fout- 파일 출력을 위한 parameter
//                  ifstream& fin - 파일 입력을 위한 parameter
//                  ProductCollection products, Product*& selected // product collection 객체, 선택된 객체
// Return Value :  선택된 product 구매버튼 반환 
// Created: 2022/5/30 8:00 pm
// Author: 유민지

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout)
{

	searchUI = new SearchUI;
	searchUI->startInterface(fin, fout); //상품명 입력 받음
	searchUI->enterProductName(this, products, fout); //입력받은 상품 정보 출력 

	selected = searchUI->selectPurchase(); //구매 버튼 반환.
	if (selected->getQuantityLeft() == 0) return NULL;
	
	return selected;
}
// Function : Product* Search::searchProduct(string productName, ProductCollection products) 
// Description: 상품정보 검색을 위한 controll class 
// Parameters :  string productName, - 상품명
//		ProductCollection products - 상품을 모아놓은 class
// Return Value : 상품명에 해당하는 product 객체
// Created: 2022/5/30 8:00 pm
// Author: 유민지

Product* Search::searchProduct(string productName, ProductCollection products)
{
	Product* product = products.findProduct(productName);
	//product->getProductDetails(); 
	return product;
}


//4.2. 상품 구매 구현
//입력 : 4 2
//출력 : > [판매자ID] [상품명]

// Function : void PurchaseUI::startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase)
// Description: 상품정보 검색 인터페이스
// Parameters :  Product* product, Client* actor, ofstream& fout, Purchase* purchase
//                        구매할 상품  ,   구매할 회원 , 출력을 위한 parameter,  	구매버튼
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void PurchaseUI::startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase)
{
	fout << "4.2. 상품 구매\n";
	if (!product) return; //검색되지 않은 경우(재고 없는 경우) 판매 불가. 
	if (product->getQuantityLeft() == 0)return; //재고없는 경우 판매 불가. 
	this->purchase = purchase;
	purchaseProduct();
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //판매자 아이디와 상품명.
}

// Function : void PurchaseUI::purchaseProduct() 
// Description: 상품구매 후 재고수정하는 함수
// Parameters :  X
// Return Value : X
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void PurchaseUI::purchaseProduct()
{
	purchase->purchaseProduct();
}

// Function : Client* Purchase::run(Product* product, Client* actor, ofstream& fout)
// Description: 구매를 위한 controll class
// Parameters :  Product* product, Client* actor, - 구매할 상품, 구매할 회원
// 		ofstream& fout - 출력을 위한 parameter
// Return Value : 구매한 회원 객체
// Created: 2022/5/30 8:00 pm
// Author: 유민지

Client* Purchase::run(Product* product, Client* actor, ofstream& fout)
{
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(product, actor, fout, this); //4.1.

	return actor;
}
// Function : void Purchase::purchaseProduct()
// Description: 구매자에게 구매정보 추가 및 재고 수정
// Parameters :  x
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.구매자에게 구매 정보 추가
	product->stockCorrection(); //4.1.1.1.2.재고 수정
}

//4.3. 상품 구매 내역 조회
//입력 : 4 3
//출력 : >{ [판매자ID] [상품명] [제작회사명] [가격] [남은수량] [평균 구매만족도] } *

// Function : void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
// Description: 상품 구매내역 조회 인터페이스
// Parameters :  ProductCollection list, - 상품 리스트
//		ofstream& fout - 출력을 위한 parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
{
	fout << "4.3. 상품 구매 내역 조회" << endl;
	if (list.getSize() == 0)
	{
		cout << "구매 내역 없음" << endl;
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
// Description: 상품 구매내역 조회를 위한 controll class
// Parameters :   Client* actor, - 조회할 회원 객체
//		ofstream& fout - 출력을 위한 parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void ShowShopping::run(Client* actor, ofstream& fout)
{
	ProductCollection list;
	ShowShoppingListUI UI;
	list = actor->getPurchasedProductList(); //구매 내역 불러오기.

	UI.startInterface(list, fout); //구매내역 interface로 전달. 
}


//4.4. 상품 구매 만족도 평가
//입력 : 4 4 [상품명] [구매만족도]
//출력 : > [판매자ID] [상품명] [구매만족도] 

// Function : void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
// Description: 상품 구매만족도 평가 인터페이스
// Parameters :  string& productName, int& score, - 상품명과 만족도 점수
//		ofstream& fout - 출력을 위한 parameter
// 		ifstream& fin, - 입력을 위한 parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
{
	fout << "4.4. 상품 구매 만족도 평가\n";
	enterNameAndScore(fin, productName, score);
}

// Function : void SatisfactionScoreUI::printScore(string sellerID, string productName, int score, ofstream& fout)
// Description: 상품 구매만족도print 함수
// Parameters :  string sellerID, string productName, int score - 판매자 ID, 상품명, 구매만족도
//		ofstream& fout - 출력을 위한 parameter
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void SatisfactionScoreUI::printScore(string sellerID, string productName, int score, ofstream& fout)
{
	fout << "> " << sellerID << " " << productName << " " << score << "\n";
}

// Function : void SatisfactionScoreUI::enterNameAndScore(ifstream& fin, string& productName, int& score)
// Description: 상품명과 구매만족도 점수를 입력받는 함수. 
// Parameters :  ifstream& fin : 입력을 위한 parameter
//				 string& productName, int& score : 상품명, 점수
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: 유민지
void SatisfactionScoreUI::enterNameAndScore(ifstream& fin, string& productName, int& score) 
{
	fin >> productName >> score; //상품명과 구매 만족도 입력 받음
}
// Function : void SatisfactionScore::run(ifstream& fin, Client* actor, ofstream& fout)
// Description: 상품 구매만족도 평가를 위한 controll class 
// Parameters :  Client* actor - 회원 객체
//		ofstream& fout - 출력을 위한 parameter
//		ifstream& fin - 입력을 위한 parameter		
// Return Value : x
// Created: 2022/5/30 8:00 pm
// Author: 유민지

void SatisfactionScore::run(ifstream& fin, Client* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score, fout); //UI에서 제품명과 만족도 입력. 

	ProductCollection list;
	list = actor->getPurchasedProductList(); //구매 리스트 불러오기.
	Product* product;
	product = list.findProduct(productName); //제품명으로 제품 찾기.
	product->setScore(score); //평균 만족도 갱신

	UI->printScore(product->getSellerID(), productName, score, fout); //UI에서 판매자 ID, 제품명, 평균 만족도 출력.

}

//
//5.1. 판매 상품 통계
//입력 : 5 1
//출력 : >{ [상품명] [상품 판매 총액] [평귱 구매 만족도] }*

// Function : void ShowStatisticsUI::startInterface(ofstream& fout)
// Description: 판매상품 통계 인터페이스
// Parameters :  ofstream& fout - 출력을 위한 parameter
//
// Return Value : x
// Created: 2022/5/31 8:00 pm
// Author: 정지환

void ShowStatisticsUI::startInterface(ofstream& fout)
{
	fout << "5.1. 판매 상품 통계" << endl;
}

// Function : void ShowStatisticsUI::showStatistics(ProductCollection list, ofstream& fout)
// Description: 판매상품 통계를 출력하는 함수
// Parameters :  ofstream& fout - 출력을 위한 parameter
//		ProductCollection list- 상품 리스트
// Return Value : x
// Created: 2022/5/31 8:00 pm
// Author: 정지환

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
// Description: 판매상품 통계를 위한. controll class
// Parameters :  ofstream& fout - 출력을 위한 parameter
//		Client* actor -회원 객체
// Return Value : x
// Created: 2022/5/31 8:00 pm
// Author: 정지환
void ShowStatistic::run(Client* actor, ofstream& fout)
{
	ShowStatisticsUI* UI = new ShowStatisticsUI;
	UI->startInterface(fout);

	ProductCollection list = actor->getSoldProductList();
	UI->showStatistics(list, fout);

}