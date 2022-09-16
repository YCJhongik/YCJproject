#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//전방 선언
class Client;
class Product;
class ProductCollection;
class ClientCollection;

//Product 클래스 선언

// Class : product 
// Description: Product class
// Created : 2022/05/29 08:00 pm
// Author: 정지환,유민지

class Product {
private:
	string sellerID;
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	int averageScore;

	Client* seller;


public:

	Product(Client* actor, string productName, string companyName, int cost, int quantityLeft); //판매 물건 등록

	void getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, int& score);
	string getProductName();
	string getName();
	string getSellerID();
	void setScore(int score);
	void stockCorrection();

	int getQuantityLeft();
	int getQuantitySold();
	int getScore();
	int calculateProfit();

};

//ProductCollection 클래스 선언

// Class : product collection 
// Description: Product collection class
// Created : 2022/05/29 08:00 pm
// Author: 정지환,유민지

class ProductCollection {
private:
	vector<Product*> products;
public:
	Product* findProduct(string productName);
	void addProduct(Product* product);
	int getSize();
	Product* getProduct(int i);

	void sortList();
};

//Client 클래스 선언

// Class : Client
// Description: client class
// Created : 2022/05/29 08:00 pm
// Author: 유창조, 유민지

class Client {
private:
	string clientName;
	string socialSecurityNumber;
	string clientID;
	string clientPassword;
	int log_status;
	ProductCollection purchasedProductList; //구매자에서 추가
	ProductCollection soldProductList; //판매 물건

public:
	string getClientPW();
	void createClient(string& name, string& SSN, string& ID, string& password); // client정보 수정
	string getClientID();        // id값 접근
	bool getlog_status();       // 로그인상태 반환
	void set_log(int log_status); // 로그인상태를 바꾸는 함수
	void addPurchaseInformation(Product* product);
	ProductCollection getPurchasedProductList();
	void addSoldProduct(Product* product);
	ProductCollection getSoldProductList();
};

//Client collection클래스 선언

// Class : Client collection
// Description: client를 모아놓은 class
// Created : 2022/05/29 08:00 pm
// Author: 유창조

class ClientCollection {
private:
	vector<Client*> clients;
public:
	int findClientIndex(string clientName); // 이름을 통해 아이디 인덱스 찾기
	Client* login(string ID, string PW);  //로그인 할 아이디의 로그인상태값 변경을 위해 호출
	void addClient(Client* client);  // 1.1회원가입
	void deleteClient(Client* client); // 1.2 회원탈퇴
	Client* loginID(); //로그인되어있는 객체 반환

};