// Tie@fy3
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "山庄庭园");
  set("long",@LONG
迎面一个镥大的庭园，当中一个小小的莲花池，红门朱栏，绿草如锦；很难想
像这里就是江湖第一大帮--丐帮的总堂。绕过莲花池，便是大厅的大门。只见两名
手执短杖、身后麻袋厚厚一叠的丐帮弟子站在大厅门前的两侧。
LONG
  );
  	set("exits",([
	         "north":__DIR__"gb4",
	         "south":__DIR__"shungeng",
	         "west":__DIR__"gb3",
	         "east":__DIR__"gb2"
               ]));
    	set("outdoors", "jinan");
        set("coor/x",-20);
        set("coor/y",90);
        set("coor/z",0);
    	set("resource/water", 1);
    	set("liquid/container", "莲花池");    
    	set("liquid/name","莲花池水");
	setup();
}