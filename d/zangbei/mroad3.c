inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山间小路");
        set("long", @LONG
一条曲曲弯弯的小路通向山的深处，寻常的山，寻常的路，不寻常的是路的两
侧栽满了鲜花。玫瑰、桃金娘、风信子、白头翁、水仙以及其它各式各样的花儿，
正在怒放争艳，开遍了整个山地，白的如珍珠，红的似珊瑚，其它黄紫青绿等灿烂
的颜色，配着芬芳的花香、清脆的鸟语、凉爽的和风、淙淙的清流，把这儿点缀成
一座人间乐园。
LONG
        );
        set("exits", ([ 
		"southwest" :   __DIR__"mroad2",
		"north" : 	__DIR__"garden1",
	]));
        set("objects", ([
        
        	__DIR__"npc/butterfly3":	1,
	]) );
	set("item_desc", ([
        	"flower": "山上的花儿开的正灿烂，你忍不住想去摘上（pick）几朵。\n",
		"花儿":  "山上的花儿开的正灿烂，你忍不住想去摘上（pick）几朵。\n",
	]));
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",900);
        set("coor/z",-50);
	set("map","zbeast");
        set("flower",2);
	setup();
}


void init() {
	add_action("do_pick","pick");
}


int do_pick(string arg) {
	
	object butterfly,flower;
	
	if ( arg!="flower" && arg!="花" )
		return notify_fail("你想摘什么？\n");
	if (!query("flower"))
		return notify_fail("花儿已经被摘完了。\n");
	if (butterfly=present("butterfly",this_object()))
		return notify_fail(butterfly->name()+"展翼飞舞，似乎不愿意让你把花儿摘去。\n");
	flower=new(__DIR__"obj/flower2");
	flower->move(this_player());
	message_vision("$N伸手摘下了一朵花儿。\n",this_player());
	add("flower",-1);
	return 1;
}

	
void reset(){
	::reset();
	set("flower",2);
}