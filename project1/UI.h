#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "entity.h"
using namespace std;

//전방 선언
class CreateClientAccountUI;
class CreateClientAccount;
class DeleteClientAccountUI;
class DeleteClientAccount;
class LoginUI;
class Login;
class LogoutUI;
class Logout;

class SearchUI;
class ShowShoppingListUI;
class SatisfactionScoreUI;
class PurchaseUI;
class Search;
class ShowShopping;
class SatisfactionScore;
class Purchase;

class AddProductUI;
class AddProduct;
class ProductForSaleUI;
class ProductForSale;
class ListSoldProductUI;
class ListSoldProduct;
class ShowStatisticsUI;
class ShowStatistic;

// 1.1 회원가입 UI
class CreateClientAccountUI {

public:
	void interface(ofstream& fout);
	Client* enterClientInformation(ifstream& fin, ofstream& fout);

};
class CreateClientAccount {
	CreateClientAccountUI* CCA_UI;
public:
	void addNewClient(ifstream& fin, ClientCollection& clients, ofstream& fout);
};

//1.2 회원탈퇴
class DeleteClientAccountUI {

public:
	void interface(ofstream& fout);
	void deleteClientAccount(ClientCollection& client, ofstream& fout);

};

//ui에서의 정보를 통해 client정보 수정
class DeleteClientAccount {
	DeleteClientAccountUI* DCA_UI;
public:
	void deleteClient(ifstream& fin, ClientCollection& clients, ofstream& fout);
};
//////


//2.1 로그인 (다이어그램을 1.getclient가 아닌 가장 마지막에 client한테 전달하도록 수정요망)
class LoginUI {
public:
	void interface(ofstream& fout);
	string* selectLogin(ifstream& fin, ofstream& fout);
};

class Login {
	LoginUI* Login_UI;
public:
	void tryLogin(ifstream& fin, ClientCollection& clients, ofstream& fout);

};

//2.2로그아웃 (로그인상태 판별후 로그인 상태일시 로그아웃) 

class LogoutUI {
public:
	void interface(ofstream& fout);
	void selectLogout(ClientCollection& clients, ofstream& fout);
};

class Logout {
	LogoutUI* Logout_UI;
public:
	void tryLogout(ClientCollection& clients, ofstream& fout);

};

/*3.1. 판매 의류 등록*/
/*Boundary*/
class AddProductUI {
public:
	void startInterface(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft, ofstream& fout);
	void printNewProduct(ofstream& fout, Product* product);
	void enterInformation(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft); //추가한 부분
	//void enterProductInformation(); 
};
/*control*/
class AddProduct {
public:
	void run(ifstream& fin, Client* actor, ProductCollection& totalProduct, ofstream& fout);

	//void addNewProduct(string productName, string companyName, int cost, int quantityLeft);
};


/*3.2. 판매중인 의류 조회*/
/*Boundary*/
class ProductForSaleUI {
public:
	void startInterface(ofstream& fout);
	void showProductForSales(ProductCollection products, ofstream& fout);
};
/*control*/
class ProductForSale {
public:
	//void showProductForSales();

	void run(Client* actor, ofstream& fout);//내가 추가
};

/* 3.3. 판매 완료된 상품 내역 조회*/
/*Boundary*/
class ListSoldProductUI {
public:
	void startInterface(ofstream& fout);
	void showSoldProductList(ProductCollection products, ofstream& fout);
};
/*control*/
class ListSoldProduct {
public:
	//void showSoldProductList();
	void run(Client* actor, ofstream& fout);
};

/*4.1. 상품 정보 검색*/
/*Boundary*/
class SearchUI {
	string productName;
	Product* selected; //추가한 부분
public:
	void startInterface(ifstream& fin, ofstream& fout);
	void enterProductName(Search* search, ProductCollection products, ofstream& fout); //searchProductName으로 바꾸는 게 나을수도..
	Product* selectPurchase();
};
/*control*/
class Search {
	SearchUI* searchUI;
public:
	Product* run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout);
	Product* searchProduct(string productName, ProductCollection products);
};

/*4.2. 상품 구매*/
/*Boundary*/
class PurchaseUI {
	Purchase* purchase;
public:
	void startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase);
	void purchaseProduct();
};
/*control*/
class Purchase {
	Product* product;
	PurchaseUI* purchaseUI;
	Client* actor;
public:
	Client* run(Product* product, Client* actor, ofstream& fout);
	void purchaseProduct();
};

/*4.3. 상품 구매 내역 조회*/
/*Boundary*/
class ShowShoppingListUI {
public:
	void startInterface(ProductCollection list, ofstream& fout);
	//void selectProductSatisfaction();
};
/*control*/
class ShowShopping {
public:
	void run(Client* actor, ofstream& fout);
};

/*4.4. 상품 구매 만족도 평가*/
/*Boundary*/
class SatisfactionScoreUI {
public:
	void startInterface(ifstream& fin, string& productName, int& score, ofstream& fout);
	void enterNameAndScore(ifstream& fin, string& productName, int& score); //추가된 부분 
	void printScore(string sellerID, string productName, int score, ofstream& fout);
};
/*control*/
class SatisfactionScore {
public:

	void run(ifstream& fin, Client* actor, ofstream& fout);
};

/*5.1. 판매 완료된 상품 내역 조회*/
/*Boundary*/
class ShowStatisticsUI
{
public:
	void startInterface(ofstream& fout);
	void showStatistics(ProductCollection list, ofstream& fout);
};
/*control*/
class ShowStatistic {
public:
	//void showTotalSalesAndAverage();
	void run(Client* actor, ofstream& fout);
};

