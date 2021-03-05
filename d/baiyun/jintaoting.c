//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "惊涛亭");
    set("long", @LONG
这一处地方相当宽敞，左右两侧和後面都是更高的石壁，而竟然在此石壁之中，
悬空建了这一惊涛亭，亭的下方便是汹涌彭湃的海浪激流，而石壁也终年受海水侵蚀
而千疮百孔，青苔密布。惊涛亭倚海而建，因海而险，但凡海潮来时，据说白云城主
便会亲临至此观潮数日，年年如此。
LONG
    );
    set("exits",
      ([
	"northdown" : __DIR__"pailangya",
	"southeast" : __DIR__"jianlin",
      ]));
    set("objects",
      ([
	__DIR__"npc/xiu3" : 1,
	__DIR__"npc/xiu4" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-40);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}
