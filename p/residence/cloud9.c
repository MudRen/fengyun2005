

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "登天殿顶层");
  set ("long", @LONG

　　　　　天上白玉京　十二楼五城　仙人抚我顶　结发受长生

　　　　　九十六圣君　浮云挂空名　天地赌一掷　未能忘战争　

LONG);
        set("exits", ([
"902" : __DIR__"userroom/mlgb1569660897",
"901" : __DIR__"userroom/mlove1568341653",
  "down" : __DIR__"cloud"+(query("floor")-1), 
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
