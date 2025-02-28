/*
    Hocam merhaba. Derse gelmediğim için içeriği bilmiyorum ama konu basit zaten. bilmediğim kısımları öğrenmek için chat e sorarak aşağıdaki mesajı attım. Sonrasında anlattı ve bir kod yazdı. Yazılan kodu ufak düzenlemeyle çıktı aldım. Öğrenmem gereken şeyleri öğrenmiş oldum.

    •C dili ile iki uint64_t diziyi ve
    bu dizilerin uzunluğunu bağımsız değişken olarak alan “KopyalaveSirala” adlı bir fonksiyon yazınız.
    Alınan iki dizinin uzunluğunun aynı olduğunu varsayınız. Fonksiyon, ilk dizinin
    elemanlarını iterate etmeli ve bu elemanları ikinci
    diziye artan sırayla eklemek için insertion sort algoritmasını kullanmalıdır.
    (Problemi birden çok fonksiyona ayırarak çözebilirsiniz.) KopyalaveSirala fonksiyonunu çalıştıran bir main
    () fonksiyonu yazınız.
    
    selam. ödevimiz bu. hadi birlikte yapalım.
    
    sorular...
    uint64_t nedir?
    iterate etmek nedir?
    insertion sort algoritmasını nedir?
    
    yanlış anlamadıysam ilk dizi dolu 2. si boş olacak. ilk diziyi algoritma ile sıralayıp 2. diziye atacağız. pointer tipinde dizileri atacağımız için 2. diziye kayıt edilmiş olacak bu sonuç. doğru mu?
    
    yani döngü ile her elemanı tek tek alacağız. algoritma ile yerleştirip dönecek. ya da recursive çalışacak. sıralama yapıp yapıp birleştiricez. en sona sıralanmış dizi kalacak. ya da en küçüğü recursive olarak bulup bulup 2. diziye atacağız.
    
    anlat bakalım
*/

#include <stdio.h>
#include <stdint.h>

void KopyalaVeSirala(uint64_t *kaynak, uint64_t *hedef, int uzunluk) 
{
    // İlk diziyi ikinci diziye kopyala
    for (int i = 0; i < uzunluk; i++) 
    {
        hedef[i] = kaynak[i];
    }

    // Insertion Sort ile hedef diziyi sıralama
    for (int i = 1; i < uzunluk; i++) 
    {
        uint64_t key = hedef[i];
        int j = i - 1;

        // Key'in doğru yerine kadar elemanları sağa kaydır
        while (j >= 0 && hedef[j] > key) 
        {
            hedef[j + 1] = hedef[j];
            j--;
        }
        hedef[j + 1] = key;
    }
}

int main() 
{
    uint64_t kaynakDizi[] = {5,9,31,7,13,1,12,18,15,10};
    int uzunluk = sizeof(kaynakDizi) / sizeof(kaynakDizi[0]);

    uint64_t hedefDizi[uzunluk];

    printf("Orijinal Dizi: ");
    for (int i = 0; i < uzunluk; i++) 
    {
        printf("%llu ", kaynakDizi[i]);
    }
    printf("\n");

    // Fonksiyonu çağır
    KopyalaVeSirala(kaynakDizi, hedefDizi, uzunluk);

    // Sonucu ekrana yazdır
    printf("Sıralanmış Dizi: ");
    for (int i = 0; i < uzunluk; i++) 
    {
        printf("%llu ", hedefDizi[i]);
    }
    printf("\n");

    return 0;
}
