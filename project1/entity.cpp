#pragma once
#include <iostream>
#include <algorithm>
#include "entity.h"

//Client Ŭ���� ����Լ� ����

// Function : string Client::getClientID()
// Description: ȸ���� ID�� ��ȯ
// Parameters :  x
// Return Value : clientID
// Created: 2022/5/29 8:00 pm
// Author: ��â��

string Client::getClientID()
{
	return clientID;
}
string Client::getClientPW()
{
	return clientPassword;
}

// Function : bool Client::getlog_status()
// Description: ȸ���� �α��� ���°� ��ȯ (0�Ͻ� �α׾ƿ�����, 1�Ͻ� �α��� ����)
// Parameters :  x
// Return Value : log_status
// Created: 2022/5/29 8:00 pm
// Author: ��â��

bool Client::getlog_status()
{
	return log_status;
}

// Function : void Client::createClient(string& name, string& SSN, string& ID, string& password)
// Description: ȸ������ �Է��Ͽ� ����
// Parameters :  string& name, string& SSN, string& ID, string& password - �̸�,�ֹι�ȣ,ID,PW
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ��â��

void Client::createClient(string& name, string& SSN, string& ID, string& password)
{
	clientName = name;
	socialSecurityNumber = SSN;
	clientID = ID;
	clientPassword = password;

}

// Function : void Client::set_log(int log_status)
// Description: �α��� ���� �ٲٴ� �Լ�
// Parameters :  int log_status -> �α��� ����  (0�Ͻ� �α׾ƿ�,1�Ͻ� �α���)
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ��â��

void Client::set_log(int log_status) {
	this->log_status = log_status;
}


// Function : void Client::addPurchaseInformation(Product* product) 
// Description: ���� ��ǰ ����Ʈ �߰�
// Parameters : Product* product -> ��ǰ
// Return Value : x
// Created:2022/5/29 8:00 pm
// Author: ������

void Client::addPurchaseInformation(Product* product)
{
	purchasedProductList.addProduct(product);
}

// Function : ProductCollection Client::getPurchasedProductList()
// Description: ���� �� ��ǰ ����Ʈ ��ȯ
// Parameters : Product* product -> ��ǰ
// Return Value : purchasedProductList
// Created: 2022/5/29 8:00 pm
// Author: ������

ProductCollection Client::getPurchasedProductList()
{
	return purchasedProductList;
}


//Client Ŭ���� �Ǹ� ��� ����

// Function : void Client::addSoldProduct(Product* product)
// Description: �ǸŵȻ�ǰ �ǸſϷ��ǰ ����Ʈ�� �߰�
// Parameters : Product* product -> ��ǰ
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ

void Client::addSoldProduct(Product* product)
{
	soldProductList.addProduct(product);
}


// Function : ProductCollection Client::getSoldProductList()
// Description:  �ǸſϷ��ǰ ����Ʈ�� ��ȯ
// Parameters : x
// Return Value : soldProductList -> �ǸſϷ� ��ǰ
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ

ProductCollection Client::getSoldProductList()
{
	return soldProductList;
}




//ClientCollection class ����

// Function : void ClientCollection::addClient(Client* client) 
// Description: ȸ������ 
// Parameters : Client* client -> ȸ�������� ��ü
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ��â��

void ClientCollection::addClient(Client* client)
{
	clients.push_back(client);
}


// Function : void ClientCollection::deleteClient(Client* client)
// Description: ȸ��Ż�� 
// Parameters : Client* client -> ȸ��Ż�� �� ��ü
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ��â��

void ClientCollection::deleteClient(Client* client) //  ȸ��Ż��

{
	string clientID = client->getClientID();
	int index = findClientIndex(clientID); // ��ü ������ ���� �ε����� ã�� ����

	clients.erase(clients.begin() + index);  //�α��� ���� ���̵��� index�� ã�Ƽ� �÷��� Ŭ���� ������ ����

}

// Function : int ClientCollection::findClientIndex(string ID) 
// Description:  ID�� ��ġ�ϴ� �ε��� ��ȯ
// Parameters :string ID -> ȸ�� ID
// Return Value : i  - �ε�����
// Created: 2022/5/29 8:00 pm
// Author: ��â��

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
// Description:  �α��� �� �� ��ü ��ȯ
// Parameters : string ID, string PW - ȸ�� ID,PW
// Return Value : clients[i]  -�α��� �� �� ��ü
// Created: 2022/5/29 8:00 pm
// Author: ��â��

Client* ClientCollection::login(string ID, string PW)
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if ((clients[i]->getClientID() == ID) && (clients[i]->getClientPW() == PW))
		{
			break;//�α������� �ε������� break
		}

	}
	return clients[i];
}

