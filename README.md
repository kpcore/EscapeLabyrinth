
Depth First Search ile Labirentten Çıkış Bulma
===================

<br/>

Description
-------------

- **Konu:** Grafta arama 
- **Problem:** Labirentten çıkış bulma

  Matrisin verilen *Height* ve *Width* sayısı ve verilen *HxW*’lik labirent için, başlangıç hücresi (1,1)’den verilen *K* ve *L* değerleri için bitiş hücresi *(K,L)*’ye yol olup olmadığını **DFS(Depth First Search)** yöntemi ile bulan bir algoritma tasarlanacaktır.

- **İşlem Adımları:**

  HxW hücreden oluşan labirent için bir matris kullanılacak. Labirent matrisinde duvarları 0, açık yolları 1 ile gösterilir. Örneğin matrisin **[1][2] değeri 0 ise 1. satır 2. sütündaki hücre duvardır**. Her hücrenin kuzey, güney, doğu ve batı yönünde toplam 4 komşusu vardır. Matrisin kenar hücrelerinin de 4 komşusu olabilmesi için (H+1)*(W+1)’lik bir matris tanımlayıp kenar hücreler için işlem yapılmaz.
<br/>


<br/>
<br/>

>    **1-** İşleme (1,1) hücresinden başlayınız.

>   **2-** İşlem yapılan her (x,y) hücresini **“gelindi”** olarak işaretlenir.

>   **3-** Her hücre için *DFS* yöntemi ile kuyruk yapısını kullanarak sırasıyla *Kuzey-(x,y+1)*, *Doğu-(x+1,y)*, *Güney-(x,y-1)* ve *Batı-(x-1,y)* yönündeki komşularına bakılır. Eğer bakılan hücre duvar değilse yığına ekleyerek işleme devam edilir.

>   **4-** (KxL) hücresine gelindiyse yol bulunmuş ve işlem bitmiştir.

<br/>

<br/>


- Duvarlar : '-' ve '|' 
- Odalar : ' ' 
- Odaların köşeleri : '+'
- Başlangıç : '*' 
- Çıkış : 'X' 
- İzlediği yol: ‘I’

<br/>
<br/>

Output
-------------


    
     +  -  +  -  +  -  + 
     |  *  |        X  | 
     +     +  -  +     + 
     |                 | 
     +     +  -  +  -  + 
     |                 | 
     +  -  +  -  +  -  + 
    
    ----------------------
    Step Sequence: 0
    Iteration Number: 0
    
    
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
    Iteration Number: 1
    
    
    ----------------------
    
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
    
    
    ----------------------
    
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
                         
