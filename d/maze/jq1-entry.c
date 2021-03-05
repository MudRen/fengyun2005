// sinny/silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "武堂入口");
    set("long", @LONG
自恩怨堂的密道往下，起初蜿蜒狭窄，只容单人侧身而行，但愈行愈宽，到了 
最后豁然开朗，粗如婴儿臂腕的牛油火烛照得通道亮如白昼，两个金衣铁卫铁枪一 
般笔直站在金漆铜门两侧，一动不动宛如雕塑。这里，便是上官金虹耗巨资建造的 
地下王国，名为武堂，实为训练金钱死士庞大的秘密禁地。
LONG
    );

    set("exits", ([ 
	"eastup" :   	AREA_FY"tang2",
	"down" : 	__DIR__"jq2-entry",
	"east": 	__DIR__"jq1-maze/entry",
      ]));
    set("objects", ([
	__DIR__"npc/jq1-guard4": 2,
      ]) );

	set("NONPC",1);
    set("coor/x",-210);
    set("coor/y",100);
    set("coor/z",-10);
    setup();

}

//	这儿演示 refresh maze,可以用flush来人工reset maze

void	init(){
    add_action("flush_maze","flush");
}


int	flush_maze(){
    object maze_room;
    string flush_msg;

    if (!wizardp(this_player()))
	return 0;

    maze_room=find_object(__DIR__"jq1-maze");
    if (!maze_room) return 1;
    flush_msg=HIW"武堂中骤然刮过一阵狂风，一切似乎又恢复刚才的模样。\n"NOR,
    maze_room->remove_all_players(maze_room,this_object(),flush_msg);
    maze_room->refresh_maze();
    return 1;
}

/*
int valid_leave(object who, string dir) {
    object guard;
    if (dir == "down") {
	if (guard = present("jinqian tiewei",this_object())) 
	    return notify_fail("金衣铁卫把枪一横，挡住了你的去路。\n");
    }
    return ::valid_leave(who,dir);
}
*/