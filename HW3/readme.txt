第一題:迷宮

程式結構如下:

第一個部分為讀入檔案，並紀錄有幾行、幾列及入口的座標，而後在迷宮外面築一圈牆(1)以便判斷是否超出界線


第二個部分為程式主結構:

利用while，當現在的位置不是出口(d)時，進入迴圈

while中，最外圍的判斷為是否為活路(deadroad函式)，若為活路再進入是否為岔路的判斷。(fork函式)
		
		一、若為活路:

			a.若為單向道:
			
			則直接移動，把走過的路設為*，如果走到出口(d)則呼叫print函式印出。
		
			b.若為岔路:
			
			則在岔路函式中把岔路座標記在stack1、stack2中，stack1為記錄岔路座標用
			，而stack2則記錄遇到岔路後走過的路的座標，以便做遇到死路的處理。
			而後進入到岔路的if迴圈，同樣移動，把走過的路設為*並把走過的路的座標push進stack2表示岔路後走的座標。

		二、若為死路
		
			a.若stack1裡面沒有座標表示沒有上一個岔路，此迷宮無出口。
			
			b.若走到死路且stack1內有座標，表示有上一個岔路，但因為前面已經把走過的路都設為*，
			故將stack2裡面的走過的路pop出來設為8，直到與stack1的座標相等，即為已經把死路的座標都設為8。

		
因為print出來結果需要是正確路線，故在print函式裡面，前面紀錄的死路(8)印出0


	
第二題:

2-1:noncircular queue

在noncircular queue的部分 一開始front、rear皆為-1，當全部刪除到queue為空時，front和rear自動回到-1
而當左邊還有空位而右邊已滿時。

2-2:circular queue 

在circular queue的部分，一開始front、rear皆為0，
因為空、滿的判斷狀況相同故要空一格不存，只能存3個欄位，而空的位置不固定，會隨情況旋轉。