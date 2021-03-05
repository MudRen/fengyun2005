#include <ansi.h>
#define FATEMARK "宿命A/泰山_流星"

inherit ROOM;

void create()
{
  set("short","月观峰");
  set("long",@LONG
巴掌大的峰顶上建有一个小亭子，亭子虽小，但建在这高山之上，也是不易，
日观峰的红日，月观峰的金月都是极好看的景致，每当清风之夜，月高悬其上，美
不胜收，如恰逢秋高气爽之时，持螯赏月，乘风而舞，兴之所致，实在无可比拟。
月观峰再往前行，便是天下武林英豪景仰之地——【无垢山庄】！
LONG
  );
    set("exits",([
	    	"down" : __DIR__"shanfeng",
        	"northup" : __DIR__"yushijie3",
    ]));
    
        set("objects", ([
                __DIR__"npc/mantrainer" : 1,
        ]) );
    	set("outdoors", "taishan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",125);
	setup();
}


void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(3) && !ob->query(FATEMARK)) {
		ob->set(FATEMARK, num);
		tell_object(ob,HIG"\n在流星没入对面山峦前，你默默的在心中许了个愿。\n"NOR);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void init_scenery()
{
        remove_call_out("falling_star");
        call_out("falling_star",1);
}

void falling_star() {
    	object *ppls, room = this_object();
    	function f=(:add_fate_mark:);
    	message("vision", HIW"\n    一道银色星光划过深蓝色的夜空，没入对面山峦的后面。 \n"NOR, room);
    	message("vision", HIC"只听，惊起宿鸟一片。\n"NOR, room);
    	ppls=filter_array(all_inventory(room),(:userp($1) && interactive($1) :));
    	if(sizeof(ppls))
		map_array(ppls,f);
}
