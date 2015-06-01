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


stage5
----------
先測試test5.cpp<br>
這邊測試insert跟push_back有沒有寫對<br>
開始之前建議把constructor多宣告的node先移除<br>
再測試test5_2.cpp<br>
這部份是測試stable_vector push_back的效率<br>
正常來說均攤之後的結果要是O(1)<br>
總之執行超過1秒（基本上沒寫好會根本跑不出來）就是沒有寫的很好<br>
需要考慮如何改進


stage6 ~ stage10 晚點補
----------


Final
---------
最後要檢查有沒有memory leak的問題<br>
可以把code寄給我<br>
我可以幫忙測試（助教給的main.cpp）後把**所有輸出**貼回給你
