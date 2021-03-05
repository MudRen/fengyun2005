

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "登天殿"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

做出来的事，就是真的。
你做的事若有君子之风，你就是个君子。
否则，你的心纵然善良，做出来的却全都是坏事，也还是一样不可塬谅的。

LONG);
        set("exits", ([
"303" : __DIR__"userroom/welldone1606121369",
"302" : __DIR__"userroom/sendita1606093470",
"307" : __DIR__"userroom/fgb1574320190",
"305" : __DIR__"userroom/stork1574319886",
"301" : __DIR__"userroom/yun1570545919",
"306" : __DIR__"userroom/freewall1536901985",
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
