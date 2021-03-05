inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "前厅");
        set("long", @LONG
前面两扇白木板的木门，门边又是两个白衣大汉。门后面是个极大的白木屏凤，
几乎有两丈多高，上面既没有图画，也没有字，但却洗得干干净净，一尘不染。这
儿是万马堂的前厅，是主管公孙断接待一般来客的地方。
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"hall2",
	"south": __DIR__"yard2",
	"east" : __DIR__"pianting",
	]));
        set("objects", ([
        	__DIR__"npc/gongsun": 1,
	]) );
        set("coor/x",-10);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}


int valid_leave(object me, string arg) {
	object ob;
	
	ob=present("gongsun duan",this_object());
	
	if (!ob || REWARD_D->check_m_success(me,"名扬边城")) 
		return 1;
	
	if (userp(me))
	if (arg== "north" || arg=="east") {
		message_vision("$N说：“没有三堂主的邀请，谁都不准入内。”\n",ob);
		return notify_fail("");
	}
	
	return 1;
}