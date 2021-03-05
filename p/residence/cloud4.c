

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "登天殿"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

每个练武的人，武功练到巅峰时，都会觉得很寂寞
因为到了那时，他就很难再找到一个真正的对手
所以有人不惜“求败”，因为他觉得只要能遇着一个真正的对手，纵然败了，也是愉快的。

LONG);
        set("exits", ([
"401" : __DIR__"userroom/field1574321449",
  "down" : __DIR__"cloud"+(query("floor")-1),
  "up" : __DIR__"cloud"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-50);
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
