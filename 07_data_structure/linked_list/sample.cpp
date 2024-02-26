#include<bits/stdc++.h>

using namespace std;

int main()
{

	int input;
	char character,choice,receipt;
	int order,quantity;
	float payment,balance;
	time_t now = time(0);
	char* dt=ctime(&now);
	const float setA=2.21;
	const float setB=2.33;
	const float setC=3.17;
	const float setD=1.87;
	const float combo1= 5.05;
	const float combo2= 3;
	const float combo3= 2.5;
	const float combo4= 9.55;
	const float combo5= 8;
	const float combo6= 4.5;
	const float combo7= 11.06;
	const float combo8= 9.98;


	system("cls");

	cout<<"\n\t\t\t NHOM 23: \n";
			cout<<endl;
			cout<<"\t\t\t -Tran Hoang Chuong \t\t\t chuongth2 \n";
			cout<<"\t\t\t -Tran Ngoc Tuong Van \t\t\t vantnt2 \n";
			cout<<"\t\t\t -Ngo Trong Nghia \t\t\t nghiant48 \n";
            cout<<endl;
			cout<<endl;
			cout<<endl;
            cout<<"\t\t\t  HE THONG DAT HANG CUA HANG LOTTERIA \n";

	cout << "\n\n\n\t\t\t ----------LOTTERIA Ordering System-----------"<<endl;
	cout << "\t\t\t|                                             |"<<endl;
	cout << "\t\t\t|  Press Y to continue or press N to exit     |"<<endl;
	cout << "\t\t\t|                                             |"<<endl;
	cout << "\t\t\t|                 INTERNSHIP                  |"<<endl;
	cout << "\t\t\t ---------------------------------------------"<<endl;

	input:
	cout << "\n\t\t\tEnter Input [Y/N] : ";
	cin >> character;

	switch(character){
		case 'Y' :
		case 'y' :
			goto menu;
			break;
		case 'N' :
		case 'n' :
			system("PAUSE");
			cout<<"\n\t\t\t MEMBERS: \n";
			cout<<endl;
			cout<<"\t\t\t -Tran Hoang Chuong \t\t\t chuongth2 \n";
			cout<<"\t\t\t -Tran Ngoc Tuong Van \t\t\t vantnt2 \n";
			cout<<"\t\t\t -Ngo Trong Nghia \t\t\t nghiant48 \n";
			cout<<endl;
			cout<<endl;
			cout<<endl;
			exit(EXIT_SUCCESS);
			break;
		default :
			cout << "\n\t\t\tYou enter wrong input"<<endl;
			goto input;
			break;

	}

			menu:
			system("cls");
            cout << "\n\t\t\t -----------------------------------------------------------"<<endl;
			cout << "\t\t\t|                        LOTTERIA - Menu                    |"<<endl;
			cout << "\t\t\t -----------------------------------------------------------"<<endl;
			cout << "\n\t\t\t ------------Set A------------\t ------------Set B---------------"<<endl;
			cout << "\t\t\t| Food  : Fried Chicken       |\t| Food  : Beef sauce spaghetti   |"<<endl;
			cout << "\t\t\t| Drink : Pepsi               |\t| Drink : Mirinda                |"<<endl;
			cout << "\t\t\t| Price : $2,21               |\t| Price : $2.33                  |"<<endl;
			cout << "\t\t\t -----------------------------\t --------------------------------"<<endl;

			cout << "\n\t\t\t ------------Set C------------\t ------------Set D---------------"<<endl;
			cout << "\t\t\t| Food  : Hamburger big size  |\t| Food  : Potato chips           |"<<endl;
			cout << "\t\t\t| Drink : Sprite              |\t| Drink : 7up                    |"<<endl;
			cout << "\t\t\t| Price : $3.17               |\t| Price : $1.87                  |"<<endl;
			cout << "\t\t\t -----------------------------\t --------------------------------"<<endl;

			cout << "\n\t\t\t ----------Combo 1-----------\t ------------Combo 2--------------"<<endl;
			cout << "\t\t\t| Food  : 2pcs Fried Chicken  |\t| Food  : Beef sauce spaghetti   |"<<endl;
			cout << "\t\t\t|          + Potato chips     |\t|        + Hamburger small size  |"<<endl;
			cout << "\t\t\t| Drink : 2 Pepsi             |\t| Drink : Mirinda                |"<<endl;
			cout << "\t\t\t| Price : $5.05 (10%off)      |\t| Price : $3 (12% off)           |"<<endl;
			cout << "\t\t\t -----------------------------\t --------------------------------"<<endl;

			cout << "\n\t\t\t ----------Combo 3-----------\t ------------Combo 4------------"<<endl;
			cout << "\t\t\t| Food  : Cheese sauce fried  |\t| Food  : 5pcs Fried Chicken     |"<<endl;
			cout << "\t\t\t|         chicken + rice      |\t|                                |"<<endl;
			cout << "\t\t\t| Drink : Orange juice        |\t| Drink : 3 random drinks        |"<<endl;
			cout << "\t\t\t| Price : $2.5 (10% off)      |\t| Price : $9.55 (best seller)    |"<<endl;
			cout << "\t\t\t -----------------------------\t --------------------------------"<<endl;

			cout << "\n\t\t\t ----------Combo 5-----------\t ------------Combo 6--------------"<<endl;
			cout << "\t\t\t| Food  : 3pcs Fried Chicken  |\t| Food  : Spicy sauce Chicken    |"<<endl;
			cout << "\t\t\t|          + 2 Potato chips   |\t|       + Hamburger medium size  |"<<endl;
			cout << "\t\t\t| Drink : 2 Pepsi             |\t| Drink : Tornado cashew         |"<<endl;
			cout << "\t\t\t| Price : $8                  |\t| Price : $4.5 (Recommended)     |"<<endl;
			cout << "\t\t\t -----------------------------\t --------------------------------"<<endl;

			cout << "\n\t\t\t ----------Combo 7-----------\t ------------Combo 8--------------"<<endl;
			cout << "\t\t\t| Food  : 7pcs random sauce   |\t| Food  : 3 Beef sauce spaghettis|"<<endl;
			cout << "\t\t\t|         chicken + rice      |\t|       + 3 Hamburgers big size  |"<<endl;
			cout << "\t\t\t| Drink : 3 Free to choose    |\t| Drink : 3 random drinks        |"<<endl;
			cout << "\t\t\t| Price : $11.06 (best seller)|\t| Price : $9.98 (30% off)        |"<<endl;
			cout << "\t\t\t -----------------------------\t --------------------------------"<<endl;

			choose:
			cout << "\n\t\t\tChoose Set/Combo : ";
			cin >> choice;


			switch(choice){
				case 'A' :
				case 'a' :
					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\tYou pick Set : A"<<endl;
					cout << "\n\t\t\t ------------Set A------------"<<endl;
                    cout << "\t\t\t| Food  : Fried Chicken       |"<<endl;
                    cout << "\t\t\t| Drink : Pepsi               |"<<endl;
                    cout << "\t\t\t| Price : $2.21               |"<<endl;
                    cout << "\t\t\t -----------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\t\t\tQuantity  : "<<quantity<<endl;
					cout << "\n\t\t\tYour total cost is $ "<<(setA*quantity)<<endl;
					do{
						cout << "\n\t\t\tPlease make your payment : $ ";
						cin  >> payment;

					if(payment>=(setA*quantity)){

						balance=payment-(setA*quantity);
						cout << fixed<<showpoint<<setprecision(2);
						cout << "\n\t\t\tYour balance is : $ " << balance;
					}

					else{

						cout<< "\n\t\t\tPayment not enough";
						}
					}while(payment< (setA*quantity));
					a:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set A "<<"   	    "<<quantity<<" 	   "<<setA<<"      "<<setA*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<setA*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto a;
					}

					break;
				case 'B' :
				case 'b' :
					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\tYou pick Set : B"<<endl;
                    cout << "\n\t\t\t ------------Set B---------------"<<endl;
                    cout << "\t\t\t| Food  : Beef sauce spaghetti   |"<<endl;
                    cout << "\t\t\t| Drink : Mirinda                |"<<endl;
                    cout << "\t\t\t| Price : $2.33                  |"<<endl;
                    cout << "\t\t\t --------------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\t\t\tQuantity  : "<<quantity<<endl;
					cout << "\n\t\t\tYour total cost is $ "<<(setB*quantity)<<endl;
					do{
					cout << "\n\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(setB*quantity)){

					balance=payment-(setB*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(setB*quantity));
					b:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set B "<<"   	    "<<quantity<<" 	   "<<setB<<"      "<<setB*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<setB*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto b;
					}
					break;
				case 'C' :
				case 'c' :
				    cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ------------Set C------------"<<endl;
                    cout << "\t\t\t| Food  : Hamburger big size  |"<<endl;
                    cout << "\t\t\t| Drink : Sprite              |"<<endl;
                    cout << "\t\t\t| Price : $3.17               |"<<endl;
                    cout << "\t\t\t -----------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\t\t\tQuantity  : "<<quantity<<endl;
					cout << "\n\t\t\tYour total cost is $ "<<(setC*quantity)<<endl;
					do{
					cout << "\n\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(setC*quantity)){

					balance=payment-(setC*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(setC*quantity));
					c:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel  : 028-3722-8555     Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software            Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set C "<<"   	    "<<quantity<<" 	   "<<setC<<"      "<<setC*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<setC*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto c;
					}
					break;
				case 'D' :
				case 'd' :
					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ------------Set D---------------"<<endl;
                    cout << "\t\t\t| Food  : Potato chips           |"<<endl;
                    cout << "\t\t\t| Drink : 7up                    |"<<endl;
                    cout << "\t\t\t| Price : $1.87                  |"<<endl;
                    cout << "\t\t\t --------------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(setD*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(setD*quantity)){ //fn1353

					balance=payment-(setD*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(setD*quantity));
					d:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<setD<<"      "<<setD*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<setD*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto d;
					}
					break;






					case '1' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ----------Combo 1------------"<<endl;
                    cout << "\t\t\t| Food  : 2pcs Fried Chicken  |"<<endl;
                    cout << "\t\t\t|          + Potato chips     |"<<endl;
                    cout << "\t\t\t| Drink : 2 Pepsi             |"<<endl;
                    cout << "\t\t\t| Price : $5.05 (10%off)      |"<<endl;
                    cout << "\t\t\t -----------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo1*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo1*quantity)){ //fn1353

					balance=payment-(combo1*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo1*quantity));
					e:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo1<<"      "<<combo1*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo1*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto e;
					}
					break;




					case '2' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ------------Combo 2-------------"<<endl;
                    cout << "\t\t\t| Food  : Beef sauce spaghetti   |"<<endl;
                    cout << "\t\t\t|        + Hamburger small size  |"<<endl;
                    cout << "\t\t\t| Drink : Mirinda                |"<<endl;
                    cout << "\t\t\t| Price : $3 (12% off)           |"<<endl;
                    cout << "\t\t\t -------------------------------- "<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo2*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo2*quantity)){ //fn1353

					balance=payment-(combo2*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo2*quantity));
					f:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo2<<"      "<<combo2*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo2*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto f;
					}
					break;

					\


					case '3' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ----------Combo 3-----------"<<endl;
                    cout << "\t\t\t| Food  : Cheese sauce fried  |"<<endl;
                    cout << "\t\t\t|         chicken + rice      |"<<endl;
                    cout << "\t\t\t| Drink : Orange juice        |"<<endl;
                    cout << "\t\t\t| Price : $2.5 (10% off)      |"<<endl;
                    cout << "\t\t\t -----------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo3*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo3*quantity)){ //fn1353

					balance=payment-(combo3*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo3*quantity));
					g:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo3<<"      "<<combo3*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo3*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto g;
					}
					break;




					case '4' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ------------Combo 4-------------"<<endl;
                    cout << "\t\t\t| Food  : 5pcs Fried Chicken     |"<<endl;
                    cout << "\t\t\t|                                |"<<endl;
                    cout << "\t\t\t| Drink : 3 random drinks        |"<<endl;
                    cout << "\t\t\t| Price : $9.55 (best seller)    |"<<endl;
                    cout << "\t\t\t --------------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo4*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo4*quantity)){ //fn1353

					balance=payment-(combo4*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo4*quantity));
					h:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo4<<"      "<<combo4*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo4*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto h;
					}
					break;




					case '5' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ----------Combo 5------------"<<endl;
                    cout << "\t\t\t| Food  : 3pcs Fried Chicken  |"<<endl;
                    cout << "\t\t\t|          + 2 Potato chips   |"<<endl;
                    cout << "\t\t\t| Drink : 2 Pepsi             |"<<endl;
                    cout << "\t\t\t| Price : $8                  |"<<endl;
                    cout << "\t\t\t -----------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo5*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo5*quantity)){ //fn1353

					balance=payment-(combo5*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo5*quantity));
					i:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo5<<"      "<<combo5*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo5*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto i;
					}
					break;




					case '6' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ------------Combo 6-------------"<<endl;
                    cout << "\t\t\t| Food  : Spicy sauce Chicken    |"<<endl;
                    cout << "\t\t\t|       + Hamburger medium size  |"<<endl;
                    cout << "\t\t\t| Drink : Tornado cashew         |"<<endl;
                    cout << "\t\t\t| Price : $4.5 (Recommended)     |"<<endl;
                    cout << "\t\t\t --------------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo6*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo6*quantity)){ //fn1353

					balance=payment-(combo6*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo6*quantity));
					j:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo6<<"      "<<combo6*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo6*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto j;
					}
					break;





					case '7' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t ----------Combo 7-------------"<<endl;
                    cout << "\t\t\t| Food  : 7pcs random sauce     |"<<endl;
                    cout << "\t\t\t|         chicken + rice        |"<<endl;
                    cout << "\t\t\t| Drink : 3 Free to choose      |"<<endl;
                    cout << "\t\t\t| Price : $11.06 (best seller)  |"<<endl;
                    cout << "\t\t\t -------------------------------"<<endl;
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo7*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo7*quantity)){ //fn1353

					balance=payment-(combo7*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo7*quantity));
					k:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo7<<"      "<<combo7*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo7*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto k;
					}
					break;




					case '8' :

					cout << "\n\t\t\tQuantity   : ";
					cin >> quantity;
					system("cls");
					cout << "\n\t\t\t------------Combo 8--------------"<<endl;
                    cout << "\t\t\t| Food  : 3 Beef sauce spaghettis|"<<endl;
                    cout << "\t\t\t|       + 3 Hamburgers big size  |"<<endl;
                    cout << "\t\t\t| Drink : 3 random drinks        |"<<endl;
                    cout << "\t\t\t| Price : $9.98 (30% off)        |"<<endl;
                    cout << "\t\t\t --------------------------------"<<endl;

					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour total cost is $ "<<(combo8*quantity)<<endl;
					do{
					cout << "\n\t\t\tPlease make your payment : $ ";
					cin  >> payment;

					if(payment>=(combo8*quantity)){ //fn1353

					balance=payment-(combo8*quantity);
					cout << fixed<<showpoint<<setprecision(2);
					cout << "\n\t\t\tYour balance is : $ " << balance<<endl;

					}
					else{

					cout<< "\n\t\t\tPayment not enough";
					}
					}while(payment<(combo8*quantity));
					l:
					cout << "\n\n\t\t\tDo you want to print receipt? [Y/N] ";
					cin >> receipt;
					if(receipt=='Y'||receipt=='y'){
						system("cls");
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t|                   LOTTERIA                    |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << endl;
						cout << "                          "<<dt<<endl;
						cout << "\t\t\t  Tel     : 028-3722-8555      Fax   : 208-057-258"<<endl;
						cout << "\t\t\t  Address : FPT Software    Order : 30041975"<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t  Cashier :  Tran Hoang Chuong"<<endl;
						cout << "\t\t\t  Shift   :  SHIFT-1"<<endl;
						cout << endl;
						cout << "\n\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t| Description      Qty     Price      Amount     |"<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
						cout << "\t\t\t  Set D "<<"   	    "<<quantity<<" 	   "<<combo8<<"      "<<combo8*quantity<<"	   "<<endl;
						cout << "                                                "<<endl;
						cout << "\t\t\t  Total "<<"                              "<<combo8*quantity<<endl;
						cout << "\t\t\t  Cash "<<"                               "<<payment<<endl;
						cout << "\t\t\t  Balance "<<"                            "<<balance<<endl;
						cout << "\t\t\t ------------------------------------------------"<<endl;
					}
					else if(receipt=='N'||receipt=='n'){
						goto welcomemenu;
					}
					else{
						cout << "\n\t\t\tYou enter wrong input!!!"<<endl;
						goto l;
					}
					break;


				default :
					cout << "\n\t\t\t Your order is not available ! "<<endl;
					goto choose;
					break;
				}

				welcomemenu:
				cout<<"\n";
				system("PAUSE");
				cout << "\n\n\t\t\t Menu : "<<endl;
				cout << endl;
				cout << "\t\t\t 1. Order again"<<endl;
				cout << "\t\t\t 2. Exit"<<endl;

				cout << "\n\t\t\t Enter choice :";
				cin >> input;

				switch(input){
					case 1 :
						goto menu;
						break;
					case 2 :
						cout << "\n\t\t\t -----------------------------"<< endl;
						cout << "\t\t\t| Thank you for your order    |"<<endl;
						cout << "\t\t\t -----------------------------"<<endl;
						system("PAUSE");
						exit(EXIT_SUCCESS);
						break;
					default :
						cout << "\n\t\t\t You enter wrong input"<<endl;
						goto welcomemenu;
						break;
				}


	}

