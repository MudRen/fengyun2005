// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "碑林");
        set("long", @LONG
此碑大多数记述着少林武学，其中程绍题“[33m少林观武[32m”诗碑，清“[33m西来堂志善
碑[32m”都记述了少林武学的形神所在，习武之人到此无不注目凝神，详细研究，以期
领悟若干。过了东碑林，便是慈云堂。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bei3",
  "east" : __DIR__"ciyun",
]));
        set("objects", ([
                BOOKS"skill/dabei_50" : 1,
                BOOKS"unarmed_50a" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
}
