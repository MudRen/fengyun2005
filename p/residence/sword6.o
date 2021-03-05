

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

在欢乐的地方，为什么不能有痛苦的往事？
若没有欢乐，哪裡来的痛苦？
痛苦与欢乐的距离，岂非本就在一线之间？

LONG);
        set("exits", ([
"601" : __DIR__"userroom/jeffo1558859470",
  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
]));
  	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