// Function : Client* ClientCollection::LoginID()
// Description:  �α��� ���� �� ��ü ã�Ƽ� ��ȯ
// Parameters : x
// Return Value : clients[i]  -�α������� �� ��ü
// Created: 2022/5/29 8:00 pm
// Author: ��â��

Client* ClientCollection::loginID()
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getlog_status() == 1)
		{
			break;//�α������� �ε������� break
		}

	}
	return clients[i];
}


//Product Ŭ���� ����Լ� ����

// Function : Product::Product(Client* actor, string productName, string companyName, int cost, int quantityLeft)
// Description:  ��ǰ ���� �Է�
// Parameters : Client* actor, string productName, string companyName, int cost, int quantityLeft
// 		ȸ��, ��ǰ��, ȸ���, ����, ����
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ,������

Product::Product(Client* actor, string productName, string companyName, int cost, int quantityLeft)
{
	this->seller = actor;

	this->sellerID = actor->getClientID();
	this->productName = productName;
	this->productCompanyName = companyName;
	this->cost = cost;
	this->quantityLeft = quantityLeft;

	this->quantitysold = 0;
	this->averageScore = 0; //������
}

// Function : string Product::getProductName()
// Description:  ��ǰ�� ��ȯ
// Parameters : x
// Return Value : productName - ��ǰ��
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ,������

string Product::getProductName()
{
	return productName;
}

// Function : void Product::getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, float& score)
// Description:  ��ǰ ���� ����
// Parameters : string& ID, string& name, string& companyName, int& productCost, int& left, float& score - 
//		ID, �̸�, ȸ���, ����, ����, ���Ÿ�����
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ,������

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
// Description:   ��� �� �Ǹŷ� ����
// Parameters : x
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ������

void Product::stockCorrection()
{
	quantityLeft--; //��� - 1
	quantitysold++; //�Ǹż��� + 1
}

// Function :void Product::setScore(int score)
// Description:   ��� ���Ÿ����� ���.
// Parameters : int score -���Ÿ�����
// Return Value : x
// Created: 2022/5/29 8:00 pm
// Author: ������

void Product::setScore(int score)
{
	int totalScore = (averageScore * (quantitysold - 1)) + score;
	averageScore = int(round(totalScore / quantitysold));
}

// Function : string Product::getName(),string Product::getSellerID(),int Product::getQuantityLeft(),int Product::getQuantitySold(),int Product::calculateProfit(),int Product::getScore()
// Description:   �̸�,ID,��������,�Ǹż���, profit, ��� ���Ÿ����� ��ȯ
// Parameters :x 
// Return Value : productName ,sellerID,quantityLeft,quantitysold,(quantitysold * cost),averageScore
//		�̸�,ID,��������,�Ǹż���, profit, ��� ���Ÿ����� 
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ,������

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
// Description:   ��ǰ ���� �˻��� �̿�
// Parameters : string productName - �˻��� ��ǰ��
// Return Value :products[i] - �˻��� ��ǰ ��ü 
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ,������

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
// Description:   ���� ���� �߰��� �̿�
// Parameters : Product* product - ���� ��ǰ
// Return Value: x
// Created: 2022/5/29 8:00 pm
// Author: ������

void ProductCollection::addProduct(Product* product)
{
	products.push_back(product);
}


// Function : int ProductCollection::getSize() 
// Description:   ��ǰ ���� ����
// Parameters : x 
// Return Value:  products.size() - ��ǰ����
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ,������

int ProductCollection::getSize()
{
	return (int)products.size();
}

// Function : Product* ProductCollection::getProduct(int i) 
// Description:   ����Ʈ ��ȸ�� �Լ�
// Parameters : i - �ε���
// Return Value:  products[i]- �ε����� ��ġ�ϴ� ��ǰ ��ü
// Created: 2022/5/29 8:00 pm
// Author: ����ȯ,������

Product* ProductCollection::getProduct(int i) //����Ʈ ��ȸ��
{
	return products[i];
}

// Function : bool compare(Product* a, Product* b)
// Description:   ��ü �̸� ��
// Parameters : Product* a, Product* b - ��ǰa, ��ǰb
// Return Value:  bool��
// Created: 2022/5/29 8:00 pm
// Author: ������

bool compare(Product* a, Product* b)
{
	return a->getName() < b->getName();
}


// Function : void ProductCollection::sortList() 
// Description: ��ǰ ����Ʈ�� ��ǰ�� ������������ ����.
// Parameters : x
// Return Value:  x
// Created: 2022/5/29 8:00 pm
// Author: ������

void ProductCollection::sortList()
{
	sort(products.begin(), products.end(), compare);
}