// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
#define FATEMARK "宿命B/黄山_佛光"
inherit ROOM;
void create()
{
        set("short", "光明顶");
        set("long", @LONG
光明顶是第二高峰，因为多次出现佛光，所以被称为光明顶，光明顶上起伏平
缓，面积广大，古人曾形容它“形若覆巢，旁无依附，秋水银河，长空一色”。如果
机缘巧合，可以在这里看见难得一遇的佛光。
LONG
        );
	set("exits", ([
  		"south" : __DIR__"feilai",
  		"eastup" : __DIR__"lianhua",
  		"southwest" : __DIR__"paiyun",
  		"north" : __DIR__"sanhua",
	]));

        set("outdoors", "huangshan");
      set("coor/x",-90);
      set("coor/y",-10);
	set("coor/z",30);
	set("objects", ([
//        __DIR__"npc/monkey1" : 1,
                        ]) );


	setup();
}

void init_scenery()
{
/*	object me;
    	int i, dayTime;
    	mixed *local;
	add_action("do_jump", "jump");
    	me = this_player();
    	local = NATURE_D->get_current_time();
    	i = NATURE_D->get_season();
    	dayTime = local[5];
// around 3pm spring or summer afternoon have chance to see foguang
	if ( i != 1 || i != 2)
    		return;
	if(query("start_foguang"))
    		return;
	if (!random(10) && dayTime > 840 && dayTime < 960)
	{
        	set("start_foguang", 1);
        	me->set_temp("foguang", 1);
  */      	remove_call_out("foguang");
        	call_out("foguang", random(6) , 0);
    //	}
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("foguang"))
	{
    		me->delete_temp("foguang");
//    		delete("start_foguang");
    	}
    	return 1;
}

void foguang(int stage)
{
    	object *ppls, ob;
    	int i;
    	ob=this_object();
    	remove_call_out("foguang");
	ppls=filter_array(all_inventory(ob),(:interactive($1) && userp($1):));
    	if(stage == 0 && random(30) <25)
    	{
        	message("vision", HIW"     一片云彩缓缓地从峰顶飘过。\n"NOR, this_object());
    	} else
    	{
        	switch(stage)
        	{
        		case 0:
            			message("vision", HIW"\n         云缓缓飘了过来，渐渐在山峰边汇成了一片云海。\n\n"NOR, ob);
            			message("vision", WHT"云海无边无际，广阔得仿佛一直可以延伸到天上。阳光斜照，阵风吹过，翻滚的云涛\n"NOR, ob);
            			message("vision", WHT"比真实的海浪轻柔许多，却也平添了几分迷幻。\n"NOR, ob);
				for(i=0;i<sizeof(ppls);i++)
				{
      	    				message_vision("\n$N慢慢向崖边靠去。\n",ppls[i]);
      	    				tell_object(ppls[i],"\n云海变换莫测，你不由得想靠近仔细看看。\n");
      	    			}
         			call_out("foguang", 5, 1, ob);
            			break;
        		case 1:
	            		message("vision", HIC"\n云海中的有什么东西吸引了你的目光，竟然是一个人的影子。\n"NOR, ob);
            			message("vision", HIY"只见那影子逐渐的清晰了起来，在周围形成了一个巨大的彩色光环。\n"NOR, ob);
            			call_out("foguang", 5, 2, ob);
            			break;
        		case 2:
            			message("vision", HIM"\n你仔细看时，只看到五彩光环浮于云际。光环之中分明是自己的身影。\n"NOR, ob);
            			message("vision", HIM"影随人移，分毫不差。\n"NOR, ob);
            			message("vision", "\n迷茫中你似乎再向前移动。。。。\n", ob);
            			//至少2个人一起看
            			if(sizeof(ppls)<2)
            				break;
            			i=random(sizeof(ppls));
            			message_vision("\n$N面带迷茫神情，直向悬崖边走去。\n",ppls[i]);
            			//我们挑选一位幸运者，接受佛祖的召唤......
            			ppls[i]->start_busy(4);
            			ppls[i]->set_temp("foguang",1);
            			if (!ppls[i]->query(FATEMARK) )
            				call_out("jump", 3, ppls[i]);
            			else
            			{
            				if (random(10) > 5)
            				{
            					call_out("jump", 3, ppls[i]);
                			} else
                			{
                    				call_out("wake", 3, ppls[i]);
                			}
            			}
            			break;
        		default:
        			return notify_fail("something wrong\n");

        }
    }
}
void wake(object watcher)
{
    	message_vision("\n一阵山风吹过，$N倏然惊醒，距离悬崖不到一步之遥，$N惊出一身冷汗。\n", watcher);
	watcher->delete_temp("foguang");
}

int jump(object watcher)
{
	int num = 1 + random(10);
	if( environment(watcher)!=this_object()) return 1;
	if(!watcher->query_temp("foguang")) return 1;//没有嘛，就return好了
	if (watcher->query("cps") < 10)
	{
    		message("vision", "\n你身不由己纵身往崖下跳去！\n", watcher);
   		message("vision","\n" + watcher->name() + "神色一片迷茫，纵身往崖下跳去！\n",
  				this_object(), watcher);
		watcher->set("宿命B/黄山_佛光", num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				watcher->name(1), geteuid(watcher), ctime(time()) ));
		watcher->start_busy(4);
		if(random(watcher->query("kar"))>10)
	 		call_out("bird", 2, watcher);
	 	else {
	 		watcher->set_temp("last_damage_from","在黄山坠崖身死。\n");
	 		watcher->die();
	 	}	
    	} else {
		message("vision", "\n一阵山风吹来，你神志略微清醒，距离悬崖一不到一步之遥，不远处的五彩光环似乎\n", watcher);
		message("vision", "在引诱你往那里走。你可以选择跳或不跳。（ｊｕｍｐ）\n", watcher);
		message("vision", "\n一阵山风吹来，" + watcher->name() + "神志清醒了过来。\n", this_object(), watcher);
		watcher->set_temp("佛光跳崖", 1);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) 得到"+FATEMARK+" "+num+"。 %s \n",
				watcher->name(1), geteuid(watcher), ctime(time()) ));
	}
    	watcher->delete_temp("foguang");
}

int do_jump()
{
	object me;
	me = this_player();
	if(me->query_temp("佛光跳崖"))
	{
		me->delete_temp("佛光跳崖");
		message_vision("$N纵身向崖下跳去！\n", me);
		me->set("宿命B/黄山_佛光", 1+random(10));
		me->start_busy(4);
		call_out("bird", 2, me);
		return 1;
	}
	return 0;
}

void bird(object me) {
	object room;
	string target;
	int i;
	string *rooms = ({  AREA_HUANGSHAN"jiyu",
//	                    AREA_XINJIANG"sichou2",
//	                    AREA_QUICKSAND"desert3",
//	                    AREA_QUICKSAND"quicksand4",
	});
	message("vision", "\n穿过五彩光环，你向下坠去，耳边是呼呼的风声，眼前一片白雾，你什么都看不到。\n", me);
	message("vision", "你脑子里一片空白。\n", me);
	message("vision", "突然间，你的头顶传来急速的羽毛鼓动的声音，接着肩膀上传来一阵剧痛，\n", me);
	message("vision", "你感到下坠的趋势顿了一下。\n\n", me);
	i=sizeof(rooms);
	target = rooms[random(i)];
	room = find_object(target);
	if(!objectp(room))
		room= load_object(target);
	me->move(room);
    	me->unconcious();
	message("vision", "\n一只巨鸟从你掠过，一团黑乎乎的东西从空中落下。\n", environment(me),me);
}
