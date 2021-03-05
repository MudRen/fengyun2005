inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山脚");
        set("long", @LONG
蓝天下，仙乃日洁白的雪峰巍然耸立于茫茫林海上，银光闪烁，南面的千仞绝
壁尽收眼底。继续上行，至扎佐拥郁，又名牛角沟，此地森林茂密，溪流潺潺。溪
侧有岩洞名神仙洞，在此小憩，扔石击打神仙洞石岩，发出钟鸣般的回声，故又称
石钟岩。
LONG
        );
        set("exits", ([ 
		"southeast" : __DIR__"mount1",
		"north":  __DIR__"temple1",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
		"石钟岩":	"扔石击打神仙洞石岩，发出钟鸣般的回声，故又称石钟岩。\n",
		"神仙洞":	"扔石击打神仙洞石岩，发出钟鸣般的回声，故又称石钟岩。\n",
	]));
	set("outdoors", "zangbei");
        set("coor/x",-1710);
        set("coor/y",640);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
