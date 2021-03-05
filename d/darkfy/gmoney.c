inherit ROOM;
#include <room.h>
void create()
{
        set("short", "镖局账房");
        set("long", @LONG
这里是金狮镖局出入镖银的账房，整间屋子是由坚硬的花岗石砌成的。连唯一的一
个小窗上都镶满拇指粗细的钢条。屋角有小床。这里由总镖头最亲信的人日夜把守。不
但如此，房中还有黄铜警铃，铃声一响，镖局伙计们就会蜂拥而至。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ghall",
]));
        set("objects", ([
        __DIR__"npc/xiansheng" : 1,
                        ]) );
        set("coor/x",20);
        set("coor/y",50);
        set("coor/z",-300);
        setup();
        create_door("south", "铁门", "north", DOOR_CLOSED);

}
