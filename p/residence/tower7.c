

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "非天塔"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

每个人都有自己的命运，如果太辉煌，就可能较短促；
你愿意做颗流星，还是做个蜡烛？
流星的光芒虽短暂，可是那种无比的辉煌和美丽，又岂是千万根蜡烛所能比得上的。

LONG);
        set("exits", ([

  "down" : __DIR__"tower"+(query("floor")-1),
  "up" : __DIR__"tower"+(query("floor")+1), 

]));
  	set("coor/x",-10);
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
