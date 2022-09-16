#pragma once
#include <iostream>
#include <algorithm>
#include "entity.h"

//Client 클래스 멤버함수 구현

// Function : string Client::getClientID()
// Description: 회원의 ID값 반환
// Parameters :  x
// Return Value : clientID
// Created: 2022/5/29 8:00 pm
// Author: 유창조

string Client::getClientID()
{
	return clientID;
}
string Client::getClientPW()
{
	return clientPassword;
}

// Function : bool Client::getlog_status()
// Description: 회원의 로그인 상태값 반환 (0일시 로그아웃상태, 1일시 로그인 상태)
// Parameters :  x
// Return Value : log_status
// Created: 2022/5/29 8:00 pm
// Author: 유창조

bool Client::getlog_status()
{
	return log_status;
}

// Function : void Client::createClient(string& name, string& SSN, string& ID, string& password)
// Description: 회원정보 입력하여 수정
// Parameters :  string& name, string& SSN, string& ID, string& password - 이름,주민번호,ID,PW
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 유창조

void Client::createClient(string& name, string& SSN, string& ID, string& password)
{
	clientName = name;
	socialSecurityNumber = SSN;
	clientID = ID;
	clientPassword = password;

}

// Function : void Client::set_log(int log_status)
// Description: 로그인 상태 바꾸는 함수
// Parameters :  int log_status -> 로그인 상태  (0일시 로그아웃,1일시 로그인)
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 유창조

void Client::set_log(int log_status) {
	this->log_status = log_status;
}


// Function : void Client::addPurchaseInformation(Product* product) 
// Description: 구매 상품 리스트 추가
// Parameters : Product* product -> 상품
// Return Value : x
// Created:2022/5/29 8:00 pm
// Author: 유민지

void Client::addPurchaseInformation(Product* product)
{
	purchasedProductList.addProduct(product);
}

// Function : ProductCollection Client::getPurchasedProductList()
// Description: 구매 된 상품 리스트 반환
// Parameters : Product* product -> 상품
// Return Value : purchasedProductList
// Created: 2022/5/29 8:00 pm
// Author: 유민지

ProductCollection Client::getPurchasedProductList()
{
	return purchasedProductList;
}


//Client 클래스 판매 기능 구현

// Function : void Client::addSoldProduct(Product* product)
// Description: 판매된상품 판매완료상품 리스트에 추가
// Parameters : Product* product -> 상품
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 정지환

void Client::addSoldProduct(Product* product)
{
	soldProductList.addProduct(product);
}


// Function : ProductCollection Client::getSoldProductList()
// Description:  판매완료상품 리스트에 반환
// Parameters : x
// Return Value : soldProductList -> 판매완료 상품
// Created: 2022/5/29 8:00 pm
// Author: 정지환

ProductCollection Client::getSoldProductList()
{
	return soldProductList;
}




//ClientCollection class 구현

// Function : void ClientCollection::addClient(Client* client) 
// Description: 회원가입 
// Parameters : Client* client -> 회원가입할 객체
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 유창조

void ClientCollection::addClient(Client* client)
{
	clients.push_back(client);
}


// Function : void ClientCollection::deleteClient(Client* client)
// Description: 회원탈퇴 
// Parameters : Client* client -> 회원탈퇴 할 객체
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 유창조

void ClientCollection::deleteClient(Client* client) //  회원탈퇴

{
	string clientID = client->getClientID();
	int index = findClientIndex(clientID); // 객체 삭제를 위해 인덱스를 찾는 과정

	clients.erase(clients.begin() + index);  //로그인 중인 아이디의 index를 찾아서 컬랙션 클래스 내에서 삭제

}

// Function : int ClientCollection::findClientIndex(string ID) 
// Description:  ID에 일치하는 인덱스 반환
// Parameters :string ID -> 회원 ID
// Return Value : i  - 인덱스값
// Created: 2022/5/29 8:00 pm
// Author: 유창조

int ClientCollection::findClientIndex(string ID)
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getClientID() == ID)
		{
			break;
		}

	}
	return i;

}

// Function : Client* ClientCollection::Login(string ID, string PW)
// Description:  로그인 할 고객 객체 반환
// Parameters : string ID, string PW - 회원 ID,PW
// Return Value : clients[i]  -로그인 할 고객 객체
// Created: 2022/5/29 8:00 pm
// Author: 유창조

Client* ClientCollection::login(string ID, string PW)
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if ((clients[i]->getClientID() == ID) && (clients[i]->getClientPW() == PW))
		{
			break;//로그인중인 인덱스에서 break
		}

	}
	return clients[i];
}

// Function : Client* ClientCollection::LoginID()
// Description:  로그인 중인 고객 객체 찾아서 반환
// Parameters : x
// Return Value : clients[i]  -로그인중인 고객 객체
// Created: 2022/5/29 8:00 pm
// Author: 유창조

Client* ClientCollection::loginID()
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getlog_status() == 1)
		{
			break;//로그인중인 인덱스에서 break
		}

	}
	return clients[i];
}


//Product 클래스 멤버함수 구현

