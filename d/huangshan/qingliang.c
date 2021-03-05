#include <ansi.h>
#define FATEMARK "宿命B/黄山_日出"

inherit ROOM;
void create()
{
        set("short", "清凉台");
        set("long", @LONG
山路曲折，一路奇松、怪石令人陶醉，来到这里，只见一块平坦的巨石向前突
出，形成一块三面凌空的危岩，旁边散落放着一些石块，游人多在这里观看日出。
向四外看白云似海，在你的脚下流淌，露出云海山头恰似蓬莱仙岛，隐约可见一座
座琼楼玉宇。山上奇松怪柏，有的象雄鹰、凌空展翅，有的象仙女、亭亭玉立，美
不胜收。
LONG
        );
    	set("exits", ([
		"southwest" : __DIR__"diezhang",
  		"northwest" : __DIR__"feilong",
  		"east" : __DIR__"shizi",
	]));
	set("item_desc",([
		"rock":	"一块平坦的巨石，可以坐下来歇息一阵（sitdown）。\n",
		"巨石":	"一块平坦的巨石，可以坐下来歇息一阵（sitdown）。\n",
	]));
		
	
    	set("outdoors", "huangshan");
      	set("coor/x",-120);
      	set("coor/y",0);
	set("coor/z",30);
	setup();
}

void init() {
    	add_action("do_sitdown", "sitdown");
    	add_action("do_standup", "standup");
}

void init_scenery()
{
        remove_call_out("sun_rise");
        call_out("sun_rise", 1, random(2), 0);
}

int do_standup()
{
	object me;
    	me = this_player();
    	if(me->is_busy())
	    	return notify_fail("你正在忙！\n");
	if(me->is_fight())
    		return 0;
	if(!me->query_temp("watch_sunrise"))
	     	return 0;
	me->set_temp("watch_sunrise", 0);
    	message_vision("$N站起身来。\n", me);
    	return 1;
}

int do_sitdown(string arg)
{
	object me/*, who*/;
	mixed *local;
	int dayTime/*, j*/;

	me = this_player();
	if(me->is_busy() || me->is_fight())
		return notify_fail("你正在忙!\n");
	
	if(me->query_temp("watch_sunrise"))
        	return notify_fail("你已经坐下了呀？\n");

    	message_vision("$N找了块石头静静地坐了下来。\n", me);
    	me->set_temp("watch_sunrise", 1);
    	
    	if(NATURE_D->is_day_time()) {
  	    return notify_fail("山上清新的空气让你精神一振。\n");
	} else {
		local = NATURE_D->get_current_time();
		dayTime = local[5];
		if(dayTime < 240) {
	    		return notify_fail("四周一片漆黑，你在这寂静的夜中独自坐着。\n");
		} else if (dayTime > 1080) {
	    		return notify_fail("不时传来的虫鸣鸟叫在寂静的夜中传出很远。\n");
		} else if (dayTime > 290 && dayTime < 360) {
		    	return notify_fail("天色已微明，晨风吹来倦意全消。\n");
		} else {
	   	    	tell_object(me, "山中，寂静的夜，别有一番滋味在心头。\n");          	
	    	}
	}
	return 1;
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(2) && !ob->query(FATEMARK)) {
		ob->set(FATEMARK, num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void sun_rise(int sunrise, int sunrise_stage)
{
    	object ob,*ppls;
    	int i, j;
        function f=(:add_fate_mark:);
    	remove_call_out("sun_rise");
    	ob=this_object();
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && $1->query_temp("watch_sunrise"):));

	if(sunrise_stage == 0 && random(10) > 2)
	{
        	message("vision", HIW"四周一片白雾茫茫，你什么也看不清楚。\n"NOR, ob);
	} else
	if(sunrise == 0)
	{
        	switch(sunrise_stage)
        	{
            		case 0:
                		message("vision", RED"\n一弯红色的光芒渐渐从山峦上漫开，初时不很耀眼，但有很强的渲染力。山峦\n的顶部都被染成红色。 \n\n"NOR, ob);
         			call_out("sun_rise", 5, 0, 1);
            		    	break;
            		case 1:
                		message("vision", HIR"\n桔红色的太阳缓缓的从山峦后升起，山谷忽然亮了起来。晨风中喧闹的山鸟止\n了叫声，一群群飞向远方，衬在朝阳里，留下一点点灵动的远影。\n"NOR, ob);
                		call_out("sun_rise", 5, 0, 2);
                		break;
            		case 2:
                		message("vision", HIR"\n一轮红日映着天边的彩霞缓缓地从东方升起。\n"NOR, this_object(), ob);
                		message("vision", HIY"\n太阳终于跃起在峰峦之上，万物都被镀上了一层淡淡的金色。 \n"NOR, ob);
                		j = NATURE_D->get_season();
                		if (j == 1)
                		{
                    			message("vision", HIR"\n满山火红的杜鹃花也镀上了淡淡的金色，看似霞光流动，变幻着五彩的颜色，\n"NOR, ob);
                    			message("vision", HIR"你迷失在这五彩的世界里。\n"NOR, ob);
                    			if(sizeof(ppls))
						map_array(ppls,f);
				}
				for(i=0;i<sizeof(ppls);i++)
				{
                		       	message_vision("$N缓缓站了起来！\n", ppls[i]);
        	                	ppls[i]->set_temp("watch_sunrise", 0);
        	                }
        	        break;
        	default:
        		return notify_fail("something wrong\n");
	        }
    } else {
 	       switch(sunrise_stage)
 	       {
            		case 0:
                		message("vision", RED"\n茫茫云涛如变幻的大海般铺开。东方远处云天相连的地方，浅浅地透出玫瑰紫色，\n"NOR, ob);
                		message("vision", RED"颜色渐亮渐红，象溶解般扩散开来。 \n"NOR, ob);
                		call_out("sun_rise", 5, 1, 1);
                		break;
            		case 1:
                		message("vision", HIR"\n灿烂的红霞上，慢慢出现了一边红亮的圆弧。刹时间云海如染，变得一片璀璨的\n"NOR, ob);
                		message("vision", HIR"火红。云潮卷动，带起层层如红纱般的轻雾。\n"NOR, ob);
               			call_out("sun_rise", 5, 1, 2);
                		break;
		        case 2:
                		message("vision", HIR"\n一轮红日映着天边的彩霞缓缓地从东方升起。\n"NOR, this_object(), ob);
                		message("vision", HIR"\n一轮红日浮动在流光灿烂的云海上，云涛渐渐平息，而不时变换着深红，浅红，\n桔红的色彩。\n"NOR, ob);
                		message("vision", HIR"\n晨雾渐渐散去，化做流霞点缀在天际。\n"NOR, ob);
                		j = NATURE_D->get_season();
                		if (j == 4)
                		{
                    			message("vision", HIW"\n满天的色彩映着山上白色的积雪，有一种说不出的带着妖异的美。\n"NOR, ob);
                    			if(sizeof(ppls))
						map_array(ppls,f);
				}
				for(i=0;i<sizeof(ppls);i++)
				{
                		       	message_vision("$N缓缓站了起来！\n", ppls[i]);
        	                	ppls[i]->set_temp("watch_sunrise", 0);
        	                }

                		break;
        		default:
        			return notify_fail("something wrong.\n");
        	}
    	}
}

int valid_leave(object who,string dir) {
	if(who->query_temp("watch_sunrise")) {
		return notify_fail("你正坐着呢，要站起来（standup）才能离开！\n");
	}
	return 1;
}