#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

int exe_time=0,exe_time_p=0, exe_time_d=0, exe_time_r=0,mms=0,ps=0,ds=0,rs=0;
#define pnum 10
#define dnum 10
#define rnum 30

string pfname[pnum];
string plname[pnum];
string page[pnum];
string pfee[pnum];
string pdis[pnum];
bool paid[pnum];
string pcontact[pnum];
string dfname[dnum];
string dlname[dnum];
string dage[dnum];
string dsal[dnum];
bool dpaid[dnum];
string dcontact[dnum];
string dspec[dnum];
string rid[rnum]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30"};
string rtype[rnum];
int rrent[rnum];
string rreg[rnum];
int rrd[rnum];

bool available[10];

void dsel(int ds);
void rsel(int rs);
void startup(int);
void menu();
void mmsel(int);
void pm();
void dm();
void rm();
void p_save_rec();
void p_read_rec();
bool login();
void psel(int);
string* split(string s,char c);
char capital_char(char);
string capital(string);
void d_read_rec();
void d_save_rec();
void r_read_rec();
void r_save_rec();

int main(int a=1){
	startup(a);
	system("pause");
	system("cls & color 48");
	if(login()==true){
		system("cls");
		menu();
	}else{
		main(0);
	}
}
void startup(int a=1){
	for(int i=0;i<30;i++){
		rreg[i]="No";
		if(i<15){
			rtype[i]=" normal ";
			rrent[i]=250;
		}
		else if(i<25){
			rtype[i]="  good  ";
			rrent[i]=500;
		}
		else if(i<30){
			rtype[i]="verygood";
			rrent[i]=700;
		}
	}
	p_read_rec();
	d_read_rec();
	r_read_rec();
	system("mode 110 & color 3f & title Hospital Management System");
	cout<<"\n"<<endl;
	cout<<"\t\t::      ::    ::::::     ::::::::: ::::::::  :::: ::::::::::    :::    ::                "<<endl;
	cout<<"\t\t::      ::  ::      ::  ::         ::     ::  ::      ::       :: ::   ::                "<<endl;
	cout<<"\t\t:::::::::: ::        ::  ::::::::  ::::::::   ::      ::      ::   ::  ::                "<<endl;
	cout<<"\t\t::      ::  ::      ::          :: ::         ::      ::     ::::::::: ::                "<<endl;
	cout<<"\t\t::      ::    ::::::    :::::::::  ::        ::::     ::     ::     :: :::::::::         "<<endl;
	cout<<"\n"<<endl;
	cout<<" ::::   ::::    :::    :::     ::    :::     :::::::: ::::::::: ::::    :::: ::::::::: :::      :: ::::::::::"<<endl;
	cout<<" :: :: :: ::   :: ::   :: ::   ::   :: ::   ::        ::        :: ::  :: :: ::        :: ::    ::     ::    "<<endl;
	cout<<" ::  :::  ::  ::   ::  ::  ::  ::  ::   ::  ::  ::::: ::::::::: ::   :::  :: ::::::::: ::  ::   ::     ::    "<<endl;
	cout<<" ::       :: ::::::::: ::    :::: ::::::::: ::     :: ::        ::        :: ::        ::    :: ::     ::    "<<endl;
	cout<<" ::       :: ::     :: ::     ::: ::     ::  :::::::  ::::::::: ::        :: ::::::::: ::      :::     ::    "<<endl;
	cout<<"\n"<<endl;
	cout<<"\t\t    ::::::::::  ::      ::  ::::::::: :::::::::: ::::::::: ::::   :::: "<<endl;
	cout<<"\t\t   ::            ::    ::  ::             ::     ::        :: :: :: :: "<<endl;
	cout<<"\t\t    :::::::::     ::::::    ::::::::      ::     ::::::::: ::  :::  :: "<<endl;
	cout<<"\t\t            ::      ::             ::     ::     ::        ::       :: "<<endl;
	cout<<"\t\t   ::::::::::       ::     :::::::::      ::     ::::::::: ::       :: "<<endl;
	cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"\n\tQualities:\n\n\t\t1: 24 Hours Emergency\n\n\t\t2: 100% Power Backup\n\n\t\t3: Expert Doctors\n\n\t\t4: Medical Store\n"<<endl;
	if(a==0){
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\t\t\t::                                                        ::\n";
	cout<<"\t\t\t\tFailed to Login! Retry...\n";
	cout<<"\t\t\t::                                                        ::\n";
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\t\t\t\n";
	}
}
bool login(){
	string uname="" ,upass="";
	cout<<"\n";
	cout<<"\t\t\t     ::         ::::::::   ::::::::  :::: :::       ::   "<<endl;
	cout<<"\t\t\t     ::        ::      :: ::          ::  :: ::     ::   "<<endl;
	cout<<"\t\t\t     ::        ::      :: ::   :::::  ::  ::   ::   ::   "<<endl;
	cout<<"\t\t\t     ::        ::      :: ::      ::  ::  ::     :: ::   "<<endl;
	cout<<"\t\t\t     :::::::::  ::::::::  :::::::::: :::: ::       :::   "<<endl;
	cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\t\t\t::                                                        ::\n";
	cout<<"\t\t\t\tUsername: ";
	cin>>uname;
	cout<<"\t\t\t::                                                        ::\n";
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\t\t\t::                                                        ::\n";
	cout<<"\t\t\t\tPassword: ";
	cin>>upass;
	cout<<"\t\t\t::                                                        ::\n";
	cout<<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\n\t\t\t\tSubmit\n\t\t\t\t";
	system("pause");
	string user[]={"Sameer","Samson","Waseem"};
	string pass[]={"sameer","samson","waseem"};
	for(int i=0;i<3;i++){
		if(user[i]==uname){
			if(pass[i]==upass){
				return true;
			}
		}
		else if(i==2){
			main(0);
			return false;
		}
	}

}

