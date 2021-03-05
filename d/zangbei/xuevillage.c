inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "好汉庄");
        set("long", @LONG
白瓦红顶，坐落在这深谷中的好汉庄就是薛家庄，庄主就是当年一百零八招开
天辟地盘古神斧横扫过太行山的薛斌。十五年前，薛斌突然退出江湖，把中原的产
业交给儿子薛大汉，自己带着几个家人到此。岁月不留痕，像它的主人一样，好汉
庄已经垂垂老矣。墙上已现出鱼纹，连油漆都很难掩饰得住，风吹着窗棂时，不停
地“格格”发响。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"valley2",
		"west": __DIR__"xuevillage2",
	]));
        set("objects", ([
		
	]) );
	set("coor/x",-2070);
        set("coor/y",580);
        set("coor/z",20);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