// Function : Product::Product(Client* actor, string productName, string companyName, int cost, int quantityLeft)
// Description:  상품 정보 입력
// Parameters : Client* actor, string productName, string companyName, int cost, int quantityLeft
// 		회원, 상품명, 회사명, 가격, 수량
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 정지환,유민지

Product::Product(Client* actor, string productName, string companyName, int cost, int quantityLeft)
{
	this->seller = actor;

	this->sellerID = actor->getClientID();
	this->productName = productName;
	this->productCompanyName = companyName;
	this->cost = cost;
	this->quantityLeft = quantityLeft;

	this->quantitysold = 0;
	this->averageScore = 0; //정수형
}

// Function : string Product::getProductName()
// Description:  상품명 반환
// Parameters : x
// Return Value : productName - 상품명
// Created: 2022/5/29 8:00 pm
// Author: 정지환,유민지

string Product::getProductName()
{
	return productName;
}

// Function : void Product::getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, float& score)
// Description:  상품 정보 수정
// Parameters : string& ID, string& name, string& companyName, int& productCost, int& left, float& score - 
//		ID, 이름, 회사명, 가격, 수량, 구매만족도
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 정지환,유민지

void Product::getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, int& score)
{
	ID = sellerID;
	name = productName;
	companyName = productCompanyName;
	productCost = this->cost;
	left = this->quantityLeft;
	score = this->averageScore;
}


// Function : void Product::stockCorrection()
// Description:   재고 및 판매량 수정
// Parameters : x
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 유민지

void Product::stockCorrection()
{
	quantityLeft--; //재고 - 1
	quantitysold++; //판매수량 + 1
}

// Function :void Product::setScore(int score)
// Description:   평균 구매만족도 계산.
// Parameters : int score -구매만족도
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: 유민지

void Product::setScore(int score)
{
	int totalScore = (averageScore * (quantitysold - 1)) + score;
	averageScore = int(round(totalScore / quantitysold));
}

// Function : string Product::getName(),string Product::getSellerID(),int Product::getQuantityLeft(),int Product::getQuantitySold(),int Product::calculateProfit(),int Product::getScore()
// Description:   이름,ID,남은수량,판매수량, profit, 평균 구매만족도 반환
// Parameters :x 
// Return Value : productName ,sellerID,quantityLeft,quantitysold,(quantitysold * cost),averageScore
//		이름,ID,남은수량,판매수량, profit, 평균 구매만족도 
// Created: 2022/5/29 8:00 pm
// Author: 정지환,유민지

string Product::getName()
{
	return this->productName;
}
string Product::getSellerID()
{
	return this->sellerID;
}
int Product::getQuantityLeft()
{
	return quantityLeft;
}
int Product::getQuantitySold()
{
	return quantitysold;
}
int Product::calculateProfit()
{
	return (quantitysold * cost);
}
int Product::getScore()
{
	return averageScore;
}

// Function :Product* ProductCollection::findProduct(string productName)
// Description:   상품 정보 검색에 이용
// Parameters : string productName - 검색할 상품명
// Return Value :products[i] - 검색한 상품 객체 
// Created: 2022/5/29 8:00 pm
// Author: 정지환,유민지

Product* ProductCollection::findProduct(string productName)
{
	int i = 0;
	for (i = 0; i < products.size(); ++i)
	{
		if (products[i]->getName() == productName)
		{
			break;
		}

	}
	return products[i];
}

// Function : void ProductCollection::addProduct(Product* product) 
// Description:   구매 정보 추가에 이용
// Parameters : Product* product - 구매 상품
// Return Value: x
// Created: 2022/5/29 8:00 pm
// Author: 유민지

void ProductCollection::addProduct(Product* product)
{
	products.push_back(product);
}


// Function : int ProductCollection::getSize() 
// Description:   상품 개수 리턴
// Parameters : x 
// Return Value:  products.size() - 상품개수
// Created: 2022/5/29 8:00 pm
// Author: 정지환,유민지

int ProductCollection::getSize()
{
	return (int)products.size();
}

// Function : Product* ProductCollection::getProduct(int i) 
// Description:   리스트 순회용 함수
// Parameters : i - 인덱스
// Return Value:  products[i]- 인덱스에 일치하는 상품 객체
// Created: 2022/5/29 8:00 pm
// Author: 정지환,유민지

Product* ProductCollection::getProduct(int i) //리스트 순회용
{
	return products[i];
}

// Function : bool compare(Product* a, Product* b)
// Description:   객체 이름 비교
// Parameters : Product* a, Product* b - 상품a, 상품b
// Return Value:  bool값
// Created: 2022/5/29 8:00 pm
// Author: 유민지

bool compare(Product* a, Product* b)
{
	return a->getName() < b->getName();
}


// Function : void ProductCollection::sortList() 
// Description: 상품 리스트를 상품명 오름차순으로 정렬.
// Parameters : x
// Return Value:  x
// Created: 2022/5/29 8:00 pm
// Author: 유민지

void ProductCollection::sortList()
{
	sort(products.begin(), products.end(), compare);
}