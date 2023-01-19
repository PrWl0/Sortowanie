#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
struct Obywatel{
    std::string imie;
    int wiek;
    int ID;
};

int compvar(const void *one, const void *two)
{
    int a = *((int*)one);
    int b = *((int*)two);
    if (a<b)
        return -1;
    if (a == b)
        return 0;
    return 1;

}

double ciag_i(int wyraz){
    double wynik=4;
    for(int i=1; i<wyraz; i++){
        wynik=1.1*wynik+4;
    }
    return wynik;
}
double ciag_r(int n){
    if(n!=1){
        return ciag_r(n-1)*(1.1)+4;
    } else return 4;}
int random_number(int a, int b){
    return a+(rand()%(b-a+1));
};
void swapping(int &a, int &b) {      //swap the content of a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void bubble_sort(std::vector<int>& losowe){
    for(int i = 0; i<losowe.size();i++){
        int swap = 0;
        for(int j = 0; j<losowe.size()-i-1;j++){
            if(losowe[j]>losowe[j+1]){
                swapping(losowe[j],losowe[j+1]);
                swap=1;
            }
        }
        if(!swap)break;
    }
}
void insert_sort(std::vector<int>& losowe){
    int key,j;
    for(int i=1; i<losowe.size();i++){
        key = losowe[i];
        j=i;
        while (j>0 and losowe[j-1]>key){
            losowe[j]=losowe[j-1];
            j--;
        }
        losowe[j]=key;
    }
}
const int ch_MAX = 26;
std::string RandomString(int ch)
{
    char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                           'h', 'i', 'j', 'k', 'l', 'm', 'n',
                           'o', 'p', 'q', 'r', 's', 't', 'u',
                           'v', 'w', 'x', 'y', 'z' };
    std::string result = "";
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % ch_MAX];

    return result;
}


std::vector<Obywatel> tworzenie(int n){
    std::vector<Obywatel> ludzie(n);
    for(int i; i<ludzie.size(); i++){
        ludzie[i].imie= RandomString(15);
        ludzie[i].wiek= random_number(0,100);
        ludzie[i].ID= random_number(0,10000000000);
    }
    return ludzie;
}
void display_student (Obywatel student){
    std::cout<<"--------------------------------"<<std::endl;
    std::cout<<"Imie: "<<student.imie<<std::endl;
    std::cout<<"Wiek: "<<student.wiek<<std::endl;
    std::cout<<"ID: "<<student.ID<<std::endl;
    std::cout<<"--------------------------------"<<std::endl;
}
void display_all_students(const std::vector<Obywatel>& vec){
    for(int i=0;i<vec.size();i+=1){
        display_student(vec[i]);
    }
}
int main() {
    srand(time(NULL));
   /* const int n = 20;
    int A=-100;
    int B=555;
  //  std::vector<int>losowe(n);
  //  for(int i = 0;i<losowe.size();i++){
    //    losowe[i]= random_number(A,B);
    //}
    for(int i = 0;i<losowe.size();i++){
        std::cout<<losowe[i]<<" ";
    }
    std::cout<<std::endl;
    //bubble_sort(losowe);
    //insert_sort(losowe);
    qsort(&losowe[0],losowe.size(),sizeof(int),compvar);*/
    std::vector<Obywatel> ludzie = tworzenie(2137);
    display_all_students(ludzie);







    return 0;
}