//Main Menu Begains
void menu(){
	while(true){
	system("color 67");
	string menu[6]={"Exit/Quite","Patients Menu","Doctors Menu","Rooms Record","","Logout"};
	if(exe_time==0){
		cout<<endl<<endl;
		cout<<"\t\t     **     **    *     *** **    *       **     ** ****** **    * *     * "<<endl;
		cout<<"\t\t     * *   * *   *  *    *  * *   *       * *   * * *      * *   * *     * "<<endl;
		cout<<"\t\t     *   *   *  ******   *  *  *  *       *   *   * ****** *  *  * *     * "<<endl;
		cout<<"\t\t     *       * *      *  *  *   * *       *       * *      *   * * *     * "<<endl;
		cout<<"\t\t     *       * *      * *** *    **       *       * ****** *    **  *****  "<<endl;
		cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\t[ID:]\t[Discription:]\n"<<endl;
		for(int i=1;i<6;i++)
			if(menu[i]!="")cout<<"\t  "<<i<<":\t"<<menu[i]<<endl<<endl;
		if(menu[0]!="")cout<<"\t  "<<0<<":\t"<<menu[0]<<endl<<endl;
	}
	exe_time++;
	cout<<"\tSelect an entry in above menu >>> ";
	cin>>mms;
	cout<<endl;
	if(mms>=0 && mms<6 && menu[mms]!=""){
		mmsel(mms);
	}
	else{
		cout<<"\tInvalid Entry!\n\tTry Again...\n\n";
	}
		}
}
void mmsel(int mms){
	switch(mms){
		case 0:
			exit(0);
			break;
		case 5:
			exe_time=0;
			main();
			break;
		case 4:
			cout<<"No option Yet";
			break;
		case 1:
			system("cls");
			pm();
			break;
		case 2:
			system("cls");
			dm();
			break;
		case 3:
			system("cls");
			rm();
			break;
	}

}
//Main Menu End

