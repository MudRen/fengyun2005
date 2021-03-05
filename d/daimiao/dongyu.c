//mac's dongyu.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","东御座");
  set("long",@LONG
此处又称迎宾堂，为皇帝登祀泰山时起居的处所，也是存放祭器的地方，其中
以温凉玉雕床尤以引人注目，此床长八尺，宽三尺，面刻三星波纹，上中部都是凉
的，而下部却是温的，为泰山三宝之一。
LONG
  );
  	set("exits",([
         	"west":__DIR__"renan",
         	"east": __DIR__"chuihua",
               ]));
        set("objects", ([
                
        ]) );
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
