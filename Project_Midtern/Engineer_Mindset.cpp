#include <iostream>
#include <string>
using namespace std;
string suffixWithUnit ( double number ) {
        //!---- 2 biến để lưu phần nguyên và dư của 1 số nhập vào >= 1000
        int part_int, remainder;
        string byte, kilo_p1, kilo_p2, mega_p1, mega_p2;
        if(number >= 1000 && number < 1000000){
                part_int = number / 1000;
                remainder = number - (part_int * 1000);
                kilo_p1 = to_string(part_int);
                kilo_p2 = to_string(remainder);
                kilo_p1 = "" + kilo_p1 + "." + kilo_p2 + " Kilo";
                return kilo_p1;
        }else if(number >= 1000000){
                part_int = number / 1000000;
                remainder = number - (part_int * 1000000);
                mega_p1 = to_string(part_int);
                mega_p2 = to_string(remainder);
                mega_p1 = "" + mega_p1 + "." + mega_p2 + " Mega";
                return mega_p1;
        } else{
            byte = "" + to_string(number);
            int i = byte.length() - 1;
            while(byte[i] != '.' && i >=0){
                byte.pop_back();
                i--;
            }
             byte.pop_back();
             return byte;
        }
}
int main(){ 
    //todo: cho 1 chuỗi bất kì, viết chương trình chuẩn hóa chuỗi theo yêu cầu:
    /* + xóa hết khoảng trắng ở đầu và cuối chuỗi
       + mỗi từ cách nhau chỉ 1 khoảng trắng
       + viết hoa từ đầu tiên của chuỗi
    */  
   double number;
   cout<<"nhap vao gia tri number la: ";
   cin>>number;
   cout<<suffixWithUnit(number);

}