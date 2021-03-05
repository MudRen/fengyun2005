// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "天上人间");
        set("long", @LONG
千金楼成都分店--天上人间。 一入门，两边都是游廊相接。院中点衬几块
山石，一边种着数本芭蕉；那一边乃是一棵西府海棠，其势若伞，丝垂翠缕，
葩吐丹砂。整个院落富丽堂皇，雍容华贵。门口高挂一块御赐金匾：
		天上人间
LONG
        );
	set("exits",([
  		"west" : __DIR__"nandajie1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}