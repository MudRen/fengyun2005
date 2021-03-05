#include <ansi.h>

inherit ROOM;
#define FATEMARK "宿命B/海市蜃楼"

void create()
{
        set("short", "沙岭");
        set("long", @long
放眼望去，只有黄沙，无边无际，无穷无尽的黄沙，没有水，没有生命，也
没有希望。此处地远人稀，时常出没的沙盗横行猖獗，沙丘上赫然尸身纵横，血
迹未干。更为可怖的是频繁的沙暴，但见黄沙在风暴中卷舞，唯有沿着岭脊往[33m北[32m
才有出路，若是胡乱瞎闯，这一辈子也不一定走得出去。
long
        );
        set("exits", ([ 
		"southwest" :   __DIR__"sandlin",
		"northwest" :   __DIR__"yangguan",
		"west" : 	__DIR__"desert5",
		"east" : 	__DIR__"desert6",
	]));
        set("outdoors", "quicksand");
	set("coor/x",-900);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}



void init_scenery()
{
        remove_call_out("sun_rise");
        call_out("sun_rise",1, random(2), 0);
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(3)) {
		ob->set(FATEMARK,num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}


void sun_rise(int sunrise_stage)
{
	object *ppls;
//  	int i,j;
    	object ob;
    	function f = (:add_fate_mark:);
    	ob=this_object();
    	   	
	switch(sunrise_stage)
	{
    		case 0: message("vision", YEL"刚才还在肆孽的沙暴慢慢平息下来，没有风，一丝风都没有，也没有丝毫声音。\n"NOR, ob);
    			call_out("sun_rise",10,1);
    			break;
    		case 1:
        		message("vision", WHT"\n远远望去，天边的云霞中，隐隐现出城廓的影子。\n"NOR, ob);
        		call_out("sun_rise", 5, 2);
        		break;
    		case 2:
        		message("vision", WHT"\n这城廓的影子越来越清晰，河流潺潺，湖泊如碧，街道房屋佛塔城墙，依稀可辨。\n"NOR, ob);
        		call_out("sun_rise", 5, 3);
        		break;
    		case 3:
        		message("vision", WHT"\n霎那之间，云彩变幻，这些幻像又归於无有。一切仿佛在梦幻之中。。\n"NOR, this_object(), ob);
        		ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
            		if(sizeof(ppls))
					map_array(ppls,f);
                	break;
		default:
			return notify_fail("something wrong\n");
	}
}