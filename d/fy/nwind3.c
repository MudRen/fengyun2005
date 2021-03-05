#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"太和门"NOR);
    set("long", @LONG
通向紫禁城的白玉大道两旁是历尽风雨依旧巍峨耸立的宏伟大殿，皇城就在眼
前，高耸入云的紫色城墙向两旁蜿蜒无尽。这儿就是太和门，重檐歇山顶，立于三
层汉白玉石雕凿的台基上。门前左右两侧各设铜狮一尊，左雄右雌，威武凶悍。雄
狮右足踏绣球，象征权力和天下；雌狮左足抚幼狮，象征子嗣昌盛。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"nwind2",
	"north" : __DIR__"nwind4",
	"northeast" : __DIR__"huantian3",
	"northwest" : __DIR__"huantian1",
      ]));
    set("objects", ([
//	__DIR__"npc/patrol_soldier": 1,
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",160);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}
