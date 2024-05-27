#include<iostream>
#include<fstream>
using namespace std;

class Shopping {
    private:
    int pcode;
    float price ;
    float disc;
    string pname;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void list();
    void rem();
    void receipt();
};


void Shopping ::menu(){
    int choice ;
    string email;
    string password;
    cout<<"\t\t\t\t----------------------------------\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t     Super Market Main Menu       \n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t----------------------------------\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t   1)Administrator         \n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t   2)Buyer                 \n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t   3)Exit                  \n";
    cout<<"\t\t\t\t                           \n";

    cout<<"\t\t\t\t   Please Select any one choice     \n";

    cin>>choice;

    switch(choice){
        m:
        case 1:
       { 
        cout<<"\t\t\t please login : \n";
        cout<<"\t\t\t Enter Email   \n";
        cin>>email;

        cout<<"\t\t\t  Enter Password \n";
        cin>>password;


        if(email=="shaswat@2401" && password=="shaswat@123"){
            administrator();
        }
        else{
            cout<<"\t\t\t Invalid email or password \n";
        }
        break;
       }

        case 2:
        {
        buyer();
        break; 
        
        }

        case 3:
        {
        exit(0);
        break;
        }
        default:
        {
        cout<<"please select from the given options ";
        break;
        }
        
    }
    goto m ;
 }

    void Shopping::administrator(){
        m:
        int choice;
        cout<<"\n\n\t\t\t\t Administrator Menu";
    
        cout<<"\n\t\t|____________1)Add the Product_____________|";
        cout<<"\n\t\t|                                          |";
        cout<<"\n\t\t|____________2)Modify the product__________|";
        cout<<"\n\t\t|                                          |";
        cout<<"\n\t\t|____________3)delete the product__________|";
        cout<<"\n\t\t|____________                    __________|";
        cout<<"\n\t\t|___________ 4)Back to main menu___________|";
        cout<<"\nplease enter your choice :";

        cin>>choice;

        switch(choice){
            case 1:
            {
            add();
            break;
            }
            case 2:
            {
                edit();
                break;
            }
            case 3:
            {
                rem();
            }
            case 4:
            {
                menu();
                break;
            }
            default:
            {
                cout<<"\n\t\t\t Invalid choice";

            }
            
        }
        goto m;

     }

     void Shopping::buyer(){
       m:
        int choice;
        cout<<"\n\t\t\t\t buyer\n";
        cout<<"\n\n\t\t\t";
        cout<<"\n\t\t\t\t\t 1)buy product\t\t\n";
        cout<<"\n\n\t\t\t";

         

        cout<<"\n\t\t\t\t\t 2)go back\t\t\t\t\n";


        cout<<"\t\t\t  Enter your choice :  ";
        cin>>choice ;
        
        switch(choice){
            case 1:
            receipt();
            
            case 2:
            menu();
            
            default:
            cout<<"Invalid choice\n\t";
            


        }
        goto m;
        

     }

    void  Shopping::add(){
        m:
        fstream data;
        int c ;
        int token=0;

        float p;
        float d;
        string n;

        cout<<"\t\t\t\n\nadd a product\t\t\t\t";
        cout<<"\n\t\t\t\t";
        cout<<"\n\t\t\t product code \t\t\t\n";
        cin>>pcode;
        cout<<"\n\t\t\t Name ofproduct\t\t\t\n";
        cin>>pname;
        cout<<"\n\t\t\t\t";
        cout<<"\n\t\t\t price of the product\t\t\t\n";
        cin>>price;
        cout<<"\n\t\t\t\t";
       
        cout<<"\n\t\t\t\t";
        cout<<"\n\t\t\t discount on product\t\t\t";
        cin>>disc;

        data.open("database.txt",ios::in);

        if(!data){
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" " <<pname<<" "<<price<<" "<<disc<<"\n";
            data.close();


        }
        else{
            data>>c>>n>>p>>d;   //reading the file and copying its data in c n p d 
            while(!data.eof()){
                if(c==pcode){
                    token++;
                }
                data>>c>>n>>p>>d;  //this is used to iterate 
            }
                data.close();

                
        
            if(token == 1){
                goto m;
            }
            else{
                data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" " <<pname<<" "<<price<<" "<<disc<<"\n";
            data.close();

            }
        }    
            cout<<"\t\t\t\t\n record inserted";
        }

        void Shopping::edit(){
            fstream data,data1;
            int token;
            int pkey;
            int c ;
            float p;
            float d;
            string n;
            cout<<"\n\t\t\t Modify the product :";
            cout<<"\n\t\t\t product code  :";
            cin>>pkey;
            data.open("database.txt",ios::in);
            if(!data){
                cout<<"\n\t\t\t this file doesen't exist.";

            }
            else{
                data1.open("database1.txt;ios:app|ios:out");
            }
            data>>pcode>>pname>>price>>disc;

            while(!data.eof()){
                if(pkey==pcode){
                    cout<<"\n\t\t\t new product code   :";
                    cin>>c;
                    cout<<"\n\t\t\t name of the product   :";
                    cin>>n;
                    cout<<"\n\t\t\t price   :";
                    cin>>p;
                    cout<<"\n\t\t\t discount on the product  :";
                    cin>>d;
                    data<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                    cout<<"\n\t\t\t Product record edited";
                    token++;
                }
                else{
                    data1<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
                }
                data>>pcode>>pname>>price>>disc;
            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt","database.txt");
            if(token==0){
                cout<<"\n\t\t\t Record not found sorry";

            }
        
        }

    void Shopping::rem(){
        fstream data ,data1;

        int pkey;
        int token =0;
        cout<<"\n\t\t\t Delete Product";
        cout<<"\n\t\t\t product code  :";
        cin>>pkey;
        data.open("databae.txt",ios::in);
        if(!data){
            cout<<"\n\t\t\t File doesn't exist";


        }
        else{
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>disc;
            while(!data.eof()){
                if(pcode==pkey){
                    cout<<"\n\n product deleted successfuly";
                    token++;
                                }
                else{
                    data1<<pcode<<" "<<pname<<" "<<price<<" "<<disc;
                }
                data>>pcode>>pname>>price>>disc;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");
            if(token == 0 ){
                cout<<"\n\n Record not found ";
            }

            
            
        }

        
    }

    void Shopping::list(){
        fstream data ;
        data.open("database.txt",ios::in);
        cout<<"|___________________________________________________\n";
        cout<<"\n\nProNo\t\tName\t\tPrice\t\t\n";
        cout<<"|___________________________________________________\n";



        
        data>>pcode>>pname>>price>>disc;
        while(!data.eof()){
            cout<<pcode<<"            "<<pname<<"            " <<price<<endl;
        

        data>>pcode>>pname>>price>>disc;
        }
        data.close();
    }


    void Shopping::receipt(){
        fstream data ;
        int arrc[100];
        int arrq[100];
        char  choice;
        int c=0;
        float amount =0;
        float disc = 0;
        float total = 0 ;
       
        cout<<"\n____________|RECEIPT|_______________"<<endl;
        data.open("database.txt", ios::in);
        if(!data){
            cout<<"Empty databse";
            
        }
        else{
            
            data.close();
            list();
            cout<<"\n|_______________________________________|";
            cout<<"\n|";
            cout<<"\n|";
            cout<<"\n|please Place the order ";                             
            cout<<"\n|";
            cout<<"\n|";             
            cout<<"\n|________________________________________|";
        
            do{
                m:
                cout<<"\n\t\t Enter the product code : ";
                cin>>arrc[c];
                cout<<"\n\n enter the product quantity : ";
                cin>>arrq[c];
                for(int i =0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product please try again later";
                   goto m; 
                }
                     }
                
                    c++;
                    cout<<"do you want to buy a product if yes press y else n for no  : ";
                    cin>>choice;
            }
            while( choice == 'y');


                cout<<"\n\n|________________Receipt_______________|"<<endl;
                cout<<"\n\n";
                cout<<"productNo\tproductName\tprod Qty\tprice\tAmount\tAmount with discount "<<endl;
                cout<<"\n\n";
                
                for(int i =0; i<c ;i++){
                    data.open("database.txt",ios::in);
                    data>>pcode>>pname>>price>>disc;
                    while (!data.eof()){
                    if(pcode == arrc[i]){
                        amount = price*arrq[i];
                        disc=amount-(amount*disc/100);
                        total = total+disc;
                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t"<<disc<<endl;
                        
                    }
                    data>>pcode>>pname>>price>>disc;
                }
                
                }
                data.close();
             }
                cout<<"___________________________________________\n";


                cout<<"\n     Total Amount:"<<total;


            }
    
                int main()
                {
                    Shopping s;
                    s.menu();
                }
            

        

            


    


    

    

        


     




    





    
