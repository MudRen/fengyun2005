// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "东石坊");
        set("long", @LONG
高大的石刻牌坊，似乎张开巨臂欢迎过往众生，题额“祖源谛本”，一幅对联
“地在天中，四海名山为第一；心传元外，十方法教是祖元”少林之悠久可见一斑，
西面题额“跋陀开创”，记载着当年印僧跋陀首创少林的故事。
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"ent3",
]));
        set("objects", ([
                __DIR__"obj/east_shi" : 1,
                __DIR__"npc/monk3" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",-100);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}
