// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
#include <ansi.h>
#define FATEMARK "宿命B/泰山_日出"
inherit ROOM;
void create()
{
  	set("short","日观峰");
  	set("long",@LONG
此处是观览日出东海最佳地方，北依悬崖，南临深谷，凉风习习，白云飘浮，
俯览群山若丘，仰观苍穹如幕，每日清晨，一轮红日自东海扶桑树上横空出世，人
高云低，日在脚下，大有一举手可以扪天之势，历代英雄到此，无不为之豪情涌动。
LONG
  );
    	set("exits",([
	    "south" : __DIR__"zhanlu",
    	]));

	set("outdoors", "taishan");
      	set("coor/x",30);
      	set("coor/y",30);
	set("coor/z",120);
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


void sun_rise(int sunrise, int sunrise_stage)
{
	object *ppls;
    	int /*i,*/ j;
    	object ob;
    	function f = (:add_fate_mark:);
    	remove_call_out("sun_rise");
    	ob=this_object();
    	if(sunrise_stage == 0 && random(10)<5)
    	{
        	message("vision", HIW"四周一片云雾茫茫，空气湿的似乎可以拧出水来，你什么都看不清楚。\n"NOR, ob);
    	} else
    	if(sunrise == 0)
    	{
        	switch(sunrise_stage)
        	{
            		case 0:
                		message("vision", RED"\n一弯红色的光芒刚刚探出灰黑色的地平线，霎时间万道霞光洒满了天空。\n"NOR, ob);
                		message("vision", RED"山峦的顶部都被染成红色。 \n\n"NOR, ob);
         			call_out("sun_rise", 5, 0, 1);
                		break;
            		case 1:
                		message("vision", HIR"\n桔红色的太阳缓缓的从地平线上升起，整个大地忽然之间亮了起来。\n"NOR, ob);
                		message("vision", HIR"山间的虫鸟止住了叫声，似在恭迎新的一天的到来。\n"NOR, ob);
                		call_out("sun_rise", 5, 0, 2);
                		break;
            		case 2:
                		message("vision", HIR"\n一轮红日映着天边的彩霞缓缓地从东方升起。\n"NOR, this_object(), ob);
                		message("vision", HIY"\n太阳终于跃出了地平线，大地万物都被渡上了一层淡淡的金色。 \n"NOR, ob);
                		j = NATURE_D->get_season();
                		if (j == 3)
                		{
                    			message("vision", HIY"\n山下的枫叶林也镀上了淡淡的金色，火红的枫叶似霞光流动，变幻着五彩的颜色，\n"NOR, ob);
                    			message("vision", HIY"你迷失在这五彩的世界里。\n"NOR, ob);
		    			ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
                    		    	if(sizeof(ppls))
						map_array(ppls,f);
	                	}
                break;
        	default:
        		return notify_fail("something wrong\n");
        }
    } else
    {
        switch(sunrise_stage)
        {
        	case 0:
                	message("vision", RED"\n厚厚的云层似凝冻著的海浪在你的脚下。东方远处云天相连的地方，好像有一丝红光透现，\n"NOR, ob);
                	message("vision", RED"天空是一片暗蓝。 \n"NOR, ob);
                	call_out("sun_rise", 5, 1, 1);
                	break;
            	case 1:
                	message("vision", HIR"\n转眼间天边出现了一道淡紫色的霞光，霞光不停地变换着紫色、粉紫色、浅红、桔红的色彩。\n"NOR, ob);
                	message("vision", HIR"太阳也露出了红彤彤的小半边脸，红的似火，却没有光亮。\n"NOR, ob);
               		call_out("sun_rise", 5, 1, 2);
                	break;
            	case 2:
	                message("vision", HIR"\n一轮红日映着天边的彩霞缓缓地从东方升起。\n"NOR, ob);
                	message("vision", HIR"\n太阳似乎负着重荷似地一步一步、慢慢地努力上升，到了最后，终于冲破了云霞，跳出了云层，\n"NOR, ob);
                	message("vision", HIR"颜色红得非常可爱。一刹那这个可爱的红色圆球，突然发出耀眼的光亮。\n"NOR, ob);
                	j = NATURE_D->get_season();
                	if (j == 4)
                	{
                    		message("vision", HIR"\n厚厚的白云被染上了五色光彩，光彩不停的流动变换，你深深的沉迷在这变幻着的光的世界中。\n"NOR, ob);
				ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
                    			if(sizeof(ppls))
                    				map_array(ppls,f);
                	}
                	break;
        	default:
        		return notify_fail("something wrong\n");
        }
    }
}
