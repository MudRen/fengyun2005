// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "中岳庙");
        set("long", @LONG
庙宇依照山势起伏自北而南，由上而下铺陈营造，气势雄伟，景色壮观。正是
“飞檐映日，杰阁联云”。寺内现有百余座石刻碑碣，其中“中岳嵩高灵庙之碑”
是嵩山最古老的石碑了。庙内崇圣门神库四角，四个镇库武神铸于北宋年间，工艺
复杂，表情夸张。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"luya", 
  "south" : __DIR__"taishi",
  "northwest" : __DIR__"shuyuan",
  "southeast" : __DIR__"shizong",
]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"obj/bei1" : 1,
       ]) );
        
        
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}