//Pmenu Begains
void pm(){
	string menu[8]={"Exit/Quite","New Record","View All","Update Record","Delete Record","Save Changes","Pay Fee","Back"};
	while(true){
		system("color c7");
		if(exe_time_p==0){
			cout<<endl<<endl;
			cout<<"\t\t\t\t ********   **     ** ****** **    * *     * "<<endl;
			cout<<"\t\t\t\t *       *  * *   * * *      * *   * *     * "<<endl;
			cout<<"\t\t\t\t ********   *   *   * ****** *  *  * *     * "<<endl;
			cout<<"\t\t\t\t *          *       * *      *   * * *     * "<<endl;
			cout<<"\t\t\t\t *          *       * ****** *    **  *****  "<<endl;
			cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
			cout<<"\t[ID:]\t[Discription:]\n"<<endl;
			for(int i=1;i<8;i++)
				if(menu[i]!="")cout<<"\t  "<<i<<":\t"<<menu[i]<<endl<<endl;
			if(menu[0]!="")cout<<"\t  "<<0<<":\t"<<menu[0]<<endl<<endl;
		}
		exe_time_p++;
		cout<<"\tSelect an entry in above menu >>> ";
		cin>>ps;
		cout<<endl;

		if(ps>=0 && ps<8 && menu[ps]!=""){
			psel(ps);
		}
		else{
			cout<<"\tInvalid Entry!\n\tTry Again...\n\n";
		}
	}

}
void psel(int ps){
    bool next;
	switch(ps){
		case 1:
			while(true){
				for(int i=0;i<pnum;i++){
					if(pfname[i]==""){
						cout<<"\t\tPatient First Name : ";
						cin>>pfname[i];
						pfname[i]=capital(pfname[i]);
						cout<<"\t\tPatient Last Name : ";
						cin>>plname[i];
						plname[i]=capital(plname[i]);
						cout<<"\t\tPatient Age : ";
						cin>>page[i];
						cout<<"\t\tPatient Phone : ";
						cin>>pcontact[i];
						cout<<"\t\tPatient Disease Discription : ";
						cin>>pdis[i];
						cout<<"\t\tPatient Fee : ";
						cin>>pfee[i];
						cout<<"\t\tPaid (1=Yes/0=No): ";
						cin>>paid[i];
						break;
					}
				}
				bool next=true;
				cout<<"\t      Add next record (1=Yes / 0=No ) : ";
				cin>>next;
				cout<<"\n";
				if(next==false)break;
			}

			break;
		case 2:
			cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Fee:]\t[Disease:]\t[Paid:]\n";
			for(int i=0;i<pnum;i++){
			if(pfname[i]!=""){
				cout<<"\n\t\t"<<i<<"\t"<<pfname[i]<<" "<<plname[i]<<"\t"<<page[i]<<"\t"<<pcontact[i]<<"\t"<<pfee[i]<<"\t"<<pdis[i]<<"\t\t";
				if(paid[i]==1){
					cout<<" Yes\n";
				}else{
					cout<<" No\n";
				}
			}
			}
			cout<<"\n";
			break;
		case 3:
			next=true;
			while(next==true){
				cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Fee:]\t[Disease:]\t[Paid:]\n";
				for(int i=0;i<pnum;i++){
				if(pfname[i]!=""){
					cout<<"\n\t\t"<<i<<"\t"<<pfname[i]<<" "<<plname[i]<<"\t"<<page[i]<<"\t"<<pcontact[i]<<"\t"<<pfee[i]<<"\t"<<pdis[i]<<"\t\t";
					if(paid[i]==1){
						cout<<" Yes\n";
					}else{
						cout<<" No\n";
					}
				}
				}
				cout<<"\n";
					cout<<"\t      Enter Patient's ID to Modify : ";
					int i;
					cin>>i;
					cout<<"\n";
					if(pfname[i]!=""){
						cout<<"\t\tPatient First Name : ";
						cin>>pfname[i];
						pfname[i]=capital(pfname[i]);
						cout<<"\t\tPatient Last Name : ";
						cin>>plname[i];
						plname[i]=capital(plname[i]);
						cout<<"\t\tPatient Age : ";
						cin>>page[i];
						cout<<"\t\tPatient Phone : ";
						cin>>pcontact[i];
						cout<<"\t\tPatient Disease Discription : ";
						cin>>pdis[i];
						cout<<"\t\tPatient Fee : ";
						cin>>pfee[i];
						cout<<"\t\tPaid (1=Yes/0=No): ";
						cin>>paid[i];
						cout<<"\t      Update next record (1=Yes / 0=No ) : ";
						cin>>next;
						cout<<"\n";
					}
			}
			break;
		case 4:
		    next=true;
			while(next==true){
				cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Fee:]\t[Disease:]\t[Paid:]\n";
				for(int i=0;i<pnum;i++){
				if(pfname[i]!=""){
					cout<<"\n\t\t"<<i<<"\t"<<pfname[i]<<" "<<plname[i]<<"\t"<<page[i]<<"\t"<<pcontact[i]<<"\t"<<pfee[i]<<"\t"<<pdis[i]<<"\t\t";
					if(paid[i]==1){
						cout<<" Yes\n";
					}else{
						cout<<" No\n";
					}
				}
				}
				cout<<"\n";
					cout<<"\t      Enter Patient's ID to Modify : ";
					int i;
					cin>>i;
					cout<<"\n";
					if(pfname[i]!=""){
						   	pfname[i]="";
                        for(int in=i;in<pnum;in++){
                                if(pfname[in+1]!=""){
                                    pfname[in]=pfname[in+1];
                                    plname[in]=plname[in+1];
                                    page[in]=page[in+1];
                                    pfee[in]=pfee[in+1];
                                    pcontact[in]=pcontact[in+1];
                                    paid[in]=paid[in+1];
                                    pdis[in]=pdis[in+1];
                            	}
                            	else{
                            		pfname[in]="";
									 break;
								}
                        }
						cout<<"\t      Delete next record (1=Yes / 0=No ) : ";
						cin>>next;
						cout<<"\n";
					}
			}
			break;
		case 5:
			p_save_rec();
			cout<<"\t\tSuccessfully Saved!\n"<<endl;
			break;
		case 6:
			next=true;
			while(next==true){
				cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Fee:]\t[Disease:]\t[Paid:]\n";
				for(int i=0;i<pnum;i++){
				if(pfname[i]!=""){
					cout<<"\n\t\t"<<i<<"\t"<<pfname[i]<<" "<<plname[i]<<"\t"<<page[i]<<"\t"<<pcontact[i]<<"\t"<<pfee[i]<<"\t"<<pdis[i]<<"\t\t";
					if(paid[i]==1){
						cout<<" Yes\n";
					}else{
						cout<<" No\n";
					}
				}
				}
				cout<<"\n";
					cout<<"\t      Enter Patient's ID to Pay Fee : ";
					int i;
					cin>>i;
					cout<<"\n";
					if(pfname[i]!=""){
						paid[i]=1;
						cout<<"\t\tPaid Successfully!\n";

						cout<<"\t      Update next record (1=Yes / 0=No ) : ";
						cin>>next;
						cout<<"\n";
					}
			}
			break;
		case 7:
			p_save_rec();
		    system("cls");
		    exe_time=0;
		    exe_time_p=0;
		    exe_time_d=0;
			menu();
			break;
		case 0:
		    p_save_rec();
			exit(0);
			break;
		}

}
//Pmenu Ends
//Dmenu Starts
void dm(){
	string menu[8]={"Exit/Quite","New Record","View All","Update Record","Delete Record","Save Changes","Pay Salory","Back"};
	while(true){
		system("color c7");
		if(exe_time_d==0){
			cout<<endl<<endl;
			cout<<"\t\t\t\t ********   **     ** ****** **    * *     * "<<endl;
			cout<<"\t\t\t\t *       *  * *   * * *      * *   * *     * "<<endl;
			cout<<"\t\t\t\t *        * *   *   * ****** *  *  * *     * "<<endl;
			cout<<"\t\t\t\t *       *  *       * *      *   * * *     * "<<endl;
			cout<<"\t\t\t\t ********   *       * ****** *    **  *****  "<<endl;
			cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
			cout<<"\t[ID:]\t[Discription:]\n"<<endl;
			for(int i=1;i<8;i++)
				if(menu[i]!="")cout<<"\t  "<<i<<":\t"<<menu[i]<<endl<<endl;
			if(menu[0]!="")cout<<"\t  "<<0<<":\t"<<menu[0]<<endl<<endl;
		}
		exe_time_d++;
		cout<<"\tSelect an entry in above menu >>> ";
		cin>>ds;
		cout<<endl;

		if(ps>=0 && ps<8 && menu[ps]!=""){
			dsel(ds);
		}
		else{
			cout<<"\tInvalid Entry!\n\tTry Again...\n\n";
		}
}
}
void dsel(int ds){
    bool next;
	switch(ds){
		case 1:
			while(true){
				for(int i=0;i<dnum;i++){
					if(dfname[i]==""){
						cout<<"\t\tDoctor's First Name : ";
						cin>>dfname[i];
						dfname[i]=capital(dfname[i]);
						cout<<"\t\tDoctor's Last Name : ";
						cin>>dlname[i];
						dlname[i]=capital(dlname[i]);
						cout<<"\t\tDoctor's Age : ";
						cin>>dage[i];
						cout<<"\t\tDoctor's Phone : ";
						cin>>dcontact[i];
						cout<<"\t\tDoctor's Specialization : ";
						cin>>dspec[i];
						cout<<"\t\tDoctor's Salory : ";
						cin>>dsal[i];
						cout<<"\t\tPaid (1=Yes/0=No): ";
						cin>>dpaid[i];
						break;
					}
				}
				bool next=true;
				cout<<"\t      Add next record (1=Yes / 0=No ) : ";
				cin>>next;
				cout<<"\n";
				if(next==false)break;
			}

			break;
		case 2:
			cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Salory:]\t[Special:]\t[Paid:]\n";
			for(int i=0;i<dnum;i++){
			if(dfname[i]!=""){
				cout<<"\n\t\t"<<i<<"\t"<<dfname[i]<<" "<<dlname[i]<<"\t"<<dage[i]<<"\t"<<dcontact[i]<<"\t"<<dsal[i]<<"\t\t"<<dspec[i]<<"\t\t";
				if(dpaid[i]==1){
					cout<<" Yes\n";
				}else{
					cout<<" No\n";
				}
			}
			}
			cout<<"\n";
			break;
		case 3:
			next=true;
			while(next==true){
				cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Salory:]\t[Special:]\t[Paid:]\n";
				for(int i=0;i<dnum;i++){
				if(dfname[i]!=""){
					cout<<"\n\t\t"<<i<<"\t"<<dfname[i]<<" "<<dlname[i]<<"\t"<<dage[i]<<"\t"<<dcontact[i]<<"\t"<<dsal[i]<<"\t\t"<<dspec[i]<<"\t\t";
					if(dpaid[i]==1){
						cout<<" Yes\n";
					}else{
						cout<<" No\n";
					}
				}
				}
				cout<<"\n";
					cout<<"\t      Enter Patient's ID to Modify : ";
					int i;
					cin>>i;
					cout<<"\n";
					if(dfname[i]!=""){
						cout<<"\t\tDoctor's First Name : ";
						cin>>dfname[i];
						dfname[i]=capital(dfname[i]);
						cout<<"\t\tDoctor's Last Name : ";
						cin>>dlname[i];
						dlname[i]=capital(dlname[i]);
						cout<<"\t\tDoctor's Age : ";
						cin>>dage[i];
						cout<<"\t\tDoctor's Phone : ";
						cin>>dcontact[i];
						cout<<"\t\tDoctor's Specialization : ";
						cin>>dspec[i];
						cout<<"\t\tDoctor's Salory : ";
						cin>>dsal[i];
						cout<<"\t\tPaid (1=Yes/0=No): ";
						cin>>dpaid[i];
						cout<<"\t      Update next record (1=Yes / 0=No ) : ";
						cin>>next;
						cout<<"\n";
					}
			}
			break;
		case 4:
		    next=true;
			while(next==true){
				cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Fee:]\t[Disease:]\t[Paid:]\n";
				for(int i=0;i<dnum;i++){
				if(dfname[i]!=""){
					cout<<"\n\t\t"<<i<<"\t"<<dfname[i]<<" "<<dlname[i]<<"\t"<<dage[i]<<"\t"<<dcontact[i]<<"\t"<<dsal[i]<<"\t"<<dspec[i]<<"\t\t";
					if(paid[i]==1){
						cout<<" Yes\n";
					}else{
						cout<<" No\n";
					}
				}
				}
				cout<<"\n";
					cout<<"\t      Enter Patient's ID to Modify : ";
					int i;
					cin>>i;
					cout<<"\n";
					if(dfname[i]!=""){
						   	dfname[i]="";
                        for(int in=i;in<dnum;in++){
                                if(dfname[in+1]!=""){
                                    dfname[in]=pfname[in+1];
                                    dlname[in]=plname[in+1];
                                    dage[in]=page[in+1];
                                    dsal[in]=pfee[in+1];
                                    dcontact[in]=pcontact[in+1];
                                    dpaid[in]=paid[in+1];
                                    dspec[in]=pdis[in+1];
                            	}
                            	else{
                            		dfname[in]="";
									 break;
								}
                        }
						cout<<"\t      Delete next record (1=Yes / 0=No ) : ";
						cin>>next;
						cout<<"\n";
					}
			}
			break;
		case 5:
			d_save_rec();
			cout<<"\t\tSuccessfully Saved!\n"<<endl;
			break;
		case 6:
			next=true;
			while(next==true){
				cout<<"\t\t[ID:]\t[Name:]\t\t[Age]\t[Phone:]\t[Salory:]\t[Special:]\t[Paid:]\n";
				for(int i=0;i<dnum;i++){
				if(dfname[i]!=""){
					cout<<"\n\t\t"<<i<<"\t"<<dfname[i]<<" "<<dlname[i]<<"\t"<<dage[i]<<"\t"<<dcontact[i]<<"\t"<<dsal[i]<<"\t\t"<<dspec[i]<<"\t\t";
					if(dpaid[i]==1){
						cout<<" Yes\n";
					}else{
						cout<<" No\n";
					}
				}
				}
				cout<<"\n";
					cout<<"\t      Enter Doctor's ID to Pay Fee : ";
					int i;
					cin>>i;
					cout<<"\n";
					if(dfname[i]!=""){
						dpaid[i]=1;
						cout<<"\t\tPaid Successfully!\n";
						cout<<"\t      Update next record (1=Yes / 0=No ) : ";
						cin>>next;
						cout<<"\n";
					}
			}
			break;
		case 7:
			d_save_rec();
		    system("cls");
		    exe_time=0;
		    exe_time_p=0;
		    exe_time_d=0;
			menu();
			break;
		case 0:
		    d_save_rec();
			exit(0);
			break;
		}

}
//Dmenu Ends
//Rmenu Starts
void rm(){
	string menu[8]={"Exit/Quite","View All","Register Room","Unregister","Save Changes","","","Back"};
	while(true){
		system("color c7");
		if(exe_time_r==0){
			cout<<endl<<endl;
			cout<<"\t\t\t\t ********   **     ** ****** **    * *     * "<<endl;
			cout<<"\t\t\t\t *       *  * *   * * *      * *   * *     * "<<endl;
			cout<<"\t\t\t\t ********   *   *   * ****** *  *  * *     * "<<endl;
			cout<<"\t\t\t\t *      *   *       * *      *   * * *     * "<<endl;
			cout<<"\t\t\t\t *       *  *       * ****** *    **  *****  "<<endl;
			cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
			cout<<"\t[ID:]\t[Discription:]\n"<<endl;
			for(int i=1;i<8;i++)
				if(menu[i]!="")cout<<"\t  "<<i<<":\t"<<menu[i]<<endl<<endl;
			if(menu[0]!="")cout<<"\t  "<<0<<":\t"<<menu[0]<<endl<<endl;
		}
		exe_time_r++;
		cout<<"\tSelect an entry in above menu >>> ";
		cin>>rs;
		cout<<endl;

		if(rs>=0 && rs<8 && menu[rs]!=""){
			rsel(rs);
		}
		else{
			cout<<"\tInvalid Entry!\n\tTry Again...\n\n";
		}
}
}
void rsel(int rs){
    bool next;
    int i=0;
    int rrin,rpid;
	switch(rs){
		case 1:
			cout<<"\t\t[ID:]\t[Type:]\t        [Reg. :]\t[Day Rent:]  [Days No:]\n\n";
			while(i<30){
				cout<<"\t\t "<<rid[i]<<"\t"<<rtype[i]<<"\t";
				if(rreg[i]=="No")cout<<rreg[i]<<"\t\t"<<rrent[i]<<" Rs.\t\t"<<rrd[i]<<"\n";
				else cout<<rreg[i]<<"\t"<<rrent[i]<<" Rs.\t\t"<<rrd[i]<<"\n";
				i++;
			}
			cout<<"\n";
			break;
		case 2:
			cout<<"\t\t[ID:]\t[Type:]\t     [Reg. :]\t[Day Rent:]\n\n";
			while(i<30){
				if(rreg[i]=="No"){
					cout<<"\t\t "<<rid[i]<<"\t"<<rtype[i]<<"\t";
					if(rreg[i]=="No") cout<<rreg[i]<<"\t  "<<rrent[i]<<" Rs.\n";
					else cout<<rreg[i]<<"\t  "<<rrent[i]<<" Rs.\n";
				}

				i++;
			}
			cout<<"\n\t     Enter room ID to Register : ";
			cin>>rrin;
			cout<<"\t\tChoose Your Patient ID : ";
			for(int i=0;i<pnum;i++){
				if(pfname[i]!="") cout<<"\n\t\t\t"<<i<<"\t"<<pfname[i]<<" "<<plname[i];
			}
			cout<<"\n\t\t>>>";
			cin>>rpid;
			rreg[rpid]=pfname[rpid]+" "+plname[rpid];
			cout<<"\t\tEnter No. of Days : ";
			cin>>rrd[rrin-1];
			cout<<"\t\tYour total rent is "<<rrd[rrin-1]*rrent[rrin]<<"\n";
			break;
		case 3:
			cout<<"\t\t[ID:]\t[Type:]\t\t[Reg. :]\t[Day Rent:]\n\n";
			while(i<30){
				if(rreg[i]!="No"){
					cout<<"\t\t "<<rid[i]<<"\t"<<rtype[i]<<"\t";
					if(rreg[i]=="No") cout<<rreg[i]<<"\t"<<rrent[i]<<" Rs.\n";
					else cout<<rreg[i]<<"\t  "<<rrent[i]<<" Rs.\n";
				}

				i++;
			}
			cout<<"\n\t     Enter room ID to Register : ";
			cin>>rrin;
			if(rreg[rrin-1]!="No"){
				rreg[rrin-1]="No";
				rrd[rrin-1]=0;
			}

			break;
		case 4:
			r_save_rec();
			cout<<"\t\tSuccessfully Saved!\n"<<endl;
			break;
		case 6:

			break;
		case 7:
			r_save_rec();
		    system("cls");
		    exe_time=0;
		    exe_time_p=0;
		    exe_time_d=0;
		    exe_time_r=0;
			menu();
			break;
		case 0:
		    r_save_rec();
			exit(0);
			break;
		}

}
//Rmenu Ends
//Capitalization Begains
string capital(string word=""){
		string t3;
		for(int i=0;i<word.length();i++){
			t3+=capital_char(word[i]);
		}
		return t3;
}
char capital_char(char a){
	char small[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char capital[26]={'A','B','C','B','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	for(int i=0;i<26;i++){
		if(a==small[i]){
			return capital[i];
			break;
		}
		else if(capital[i]=='Z'){
			return a;
			break;
		}
	}
}
//Capitalization Ends
//Save record  begains
void p_save_rec(){
	ofstream handle;
	handle.open("patients.dbs");
	for(int i=0;i<pnum;i++){
		if(pfname[i]=="")
			break;
		handle<<pfname[i]<<"\n"<<plname[i]<<"\n"<<page[i]<<"\n"<<pcontact[i]<<"\n"<<pdis[i]<<"\n"<<paid[i]<<"\n"<<pfee[i]<<"\n";
	}
	handle.close();
}
void d_save_rec(){
	ofstream handle;
	handle.open("doctors.dbs");
	for(int i=0;i<pnum;i++){
		if(dfname[i]=="")
			break;
		handle<<dfname[i]<<"\n"<<dlname[i]<<"\n"<<dage[i]<<"\n"<<dcontact[i]<<"\n"<<dspec[i]<<"\n"<<dpaid[i]<<"\n"<<dsal[i]<<"\n";
	}
	handle.close();
}
void r_save_rec(){
	ofstream handle;
	handle.open("rooms.dbs");
	for(int i=0;i<rnum;i++){
		handle<<rid[i]<<"\n"<<rreg[i]<<"\n"<<rrd[i]<<"\n";
	}
	handle.close();
}
//Save record Ends
//read begains
bool stb(string s){
	if(s=="0")
		return false;
	else
		return true;
}
void p_read_rec(){
		char a[50];
	ifstream handle;
	handle.open("patients.dbs");
	for(int i=0;i>=0;i++){
        if(handle.good()==0){
            ofstream hand;
            hand.open("patients.dbs");
            hand<<"";
            hand.close();
            p_read_rec();
            break;
        }
		handle.getline(a,20);
		if(!handle.eof()){
			if(i%7==0){
				pfname[i/7]=a;
			}
			if(i%7==1){
				plname[(int)i/7]=a;
			}
			if(i%7==2){
				page[i/7]=a;
			}
			if(i%7==3){
				pcontact[i/7]=a;
			}
			if(i%7==4){
				pdis[i/7]=a;
			}
			if(i%7==5){
                paid[i/7]=stb(a);
			}
			if(i%7==6){
				pfee[i/7]=a;
			}
	   }else{
	   	break;
	   }
	}

	handle.close();
	cout<<a;
}
void d_read_rec(){
		char a[50];
	ifstream handle;
	handle.open("doctors.dbs");
	for(int i=0;i>=0;i++){
        if(handle.good()==0){
            ofstream hand;
            hand.open("doctors.dbs");
            hand<<"";
            hand.close();
            d_read_rec();
            break;
        }
		handle.getline(a,20);
		if(!handle.eof()){
			if(i%7==0){
				dfname[i/7]=a;
			}
			if(i%7==1){
				dlname[(int)i/7]=a;
			}
			if(i%7==2){
				dage[i/7]=a;
			}
			if(i%7==3){
				dcontact[i/7]=a;
			}
			if(i%7==4){
				dspec[i/7]=a;
			}
			if(i%7==5){
                dpaid[i/7]=stb(a);
			}
			if(i%7==6){
				dsal[i/7]=a;
			}
	   }else{
	   	break;
	   }
	}

	handle.close();
	cout<<a;
}
void r_read_rec(){
		char a[50];
	ifstream handle;
	handle.open("rooms.dbs");
	for(int i=0;i<30;i++){
        if(handle.good()==0){
            ofstream hand;
            hand.open("rooms.dbs");
            hand<<"";
            hand.close();
            d_read_rec();
            break;
        }
		handle.getline(a,20);
		if(!handle.eof()){
			if(i%3==0){
				rid[i/3]=a;
			}
			if(i%3==1){
				rreg[i/3]=a;
			}
			if(i%3==2){
				rrd[i/3]=atoi(a);
			}
	   }else{
	   	break;
	   }
	}
	handle.close();
	cout<<a;
}
////read Ends
