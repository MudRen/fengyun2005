

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "笑浅楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

笑，就像是香水，不但能令自己芬芳，也能令别人快乐。
你若能令别人笑一笑，纵然做做愚蠢的事又何妨？

LONG);
        set("exits", ([
  "down" : __DIR__"smile"+(query("floor")-1),
  "up" : __DIR__"smile"+(query("floor")+1), 
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
