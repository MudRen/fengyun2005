inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "回春阁");
        set("long", @LONG
这是间极大的房子，四面堆满各式各样的药草，占据了屋子十之五大，其余地
方，放了十几具火炉，炉火俱都烧得正旺，炉子上烧着的有的是铜壶，有的是锡锅，
还有的是奇形怪状，说不出各自的紫铜器，每一件铜器中，都有一阵阵浓烈的药香
传出。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"groad4",
	"north" : __DIR__"chunliuju2",
	]));
        set("objects", ([
        	__DIR__"npc/chunliu":1,
	]) );
        set("valid_startroom", 1);
		set("chunliu",1);
        set("coor/x",90);
        set("coor/y",100);
        set("coor/z",0);
	set("map","eren");
	setup();
}



int do_recover(object me, int count){
	
	if (!me || !objectp(me) || me->is_ghost())
		return 0;
	
	if (!environment(me)->query("chunliu")) {
		tell_object(me,RED"你胸中气血翻涌，顿时晕了过去。\n"NOR);
		me->delete("marks/eren/in_cure");
		me->unconcious();
		return 1;
	}
	
	count++;
	
	if (count >= 5)  {
		me->delete("marks/eren/in_cure");
		tell_object(me,YEL"你的伤势终于好了。\n"NOR);
		me->full_me();
		return 1;
	}
	
	if (count)
		tell_object(me,MAG"你觉得伤口上又麻又痒，苦楚略减。\n"NOR);
	call_out("do_recover",10+random(5), me, count);
	return 1;
}