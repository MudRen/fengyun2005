#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
一条猩红的地毯，自门口笔直地铺向远处，其长竟不止十丈。尽头处又是十数
级石阶，阶上又是一重门户。原来小阁楼里连接山腹，外观虽小，里面却是宽容博
大，两壁间灯光辉煌。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gate",
  "south" : __DIR__"datang",
]));
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
    set("objects", ([
        __DIR__"npc/g_wushi" : 2,
    ]) );

	setup();
    create_door("north","door", "黄金门", "south", DOOR_CLOSED);
}
void init()
{
	object me;
	me = this_player();
	if(interactive(me))
	me->set_temp("intime", time());

}

int valid_leave(object me, string dir)
{
	int in_time;
	
	if (dir == "south")
	{
	in_time = me->query_temp("intime");
	me->set_temp("wait_time", time()-in_time);	
	}
	return ::valid_leave(me, dir);
}
