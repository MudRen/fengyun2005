inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大雪山");
        set("long", @LONG
大雪山的名字叫“念青贡嘎日松贡布”，由三座完全隔开，但相距不远，呈品
字形排列的雪峰组成。北峰[37m仙乃日[32m，南峰[37m央迈勇[32m，东峰[37m夏诺多吉[32m。三座雪峰洁白，
峭拔，似利剑直插云霄。故老相传，转三次三怙主雪山，能消除屠杀八条人马的罪
恶。转十五次神山脚下的冲古寺就相当于念一亿嘛呢的功德。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"mount1",
		"south":  __DIR__"mount2",
		"east":  __DIR__"mount3",
		"westdown": __DIR__"diyugu2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1700);
        set("coor/y",620);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
