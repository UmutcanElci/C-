#include <iostream>
#include <fstream>

using namespace std;
class passwordInfo{
public:
    string appName;
    string password;
};

void add(){
    ofstream file("./password.txt",ios::app);//Dosya olu?turuldu asl?nda sadece ad? ve nerde oldu?u belli de?il. ayr?ca sadece yazma i?lemlerinde kullan?l?r !
    passwordInfo p1;
    cout << "Uygulamanin adini giriniz : ";
    cin >> p1.appName;
    cout << "Uygulamanizin sifresini giriniz : ";
    cin >> p1.password;

    file.write(p1.appName.c_str(),p1.appName.size());
    file.write(" ",1);
    file.write(p1.password.c_str(),p1.password.size());
    file.write("\n",1);
    file.close();
    cout << "Verileriniz dosyaya eklendi !" << endl;
    /*
     * GÜNCELLEME file.open yerine file ? olu?tururken açm??da say?l?yor ! Bu yüzden
     * (Dosya olu?turudu somut olarak ismide belli ve ios::app modu sayesinde dosya n?n sonuna eklemeler yap?labilecek.
     * ./ txt dosyas?n? porgram?n olu?tu?u diziye yazar)
     * file.open("password.txt",ios::app) --> (yerine) ofstream file("password.txt",ios::app)
     */

}
void list(){
    ifstream readFile("./password.txt",ios::binary);//Dosya okumak için
    char buffer[256];
    if (readFile.is_open()) {
        passwordInfo p1;
        while (readFile.getline(buffer,256)) { // Dosyadan veri okuma
            cout << buffer << endl;
        }
    }

    readFile.close();
}
int main() {
  add();
    cout << "-----------------------" << endl;
    list();
    return 0;
}






/*
 * ios::in: Dosyay? okuma modunda açar. Bu modu kullanarak dosya içeri?ini okuyabilirsiniz.
ios::out: Dosyay? yazma modunda açar. Bu modu kullanarak dosyaya veri yazabilirsiniz. Bu modu kullanarak aç?lan bir dosya, varsa içeri?i silinerek yeniden olu?turulur.
ios::app: Dosyay? sona ekleme modunda açar. Bu modu kullanarak dosyan?n sonuna veri ekleyebilirsiniz. Bu modda, dosya aç?ld???nda konum dosyan?n sonunda olur ve her yazma i?lemi sonras?nda konum yine dosyan?n sonuna ta??n?r.
ios::binary: Dosyay? ikili modda açar. Bu modu kullanarak dosyan?n içeri?ini ikili veri olarak okuyabilirsiniz veya ikili veri yazabilirsiniz.
ios::ate: Dosya aç?ld???nda konum dosyan?n sonuna ta??n?r. Bu modu kullanarak dosyan?n içeri?ini de?i?tirerek sonuna eklemek veya mevcut verileri de?i?tirmek mümkündür.
ios::trunc: Dosyay? yazma modunda açar ve dosya içeri?ini siler. Bu modu kullanarak dosyay? s?f?rdan olu?turabilirsiniz.
 file.read() fonksiyonu, belirtilen dosyadan belirtilen say?da byte okur ve okunan verileri bir bellek blo?una kopyalar.
 */
