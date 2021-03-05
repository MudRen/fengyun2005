

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "登天殿"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

不要命的人，就是最可怕的人
不要命的武功，就是最可怕的武功

LONG);
        set("exits", ([

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
