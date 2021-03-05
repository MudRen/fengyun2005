
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "枫叶泉");
        set("long", @LONG
风云城中的枫叶泉是方圆五百里最著名的一口温泉。据老人们说：从前水温适中，
泉水呈淡红,故而得名枫叶。它不但有去腐生肌的奇效，据说还有延年益寿的妙
用。从前的武林第一美人林仙儿每天都以此泉水浣面，来保持她如花似玉的容貌。
不过旁边放着一个大大牌子上面写着：电线脱落，澡塘暂时关闭。
LONG
        );
        set("exits", ([
                "west" : __DIR__"hfenglang3",
        ]));
        set("objects", ([
                __DIR__"npc/": 2,
        ]) );
        set("outdoors", "fengyun");
        set("coor/x",45);
        set("coor/y",45);
        set("coor/z",-300);
        setup();
        create_door("west", "檀木门", "east", DOOR_CLOSED);

}


