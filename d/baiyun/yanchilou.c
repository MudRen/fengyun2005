//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "雁翅楼");
    set("long", @LONG
雁翅楼的两端，各设有一座重檐尖顶的闕亭。整座楼上的构形，三面环抱，五峰
突出，高低错落，主次相相辅，气势雄伟，有“五凤楼”之称。楼上古篆一幅：
                           苍    有 
                           松    凤
                           迎    栖
                           客    梧
LONG
    );
    set("exits",
      ([
	"northdown" : __DIR__"dragonplace",
	"southeast" : __DIR__"emaze8",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	__DIR__"npc/songshi" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-30);
    set("coor/y",-70);
    set("coor/z",20);
    setup();
    replace_program(ROOM);
}
