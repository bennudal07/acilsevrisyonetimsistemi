#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HASTA 100
#define MAX_STR 50

// Hasta bilgilerini tutan struct
typedef struct {
    char ad[MAX_STR];
    char soyad[MAX_STR];
    char tcNo[12];
    int yas;
    char cinsiyet;
    char sikayet[MAX_STR*2];
    int triaj; // 1-5 arasi oncelik (1 en yuksek)
    char telefon[15];
    char yakinTelefon[15];
    char alerji[MAX_STR];
    int buyukTansiyon;
    int kucukTansiyon;
    float ates;
    char poliklinik[MAX_STR];
    char doktor[MAX_STR];
    int siraNo;
    int aktif; // 1: aktif, 0: silinmis
} Hasta;

// Recete bilgilerini tutan struct
typedef struct {
    char tcNo[12];
    int receteNo;
} Recete;

// Poliklinik ve doktor eslestirmelerini tutan struct
typedef struct {
    char poliklinikAdi[MAX_STR];
    char doktorAdi[MAX_STR];
} PoliklinikDoktor;

// Global degiskenler
Hasta hastalar[MAX_HASTA];
Recete receteler[MAX_HASTA];
int hastaCount = 0;
int receteCount = 0;

// Poliklinik ve doktor listesi
PoliklinikDoktor poliklinikler[] = {
   {"Dahiliye", "Dr. Suleyman Cetin"},
    {"Ortopedi", "Dr. Sultan Pembe"},
    {"Kardiyoloji", "Dr. Beril Koru"},
    {"Noroloji", "Dr. Azra Batur"},
    {"Gogus", "Dr. Gaye Zumrut"},
    {"Genel Cerrahi", "Dr. Yusuf Can Cakmak"},
    {"Cildiye", "Dr. Mustafa Ceylan"},
    {"KBB", "Prf. Dr. Beste Yildiz"},
     {"Pediatri", " Dr. Guney Alaca"}
};

// Fonksiyon prototipleri
void menuGoster();
void yeniHastaKaydi();
void hastaBilgisiGoruntule();
void tumHastalariGoruntule();
void hastaSil();
void receteOlustur();
int rastgeleSayi(int min, int max);
char* doktorBul(char* poliklinik);

