// КОСТЯ Я ЛЮБЛЮ ТЕБЯ
#include <iostream>
#include <string>
#include <clocale>
using namespace std;
int checker(string str){
    if (str.empty()) return 0;
    for (int i=0; i<str.length(); i++){
        if ((int)str[i]!=-16){
            if ( ((int)str[i]<-128) || ((int)str[i]>-97) ) return 0;
        }
    }
    return 1;
}
void visioner_code(string str, string key, string letters){
    char str_char, new_char;
    int char_shift, char_position,key_num;
    string new_str = "";
    for (int i=0; i<str.length(); i++){
        key_num = i % key.length();
        for (int j=0; j<33;j++){
            if (((int)letters[j] - 64 ) == str[i]) {
            char_position = j;
            break;
        }
            else char_position = 6; // Ё МОМЕНТ)))
        }
        for (int k=0; k<33;k++){
            if (((int)letters[k] - 64 ) == key[key_num]){
            char_shift = k;
            break;
        }
            else char_shift = 6; // Ё МОМЕНТ)))
        }
        new_char = letters[(char_position + char_shift) % 33] ;
        new_str += new_char;
    }
    cout<<new_str;
}
int main()
{
    setlocale(LC_CTYPE, "");
    string letters = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    int check;
    string str_in,key_word;
    do{
        cout << "Введите текст без пробелов КАПСОМ\n";
        getline(cin, str_in);
        check = checker(str_in);
        if (!check) cout << "Недопустимый ввод\n";
    }while(!check);
    do{
        cout << "Введите кодовое слово без пробелов КАПСОМ\n";
        getline(cin, key_word);
        check = checker(key_word);
        if (!check) cout << "Недопустимый ввод\n";
    }while(!check);
    visioner_code(str_in,key_word,letters);
    return 0;
}