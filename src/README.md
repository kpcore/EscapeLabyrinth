
EscapeLabyrinth Project
===================


Yöntem Bölümü
-------------

**Konu:** Grafta arama 
**Problem:** Labirentten çıkış bulma

Matrisin verilen *Height* ve *Width* sayısı ve verilen *HxW*’lik labirent için, başlangıç hücresi (1,1)’den verilen *K* ve *L* değerleri için bitiş hücresi *(K,L)*’ye yol olup olmadığını **DFS(Depth First Search)** yöntemi ile bulan bir algoritma tasarlanacaktır.
<br/>
**Çözüm:**

Problemi çözmek için *depth first search* ile kullanılan *stack* mantığını kullandım. Ayrıca gezilen düğümleri ayrı bir *visit* dizisinde tuttum. Problemdeki ana mesele ise yol ayrımlarında seçtiğimiz tarafın *dead end* yani çıkmaz sokak olması durumuydu. Bu meseleyi ise bir *turnOut* dizisinde yol ayrımlarını tutarak aştım. Temelde bulunduğumuz *node* 'un komşu sayısı 1'den büyükse ilgili *node'un* *turnOut* değeri 'komşu sayısı - 1'  kadar oluyor. Buradaki - 1 ise bizim komşulardan herhangi birini seçmemiz durumunu ifade ediyor ve o yol ayrımına her geldiğimizde bu değer bir azalıyor. Bulunduğumuz *node* 'un komşu sayısı 1 ise zaten o komşu seçilecektir. *turnOut* değeri 0 olur. *Node* 'un komşu sayısı 0 ise çıkmaz yola girmiş demektir zaten. 
<br/>

Uygulama Bölümü
-------------

**İşlem Adımları:**

1-Üzerinde işlem yaptığımız matrisi ilk olarak duvarlar 0, yollar 1 olacak şekilde tüm hücreler birbirinden bağımsız olarak tasarladık. Örneğin 7x7'lik formatlı matris gösterimi şöyle gözükür;

     +  -  +  -  +  -  + 
     |     |     |     | 
     +  -  +  -  +  -  + 
     |     |     |     | 
     +  -  +  -  +  -  + 
     |     |     |     | 
     +  -  +  -  +  -  + 

<br/>

2-Daha sonra kullanıcıdan duvarları girmesini istiyoruz. Örneğin matriste (1,4), (2,1), (2,5), (3,2), (3,4), (4,1), (5,2), (5,4) noktalarını duvar olmaktan çıkarıp yola dönüştürelim. Döngüden çıkmak için son yolun (0,0) girilmesi gerekiyor ve duvarlar girildikten sonraki matrisimiz;

     +  -  +  -  +  -  + 
     |     |           | 
     +     +  -  +     + 
     |                 | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 

<br/>

3-Başlangıç ve bitiş noktalarını alıyoruz Örneğimiz için Başlangıç = (1,1), Bitiş = (1,5) ;

     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |                 | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 
<br/>


4-Başlangıç noktasından  başlayarak gelinen her noktayı *visit* dizisine atıyoruz. O noktanın sırası ile kuzey, doğu, güney ve batı yönündeki komşularına bakıp *visit* dizisinde olmayan komşularını *stack*  dizisine atıyoruz.  Sonra *stack* ten sonraki gidilecek komşu noktayı çekiyoruz ve aynı işlemleri o nokta için de uyguluyoruz. Gittiğimiz yolu  **I** ile gösteriyoruz. Ayrıca her bir işlem adımını tutan *Iteration Number* ve başlangıç noktasından olan uzaklığı tutan *Step Sequence* bilgilerini her adımda gösteriyoruz.  


     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I              | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 1
    Iteration Number: 1
   <br/>

    
 5- Ayrıca yukarıdaki durum gibi herhangi bir yol ayrımına gelindiğinde iki yoldan *'stack'e* son atılan komşuyu seçip oradan gidiyoruz. Bu noktada; eğer seçtiğimiz komşudan tarafa giden yol, çıkmaz yol ise bu konumu *turnOut* dizisinde belirli bir algoritmaya göre tutuyoruz.
    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I              | 
     +     +  -  +  -  + 
     |  I              | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 2
    Iteration Number: 2
    
    
    ----------------------
    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I              | 
     +     +  -  +  -  + 
     |  I     I        | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 3
    Iteration Number: 3
    
    
    ----------------------
    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I              | 
     +     +  -  +  -  + 
     |  I     I     I  | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 4
    Iteration Number: 4
    
   <br/>
6-Bu noktada en son yol ayrımına geri dönmemiz lazım. *turnOut* dizisinden en son yol ayrımına *backtracking* yapıyoruz. *Step Sequence* bilgisini güncelliyoruz.
   
         Backtracking    
    ----------------------
    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I              | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 1
    Iteration Number: 5
    
    
    ----------------------
    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I     I        | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 2
    Iteration Number: 6
    
    
    ----------------------
    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I     I     I  | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 3
    Iteration Number: 7
    
 <br/>
7-Ve bitiş noktasına ulaşıyoruz.
    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |  I     I     I  | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 
    
    ----------------------
    
    Step Sequence: 4
    Iteration Number: 8
    
                         
       TARGET REACHED!   


 
<br/>



Sonuç Bölümü
-------------

Algoritmamız, eğer seçilen komşular hedefimiz yönünde ise yani herhangi bir yol ayrımına geri dönmek zorunda kalmıyorsak en iyi durumda çalışıyordur. Fakat gezdiğimiz *node* 'ların ulaşmaya çalıştığımız noktaya tahmini uzaklıklarını veya yolun hedefe çıkıp çıkmayacağını bilmediğimizden, labirentin tasarlanmasına göre karmaşıklık hesabı da değişir. Komşu seçimini sabit bir sıraya göre (kuzey, doğu, güney, batı sırası) yaptığımızdan dolayı eğer bu duruma ters bir labirent üzerinde geziyorsak bütün *node* 'ları dolaşıp sonra hedefe varabilme ihtimalimiz de var. Zaten bu durum da en kötü durum olmuş oluyor. Yani karmaşıklığı temelde yaptığımız *backtracking* sayısı ile ölçebiliriz. Ki bu bize karmaşıklık hesabımızın *Iteration number* / *Step Sequence* oranı olduğunu gösterir.
    
    

                         
