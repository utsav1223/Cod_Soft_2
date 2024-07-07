#include <iostream>
#include <iostream>
using namespace std;
//Declaring Variables//
string name_1{""};
string name_2{""};
int row{};
int column{};
int token{'X'};
int number{};
bool tie;
char array[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
//Declaring Prototypes//
void function_1();
void function_2();
bool function_3();
//------------------------------------------------------------//
void function_1(){
    cout << "     |       |      \n";
    cout << "  " << array[0][0] << "  |  " << array[0][1] << "    |  " << array[0][2] << endl;
    cout << "_____|_______|______\n";
    cout << "     |       |      \n";
    cout << "  " << array[1][0] << "  |  " << array[1][1] << "    |  " << array[1][2] << endl;
    cout << "_____|_______|______\n";
    cout << "     |       |      \n";
    cout << "  " << array[2][0] << "  |  " << array[2][1] << "    |  " << array[2][2] << endl;
    cout << "     |       |      \n";
}
void function_2(){
    if(token=='X'){
        cout<<"Please enter "<<name_1<<" : ";
        cin>>number;
    }
    if(token=='O'){
        cout<<"Please enter "<<name_2<<" : ";
        cin>>number;
    }
    switch (number) {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        if(number<1 || number>9){
        cout << "Invalid Number !!!" << endl;
        }
    }
if(token=='X' && array[row][column] != 'X' && array[row][column] !='O'){
    array[row][column]='X';
    token='O';
}
else if(token=='O' && array[row][column] != 'X' && array[row][column] !='O'){
    array[row][column]='O';
    token='X';
}
else{
    cout<<"There is no empty space !"<<endl;
    function_2();
}
}
bool function_3(){
    for(int i=0; i<3; i++){
        if(array[i][0]==array[i][1] && array[i][0]==array[i][2] || array[0][i]==array[1][i] && array[0][i]==array[2][i]){
            return true;
        }
    }

if(array[0][0]==array[1][1] && array[1][1]==array[2][2] || array[0][2]==array[1][1] && array[1][1]==array[2][0]){
    return true;
}
for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        if(array[i][j]!='X' && array[i][j]!= 'O'){
            return false;
        }
    }
}
tie=true;
return false;
}
int main(){
    cout<<"-------Welcome ! to TIC_TAC_TOE game------- "<<endl;
    cout<<"Enter Player name_1: ";
    getline(cin, name_1);
    cout<<"Enter Player name_2: ";
    getline(cin,name_2);
    cout<<"\n";
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"So "<<name_1<<" is player 1 so he/she will play first  ! "<<endl;
    cout<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"So "<<name_2<<" is player 2 so he/she will play second ! "<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    while(!function_3()){
        function_1();
        function_2();
        function_3();
    }
    if(token=='X' && tie==false){
        cout<<"Congratulations ! "<<name_2<<" wins.... "<<endl;
    }
    else if(token=='O' && tie==false){
        cout<<"Congratulations ! "<<name_1<<" wins.... "<<endl;
    }
    else{
        cout<<"It's a draw !"<<endl;
    }
    return 0;
}

