

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "非天塔"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

朋友就是朋友，朋友绝不分好坏，因为朋友只有一种。
如果你对不起我，出卖了我，你根本就不是我的朋友，根本就不配说这两个字。

LONG);
        set("exits", ([
"210" : __DIR__"userroom/love1568791274",
"207" : __DIR__"userroom/beauty1566785216",
"205" : __DIR__"userroom/kwok1565236478",
"209" : __DIR__"userroom/lain1537378893",
"208" : __DIR__"userroom/xxc1523149507",
"206" : __DIR__"userroom/mlhy1513492038",
"204" : __DIR__"userroom/liz1510132206",
"203" : __DIR__"userroom/xxa1509068652",
"202" : __DIR__"userroom/xxb1509068408",
"201" : __DIR__"userroom/hzz1509068338",
  "down" : __DIR__"tower1",
  "up" : __DIR__"tower3", 
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
