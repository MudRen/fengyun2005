// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "紧那罗殿");
        set("long", @LONG
大雄殿东，内祀紧那罗像三尊，中为藤像，左为铜像，右为铁像，造型皆雄奇。
称为少林寺的护法伽蓝，这与别处奉关羽为护寺伽蓝大有不同，所谓伽蓝，本身在
梵语中便有寺院的意思。所以这间伽蓝殿的规模实在不小。看着手持铁棍的紧那罗，
你不禁心有所动。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"jinna",
]));
        set("objects", ([
                BOOKS"skill/jinna_100" : 1,
                __DIR__"npc/laomonk" : 1,
       ]) );
	set("coor/x",20);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
