#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//���� ����
class Client;
class Product;
class ProductCollection;
class ClientCollection;

//Product Ŭ���� ����

// Class : product 
// Description: Product class
// Created : 2022/05/29 08:00 pm
// Author: ����ȯ,������

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

	Product(Client* actor, string productName, string companyName, int cost, int quantityLeft); //�Ǹ� ���� ���

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

//ProductCollection Ŭ���� ����

// Class : product collection 
// Description: Product collection class
// Created : 2022/05/29 08:00 pm
// Author: ����ȯ,������

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

//Client Ŭ���� ����

// Class : Client
// Description: client class
// Created : 2022/05/29 08:00 pm
// Author: ��â��, ������

class Client {
private:
	string clientName;
	string socialSecurityNumber;
	string clientID;
	string clientPassword;
	int log_status;
	ProductCollection purchasedProductList; //�����ڿ��� �߰�
	ProductCollection soldProductList; //�Ǹ� ����

public:
	string getClientPW();
	void createClient(string& name, string& SSN, string& ID, string& password); // client���� ����
	string getClientID();        // id�� ����
	bool getlog_status();       // �α��λ��� ��ȯ
	void set_log(int log_status); // �α��λ��¸� �ٲٴ� �Լ�
	void addPurchaseInformation(Product* product);
	ProductCollection getPurchasedProductList();
	void addSoldProduct(Product* product);
	ProductCollection getSoldProductList();
};

//Client collectionŬ���� ����

// Class : Client collection
// Description: client�� ��Ƴ��� class
// Created : 2022/05/29 08:00 pm
// Author: ��â��

class ClientCollection {
private:
	vector<Client*> clients;
public:
	int findClientIndex(string clientName); // �̸��� ���� ���̵� �ε��� ã��
	Client* login(string ID, string PW);  //�α��� �� ���̵��� �α��λ��°� ������ ���� ȣ��
	void addClient(Client* client);  // 1.1ȸ������
	void deleteClient(Client* client); // 1.2 ȸ��Ż��
	Client* loginID(); //�α��εǾ��ִ� ��ü ��ȯ

};