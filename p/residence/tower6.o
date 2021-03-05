

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "非天塔"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

世上有些事正是如此，越想得多，顾虑越多，
于是就做不成了，
若是不想就做，反而说不定能做得通。
世上有许多轰轰烈烈的大事，正是不想做而就出来的，若是仔细想过，便不会做了。


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
