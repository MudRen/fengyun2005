

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

一朵花也是一个生命。
在那朵花开的那一瞬间，也就是生命诞生的时候。
一个生命在天地孕育中诞生，其中变化之精微奇妙，世上绝没有任何事能比得上。

LONG);
        set("exits", ([
"804" : __DIR__"userroom/jeffu1568436573",
"803" : __DIR__"userroom/jeffz1568432238",
"802" : __DIR__"userroom/jeffp1568425106",
"801" : __DIR__"userroom/dwd1568259576",
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


