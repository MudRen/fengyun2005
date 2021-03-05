//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIC"望仙乡"NOR);
    set("long", @LONG
花发西园，草薰南陌，韶光明媚，乍晴轻暖清明后。水嬉舟动，禊饮筵开，银塘
似染，金堤如绣。是处王孙，几多游妓，往往携纤手。遣离人、对嘉景，触目伤怀，
尽成感旧。别久。帝城当日，兰堂夜烛，百万呼庐，画阁春风，十千沽酒。未省、宴
处能忘管弦，醉里不寻花柳。岂知秦楼，玉箫声断，前事难重偶。
             空遗恨，望仙乡，一饷消凝，泪沾襟袖。
LONG
    );
    set("exits",
      ([
	"out" : __DIR__"skystreet4",
	"up":  __DIR__"yaoxian",
      ]));
    set("objects",
      ([
	__DIR__"npc/wangxian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
