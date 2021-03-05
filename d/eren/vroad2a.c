inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山村中心");
        set("long", @LONG
再往前就是这个小山村的集市口了，青石小路变得宽敞起来，路旁没有店铺，
只有许多用油毡，茅草筑起的小亭子。每到正午这儿就热闹起来，各家各户拿着自
己酿的酒，种的菜，宰的肉到这儿来交易，偶尔也会有人从山外归来，带着些丝绸
杂货，引得大姑娘小媳妇们眼红心热。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad2",
	"east" : __DIR__"vroad3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",60);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
