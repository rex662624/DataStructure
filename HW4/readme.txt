作業一 矩陣相乘
	在這個作業中，儲存稀疏矩陣的部分，我是參考課本中的宣告方式得來，利用Head Node為線頭把所有矩陣連繫在一起。
	而因為需要儲存2個矩陣，故我用HdNode[3][]來宣告以儲存2個矩陣以及最後的答案矩陣。
	
	在矩陣相乘的函式，我是利用類似於課本中前面講到的array用排隊比身高的方式
	，如果有一方先走完則往下，否則則看看是否兩者為正確可以相乘的數字，相乘後儲存並印出答案。
	



作業二 transpose

	在這個作業中，我用link list儲存矩陣並宣告一個 tranpose的函式
	
	儲存稀疏矩陣的部分，我是參考課本中的宣告方式得來，利用Head Node為線頭把所有矩陣連繫在一起。

	在tranpose function中，利用的邏輯為，
		第一個for為從Headnode的下個元素開始，每個元素的row、col互換，
		第二個for為把所有node 的right、down互相交換，達成轉置後正確的指標。