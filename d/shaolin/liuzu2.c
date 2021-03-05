// annie 07.2003
// dancing_faery@hotmail.com

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "六祖殿");
        set("long", @LONG
与紧那罗殿东西相对，殿面阔三间，殿内祀初祖达摩，二祖慧可，三祖僧粲，
四祖道信，五祖弘忍，六祖慧能塑像，正中供奉观音菩萨，称为“六祖朝观音”，
四周墙壁还画有历代名僧画像。确是佛家宝殿。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"liuzu",
]));
        set("objects", ([
                __DIR__"npc/xin_qian" : 1,
       ]) );
	set("coor/x",-20);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
