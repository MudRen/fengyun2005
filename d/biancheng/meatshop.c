inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "肉铺");
        set("long", @LONG
门口挂着个油腻的招牌，写着：“专卖牛羊猪三牲”。店堂分左右两间，左面
是卖生肉的，地上堆着几片猪腿，柜台后几个伙计正在忙碌，右面的半间墙上一字
吊着十几只香喷喷的烤鸭和烧鸡，老板热情地招呼着每一个进门的顾客。
LONG
        );
        set("exits", ([ 
	"north": __DIR__"road4",
	]));
        set("objects", ([
        	__DIR__"npc/bosshu":	1,
	]) );
	set("coor/x",-30);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}


int valid_leave(object obj, string dir){
	object hu;
	
	if (dir=="north" && obj->query_temp("marks/wanma/胡掌柜杀"))
	if ( hu=present("hu zhanggui",this_object())) {
		tell_object(obj,hu->name()+"气势汹汹地挡住了你的去路。\n");
		return notify_fail("");
	}	

	return 1;
}


void reset(){
	if (present("yunzhong he",this_object()))	return;
	::reset();
}	