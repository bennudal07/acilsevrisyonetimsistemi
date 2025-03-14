# acilsevrisyonetimsistemi
 veri yapıları ve algoritmalar ödev-3
Acil Servis Yönetim Sistemi

Bu proje, bir acil servis yönetim sistemini simüle eden basit bir C programıdır. Hastaların kaydedilmesi, bilgilerine erişilmesi, silinmesi ve reçete bilgilerinin görüntülenmesi gibi temel işlevleri içerir.

# Özellikler

1.Yeni hasta kaydı oluşturma

2.Kayıtlı hastaların bilgilerini görüntüleme

3.Tüm hastaları listeleme

4.Hasta kaydını silme (pasif hale getirme)

5.Hastanın reçete bilgilerini görüntüleme

6.Rastgele sıra numarası ve reçete numarası atama

7. Poliklinik seçimine göre doktor atama

# Kullanım

1.Programı derleyin:

2.Programı çalıştırın.

3.Menüden istediğiniz işlemi seçin ve yönlendirmeleri takip edin.

# Yapı

1.Hasta struct'ı, hasta bilgilerini içerir.

2.PoliklinikDoktor struct'ı, poliklinik ve doktor eşleşmelerini tutar.

3.hastalar dizisi, sistemde kayıtlı tüm hastaları saklar.

4.menuGoster(): Ana menüyü gösterir.

5.yeniHastaKaydi(): Yeni bir hasta kaydı oluşturur.

6.hastaBilgisiGoruntule(): Belirtilen TC numarası ile hasta bilgilerini görüntüler.

7.tumHastalariGoruntule(): Tüm kayıtlı hastaları listeler.

8.hastaSil(): Belirtilen TC numarasına sahip hastayı siler.

9.receteGoruntule(): Hastanın reçete bilgilerini gösterir.

# Gereksinimler

1. C derleyicisi;
İnternet üzerinden uygulamaya gerek olmadan çalışan bir derleyici: Online C Compiler

Windows bilgisayarda çalışması için: DevC++

Tüm bilgisayarlarda çalışması için: Visual Studio

2. Standart C kütüphaneleri (stdio.h, stdlib.h, string.h, time.h)
