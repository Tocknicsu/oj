yyp/hw6
========

參考的人可以照著stage打<br>
這是個人建議的實作步驟<br>
實際情形可自己調適

建議每打完一組stage就compile一次<br>
然後進行測試


在開始之前<br>
建議大家先將空function的";"改為"{}"<br>
可以少很多warning<br>
用command line的記得編譯參數要下--std=c++11<br>


到第stage4之前的測試<br>
你的stable_vector的constructor的需要多插幾個節點<br>
不然測試的時候會收到RE(因為在stage5之前都沒有插入的功能)


stage1
--------
在stage1的時候可以多插幾個節點<br>
之後寫完push_back的時候再回去留一個end的節點就好<br>
這樣方便做test<br>
size的部份一開始可以直接等於v的size<br>
這樣能確保你的end節點沒有錯誤<br>
也是之後再把他改回正確的<br>




stage2
--------
測試的時候<br>
一開始應該輸出你所有的節點<br>
之後front跟back都應該要被改變


stage3、4
--------
stage3沒辦法獨立在main裡面做測試<br>
所以就跟4放在一起測試<br>
這邊主要測試iterator跟const_iterator的建構跟取值