int main() {
    int secim;
    srand(time(NULL)); // Rastgele sayi uretimi icin
    
    while (1) {
        menuGoster();
        printf("Seciminiz: ");
        scanf("%d", &secim);
        
        switch (secim) {
            case 1:
                yeniHastaKaydi();
                break;
            case 2:
                hastaBilgisiGoruntule();
                break;
            case 3:
                tumHastalariGoruntule();
                break;
            case 4:
                hastaSil();
                break;
            case 5:
                receteOlustur();
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }
    
    return 0;
}

// Ana menu
void menuGoster() {
    printf("\n===== ACIL SERVIS YONETIM SISTEMI =====\n");
    printf("1- Yeni hasta kaydi\n");
    printf("2- Kayitli hastanin bilgilerini goruntule\n");
    printf("3- Kayitli tum hastalari goruntule\n");
    printf("4- Hasta sil\n");
    printf("5- Kayitli hastaya recete olustur\n");
    printf("0- Cikis\n");
}

// Min ve max arasinda rastgele sayi uretir
int rastgeleSayi(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Poliklinik adina gore doktor bulur
char* doktorBul(char* poliklinik) {
    int i;
    int poliklinikSayisi = sizeof(poliklinikler) / sizeof(poliklinikler[0]);
    
    for (i = 0; i < poliklinikSayisi; i++) {
        if (strcmp(poliklinikler[i].poliklinikAdi, poliklinik) == 0) {
            return poliklinikler[i].doktorAdi;
        }
    }
    
    return "Dr. Nobet";  // Eger eslesen poliklinik bulunamazsa
}

// Yeni hasta kaydi fonksiyonu
void yeniHastaKaydi() {
    if (hastaCount >= MAX_HASTA) {
        printf("Hata: Hasta kayit limiti doldu!\n");
        return;
    }
    
    Hasta yeniHasta;
    yeniHasta.aktif = 1;
    
    printf("\n=== YENI HASTA KAYDI ===\n");
    
    printf("Ad: ");
    scanf("%s", yeniHasta.ad);
    
    printf("Soyad: ");
    scanf("%s", yeniHasta.soyad);
    
    printf("TC No (11 hane): ");
    scanf("%s", yeniHasta.tcNo);
    
    // TC Kontrolu
    if (strlen(yeniHasta.tcNo) != 11) {
        printf("Hata: TC No 11 haneli olmalidir!\n");
        return;
    }
    
    // TC Numarasi daha once kayitli mi kontrolu
    int i;
    for (i = 0; i < hastaCount; i++) {
        if (hastalar[i].aktif && strcmp(hastalar[i].tcNo, yeniHasta.tcNo) == 0) {
            printf("Bu TC No zaten kayitli!\n");
            return;
        }
    }
    
    printf("Yas: ");
    scanf("%d", &yeniHasta.yas);
    
    printf("Cinsiyet (E/K): ");
    scanf(" %c", &yeniHasta.cinsiyet);
    
    printf("Sikayet: ");
    scanf(" %[^\n]", yeniHasta.sikayet);
    
    printf("Triaj (1-5 arasi, 1 en acil): ");
    scanf("%d", &yeniHasta.triaj);
    
    printf("Telefon: ");
    scanf("%s", yeniHasta.telefon);
    
    printf("Yakin Telefon: ");
    scanf("%s", yeniHasta.yakinTelefon);
    
    printf("Alerji: ");
    scanf(" %[^\n]", yeniHasta.alerji);
    
    printf("Buyuk Tansiyon: ");
    scanf("%d", &yeniHasta.buyukTansiyon);
    
    printf("Kucuk Tansiyon: ");
    scanf("%d", &yeniHasta.kucukTansiyon);
    
    printf("Ates (derece): ");
    scanf("%f", &yeniHasta.ates);
    
    printf("Poliklinik (Dahiliye/Ortopedi/Kardiyoloji/Noroloji/Gogus/Genel Cerrahi/Cildiye/KBB/Pediatri): ");
    scanf("%s", yeniHasta.poliklinik);
    
    // Doktor ata
    strcpy(yeniHasta.doktor, doktorBul(yeniHasta.poliklinik));
    
    // Rastgele sira no ata
    yeniHasta.siraNo = rastgeleSayi(1000, 9999);
    
    // Hasta kaydet
    hastalar[hastaCount++] = yeniHasta;
    
    printf("\nHasta kaydi basariyla eklendi!\n");
    printf("Hasta Sira No: %d\n", yeniHasta.siraNo);
    printf("Atanan Doktor: %s\n", yeniHasta.doktor);
}

// Hasta bilgilerini goruntuleme fonksiyonu
void hastaBilgisiGoruntule() {
    char tcNo[12];
    int bulundu = 0;
    int i;
    
    printf("\n=== HASTA BILGISI GORUNTULE ===\n");
    printf("TC No: ");
    scanf("%s", tcNo);
    
    for (i = 0; i < hastaCount; i++) {
        if (hastalar[i].aktif && strcmp(hastalar[i].tcNo, tcNo) == 0) {
            printf("\n--- HASTA BILGILERI (HL7) ---\n");
            printf("Ad: %s\n", hastalar[i].ad);
            printf("Soyad: %s\n", hastalar[i].soyad);
            printf("TC No: %s\n", hastalar[i].tcNo);
            printf("Yas: %d\n", hastalar[i].yas);
            printf("Cinsiyet: %c\n", hastalar[i].cinsiyet);
            printf("Sikayet: %s\n", hastalar[i].sikayet);
            printf("Triaj Onceligi: %d\n", hastalar[i].triaj);
            printf("Telefon: %s\n", hastalar[i].telefon);
            printf("Yakin Telefon: %s\n", hastalar[i].yakinTelefon);
            printf("Alerji: %s\n", hastalar[i].alerji);
            printf("Tansiyon: %d/%d\n", hastalar[i].buyukTansiyon, hastalar[i].kucukTansiyon);
            printf("Ates: %.1f\n", hastalar[i].ates);
            printf("Poliklinik: %s\n", hastalar[i].poliklinik);
            printf("Doktor: %s\n", hastalar[i].doktor);
            printf("Sira No: %d\n", hastalar[i].siraNo);
            bulundu = 1;
            break;
        }
    }
    
    if (!bulundu) {
        printf("Hata: Bu TC No'ya ait hasta bulunamadi!\n");
    }
}

// Tum hastalari goruntuleme fonksiyonu
void tumHastalariGoruntule() {
    int i;
    int aktifHastaSayisi = 0;
    
    printf("\n=== TUM HASTALAR ===\n");
    
    for (i = 0; i < hastaCount; i++) {
        if (hastalar[i].aktif) {
            printf("\n--- %d. Hasta ---\n", ++aktifHastaSayisi);
            printf("Ad Soyad: %s %s\n", hastalar[i].ad, hastalar[i].soyad);
            printf("TC No: %s\n", hastalar[i].tcNo);
            printf("Yas: %d, Cinsiyet: %c\n", hastalar[i].yas, hastalar[i].cinsiyet);
            printf("Sikayet: %s\n", hastalar[i].sikayet);
            printf("Triaj: %d\n", hastalar[i].triaj);
            printf("Poliklinik: %s\n", hastalar[i].poliklinik);
            printf("Doktor: %s\n", hastalar[i].doktor);
            printf("Sira No: %d\n", hastalar[i].siraNo);
        }
    }
    
    if (aktifHastaSayisi == 0) {
        printf("Sistemde kayitli hasta bulunmamaktadir.\n");
    }
}

// Hasta silme fonksiyonu
void hastaSil() {
    char tcNo[12];
    int bulundu = 0;
    int i;
    
    printf("\n=== HASTA SIL ===\n");
    printf("Silinecek hastanin TC No'su: ");
    scanf("%s", tcNo);
    
    for (i = 0; i < hastaCount; i++) {
        if (hastalar[i].aktif && strcmp(hastalar[i].tcNo, tcNo) == 0) {
            hastalar[i].aktif = 0;  // Hasta kaydini pasif yap
            printf("Hasta kaydi basariyla silindi.\n");
            bulundu = 1;
            break;
        }
    }
    
    if (!bulundu) {
        printf("Hata: Yanlis TC, kayit bulunamadi!\n");
    }
}

// Recete olusturma fonksiyonu
void receteOlustur() {
    char tcNo[12];
    int bulundu = 0;
    int i;
    
    printf("\n=== RECETE OLUSTUR ===\n");
    printf("Hasta TC No: ");
    scanf("%s", tcNo);
    
    for (i = 0; i < hastaCount; i++) {
        if (hastalar[i].aktif && strcmp(hastalar[i].tcNo, tcNo) == 0) {
            Recete yeniRecete;
            strcpy(yeniRecete.tcNo, tcNo);
            yeniRecete.receteNo = rastgeleSayi(100000, 999999);
            
            receteler[receteCount++] = yeniRecete;
            
            printf("\nRecete basariyla olusturuldu!\n");
            printf("Hasta: %s %s\n", hastalar[i].ad, hastalar[i].soyad);
            printf("Recete No: %d\n", yeniRecete.receteNo);
            printf("Doktor: %s\n", hastalar[i].doktor);
            
            bulundu = 1;
            break;
        }
    }
    
    if (!bulundu) {
        printf("Hata: Bu TC No'ya ait hasta bulunamadi!\n");
    }
}
