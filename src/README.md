<!DOCTYPE <!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
</head>
<body>
    <h1 id="2015-2016-güz-yarıyılı-algoritma-analizi-final-projesi">2015-2016 Güz Yarıyılı Algoritma Analizi Final Projesi</h1>

<hr>



<h2 id="yöntem-bölümü">Yöntem Bölümü</h2>

<p><strong>Konu:</strong> Grafta arama  <br>
<strong>Problem:</strong> Labirentten çıkış bulma</p>

<p>Matrisin verilen <em>Height</em> ve <em>Width</em> sayısı ve verilen <em>HxW</em>’lik labirent için, başlangıç hücresi (1,1)’den verilen <em>K</em> ve <em>L</em> değerleri için bitiş hücresi <em>(K,L)</em>’ye yol olup olmadığını <strong>DFS(Depth First Search)</strong> yöntemi ile bulan bir algoritma tasarlanacaktır. <br>
<br> <br>
<strong>Çözüm:</strong></p>

<p>Problemi çözmek için <em>depth first search</em> ile kullanılan <em>stack</em> mantığını kullandım. Ayrıca gezilen düğümleri ayrı bir <em>visit</em> dizisinde tuttum. Problemdeki ana mesele ise yol ayrımlarında seçtiğimiz tarafın <em>dead end</em> yani çıkmaz sokak olması durumuydu. Bu meseleyi ise bir <em>turnOut</em> dizisinde yol ayrımlarını tutarak aştım. Temelde bulunduğumuz <em>node</em> ‘un komşu sayısı 1’den büyükse ilgili <em>node’un</em> <em>turnOut</em> değeri ‘komşu sayısı - 1’  kadar oluyor. Buradaki - 1 ise bizim komşulardan herhangi birini seçmemiz durumunu ifade ediyor ve o yol ayrımına her geldiğimizde bu değer bir azalıyor. Bulunduğumuz <em>node</em> ‘un komşu sayısı 1 ise zaten o komşu seçilecektir. <em>turnOut</em> değeri 0 olur. <em>Node</em> ‘un komşu sayısı 0 ise çıkmaz yola girmiş demektir zaten.  <br>
<br></p>

<h2 id="uygulama-bölümü">Uygulama Bölümü</h2>

<p><strong>İşlem Adımları:</strong></p>

<p>1-Üzerinde işlem yaptığımız matrisi ilk olarak duvarlar 0, yollar 1 olacak şekilde tüm hücreler birbirinden bağımsız olarak tasarladık. Örneğin 7x7’lik formatlı matris gösterimi şöyle gözükür;</p>

<pre><code> +  -  +  -  +  -  + 
 |     |     |     | 
 +  -  +  -  +  -  + 
 |     |     |     | 
 +  -  +  -  +  -  + 
 |     |     |     | 
 +  -  +  -  +  -  + 
</code></pre>

<p><br></p>

<p>2-Daha sonra kullanıcıdan duvarları girmesini istiyoruz. Örneğin matriste (1,4), (2,1), (2,5), (3,2), (3,4), (4,1), (5,2), (5,4) noktalarını duvar olmaktan çıkarıp yola dönüştürelim. Döngüden çıkmak için son yolun (0,0) girilmesi gerekiyor ve duvarlar girildikten sonraki matrisimiz;</p>

<pre><code> +  -  +  -  +  -  + 
 |     |           | 
 +     +  -  +     + 
 |                 | 
 +     +  -  +  -  + 
 |                 | 
 +  -  +  -  +  -  + 
</code></pre>

<p><br></p>

<p>3-Başlangıç ve bitiş noktalarını alıyoruz Örneğimiz için Başlangıç = (1,1), Bitiş = (1,5) ;</p>

<pre><code> +  -  +  -  +  -  + 
 |  *  |        X  | 
 +     +  -  +     + 
 |                 | 
 +     +  -  +  -  + 
 |                 | 
 +  -  +  -  +  -  + 
</code></pre>

<p><br></p>

<p>4-Başlangıç noktasından  başlayarak gelinen her noktayı <em>visit</em> dizisine atıyoruz. O noktanın sırası ile kuzey, doğu, güney ve batı yönündeki komşularına bakıp <em>visit</em> dizisinde olmayan komşularını <em>stack</em>  dizisine atıyoruz.  Sonra <em>stack</em> ten sonraki gidilecek komşu noktayı çekiyoruz ve aynı işlemleri o nokta için de uyguluyoruz. Gittiğimiz yolu  <strong>I</strong> ile gösteriyoruz. Ayrıca her bir işlem adımını tutan <em>Iteration Number</em> ve başlangıç noktasından olan uzaklığı tutan <em>Step Sequence</em> bilgilerini her adımda gösteriyoruz.  </p>

<pre><code> +  -  +  -  +  -  + 
 |  *  |        X  | 
 +     +  -  +     + 
 |  I              | 
 +     +  -  +  -  + 
 |                 | 
 +  -  +  -  +  -  + 

----------------------
Step Sequence: 1
Iteration Number: 1
</code></pre>

<p><br></p>

<p>5- Ayrıca yukarıdaki durum gibi herhangi bir yol ayrımına gelindiğinde iki yoldan <em>‘stack’e</em> son atılan komşuyu seçip oradan gidiyoruz. Bu noktada; eğer seçtiğimiz komşudan tarafa giden yol, çıkmaz yol ise bu konumu <em>turnOut</em> dizisinde belirli bir algoritmaya göre tutuyoruz.</p>

<pre><code> +  -  +  -  +  -  + 
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
</code></pre>

<p><br> <br>
6-Bu noktada en son yol ayrımına geri dönmemiz lazım. <em>turnOut</em> dizisinden en son yol ayrımına <em>backtracking</em> yapıyoruz. <em>Step Sequence</em> bilgisini güncelliyoruz.</p>

<pre><code>     Backtracking    
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
</code></pre>

<p><br> <br>
7-Ve bitiş noktasına ulaşıyoruz.</p>

<pre><code> +  -  +  -  +  -  + 
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
</code></pre>

<p><br></p>

<h2 id="sonuç-bölümü">Sonuç Bölümü</h2>

<p>Algoritmamız, eğer seçilen komşular hedefimiz yönünde ise yani herhangi bir yol ayrımına geri dönmek zorunda kalmıyorsak en iyi durumda çalışıyordur. Fakat gezdiğimiz <em>node</em> ‘ların ulaşmaya çalıştığımız noktaya tahmini uzaklıklarını veya yolun hedefe çıkıp çıkmayacağını bilmediğimizden, labirentin tasarlanmasına göre karmaşıklık hesabı da değişir. Komşu seçimini sabit bir sıraya göre (kuzey, doğu, güney, batı sırası) yaptığımızdan dolayı eğer bu duruma ters bir labirent üzerinde geziyorsak bütün <em>node</em> ‘ları dolaşıp sonra hedefe varabilme ihtimalimiz de var. Zaten bu durum da en kötü durum olmuş oluyor. Yani karmaşıklığı temelde yaptığımız <em>backtracking</em> sayısı ile ölçebiliriz. Ki bu bize karmaşıklık hesabımızın <em>Iteration number</em> / <em>Step Sequence</em> oranı olduğunu gösterir.</p>
</body>
</html>