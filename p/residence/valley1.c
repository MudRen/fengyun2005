

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "笑浅楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

　　　　　　　　　　翠鬟冠玉叶
　　　　　　　　霓袖捧瑶琴
　　　　　　应共吹箫侣
　　　　　　　　　　　　　暗相寻。

LONG);
        set("exits", ([
//  "down" : __DIR__"valley"+(query("floor")-1),
  "up" : __DIR__"valley"+(query("floor")+1), 
  "south" : __DIR__"enterance", 
]));
  	set("coor/x",-20);
	set("coor/y",-30);
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
