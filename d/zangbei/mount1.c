inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "北侧峰");
        set("long", @LONG
北峰，当地人称之为“仙乃日”，远远望去，像一尊大佛安详地端坐在莲花宝
座上，山峰周围角峰林立，大大小小共三十多座，千姿百态，蔚为壮观。再往北，
山脚下就是著名的冲古寺和天心阁。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"nianqing",
		"northwest":  __DIR__"zhayi",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1700);
        set("coor/y",630);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
