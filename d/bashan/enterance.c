// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "黑木门");
    set("long", @LONG
过得劫余岭，就已经走进了江湖中最为神秘的禁地：小巴山。没有人知道是从
什么时候开始，这里一座偌大的佛窟被一群身份不明的怪人所占据，只是自从百多
年前号称佛法武学俱是天下第一的少林戒律院首座天禅大师莫名丧生在此地门前之
后，武林中人都会远远的避开小巴山，避开这扇仿如被九天十地的恶魔所诅咒的黑
木门。
LONG
    );
    set("exits",([
	"east" : "/d/xiangsi/jieyu",
	"west" : __DIR__"maze1/entry",
      ]) );

    set("objects", ([
	"/d/xiangsi/npc/gongsun2" : 1,
      ]));
    set("outdoors", "bashan");

    set("coor/x",5);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}

void generate_maze()
{
    object icecave;
    object maze_room;
    string flush_msg;
    int boss_x,boss_y;

    if (query("maze1/maze"))
	return;
    set("maze1/maze",1);

    maze_room=find_object(__DIR__"maze1");
    if (!maze_room)
	maze_room=load_object(__DIR__"maze1");
    flush_msg=HIR BLK"\n．．．\n\n"NOR,
    maze_room->remove_all_players(maze_room,this_object(),flush_msg);
    maze_room->refresh_maze();

    icecave = this_object();
    boss_x = random(6);
    boss_y = random(6);
    icecave->set("maze1/boss_x",boss_x);
    icecave->set("maze1/boss_y",boss_y);

}
