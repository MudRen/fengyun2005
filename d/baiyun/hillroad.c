//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "山行道");
    set("long", @LONG
行不至远，地势突起，遂又低伏。如此反复数次。你眼前猛然一亮。山势已作平
地。豁然开朗. 但见青山绿水掩映之下，赫然是一座山城。
LONG           );
    set("exits",
      ([
	"northdown" : __DIR__"duixiuhill",
	"southup" : __DIR__"hillroad2",
	"northeast" : __DIR__"guajianbei",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-100);
    set("coor/z",20);
    setup();
    replace_program(ROOM);
}
