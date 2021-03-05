// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "桃花峰");
        set("long", @LONG
峰顶面积不大，却也不小，一座六角小亭紧靠峰顶的边缘，靠中间则是一个青
砖琉璃瓦的建筑。站在峰顶向下看，是连绵无际的群峰山峦和看不到边际的绿色，
山峰的半腰常年云雾缭绕，温泉犹如颗颗明珠，嵌映在群峰中。不远处隐约可见一
小石桥横跨在山半腰。
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"ciguang",
  "eastdown" : __DIR__"wenquan",
  "southwest"  : __DIR__"taoyuan",
  "westdown" : __DIR__"qingluan",
]));

        set("outdoors", "huangshan");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
