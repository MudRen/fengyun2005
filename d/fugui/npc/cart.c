#include <ansi.h>
inherit ITEM;
object owner;

void to_rob(object me);
void check(object ob,object me);
mapping default_dirs = ([
        "north":        "北面",
        "south":        "南面",
        "east":         "东面",
        "west":         "西面",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上面",
        "down":         "下面",
        "enter":        "里面",
        "out":          "外面",
]);

void create()
{
        set_name("镖车", ({ "silver cart", "cart"}) );
        set_weight(300000);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(80000000);
	set("unit", "辆");
	set("long", "一辆黑漆漆的镖车，上面刻着金大帅府的标志。\n你可以（drive cart to <方向>）来押运镖车前进。\n");
	set("closed", 1);
	set("value", 2000);
}

void init()
{
	::init_item();
	add_action("do_open","open");
	add_action("do_close","close");
	add_action("do_drive","drive");
	call_out("destroy",random(900)+900,this_object());
}

int is_container() {return 1;}

int do_close(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
        if(arg != "cart" && arg != "silver cart")
                return notify_fail("你要关上什么？\n");
        if(ob->query("closed"))
        	return notify_fail("镖车已经是关着的了。\n");
       	message_vision("$N把$n门关上了。\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(arg != "cart" && arg != "silver cart")
    		return notify_fail("你要打开什么？\n");
        if(!ob->query("closed"))
        	return notify_fail("镖车已经是开着的了。\n");
	message_vision("$N将$n盖打开。\n", me, ob);
  	ob->set("closed",0);
        return 1;
}

int do_drive(string arg)
{        
        object me,ob, env, obj;
        string item, dir, dest, target;
        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("你要押运什么？\n");
        
        if(me != owner)
        	return notify_fail("你不是镖车的主人！\n");

        if( sscanf(arg, "%s to %s", item, dir) != 2 ||
                item != "cart" && item != "silver cart")
                return command(query_verb()+" "+arg);
                        
        if( me->is_busy() )
                return notify_fail("你现在正忙着哩。\n");

        if ( present("robber",environment(this_player())))
                return notify_fail(HIR"劫匪伸手一拦道：“想跑？没那么容易！”\n"NOR);
        
        if ( present("theif leader",environment(this_player())))
                return notify_fail(HIR"你还是先把毛贼解决了再说吧\n"NOR);
        
        if ( this_player()->is_fighting())
                return notify_fail("你还是先把对手解决了再说吧！\n");
 
        env = environment(me);
        if(!env) return notify_fail("你要去那里？\n");
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
        {
                if( query_verb()=="drive")
                        return notify_fail("这个方向过不去。\n");
                else
                        return 0;
        }
        
        dest = exit[dir];
                        
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("没法向那里押运。\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");

        message_vision("\n$N赶着镖车往" + target + "驶去。\n",me);
        message_vision("镖车隆隆向"+ target + "驶去。\n",me);

        if( ob->move(obj) && me->move(obj)) 
        {
		all_inventory(env)->follow_me(me, dir);
		message_vision("$N赶着镖车驶了过来。\n",me);
		message_vision("镖车隆隆驶了过来。\n",me); 
		me->start_busy(random(3));
        }
        check(ob,me);
	to_rob(me);
        return 1;
}

void check(object ob, object me)
{
        object room;
        string placename;
        room = environment(ob);
        placename = (string) room->query("short");
        if (placename ==(string)me->query_temp("dart_area") 
             && present(me->query_temp("dart_id"), environment(me)) )
           {  
              message_vision(HIY"$N累了个半死，终于把镖运到了地头。\n\n"NOR,me);
              message_vision(HIY+me->query_temp("dart_name")+
                "疑惑的对$N说道：“"+RANK_D->query_respect(this_player())
                +"辛苦了，但是我和金大帅并无交情，\n他葫芦里卖的什么药？”\n\n"NOR,me);
              me->start_busy(2);
              me->delete_temp("dart_area");
              me->delete_temp("dart_id");
              destruct(ob);
              return;
            }  
}

void destroy(object ob)
{
	message_vision(HIR"突然骡子大叫一声发疯似拖着镖车跑了。\n"NOR,ob);
	destruct(ob);
	return;
}

void set_owner(object player)
{	
	owner=player;
}

void to_rob(object me)
{
	object robber,room;
	int i,exp, chance;
	room = environment(this_player());
	me= this_player();
	exp = (int) me->query("combat_exp");
	if (exp >1200000)
		exp = 1200000;
	if( environment(this_player())->query("no_fight") ) return;
	
	if (!this_object()) return;
	
	if( !me->query_temp("meet_poor") && environment(this_object())->query("bandit_out"))
	{
		me->set_temp("meet_poor",1);
		chance=sizeof(me->query("宿命B"))+sizeof(me->query("宿命A"));
		chance = 3+chance/2;
		chance = random(chance);
		if (chance) return;
		message_vision(HIY"突然，几个衣衫褴褛的劫匪从暗处跳了出来，打叫道：“快抢银子啊，抢了就回村！。”\n\n"NOR,this_player()); 
		
		for (i=0;i<2;i++)
		{
			robber=new(__DIR__"poorrobber");
			robber->move(room);
			robber->set("combat_exp",100000 + random(100000));
			robber->set_leader(me);
		}
		robber=new(__DIR__"robleader");
		robber->move(room);
		robber->set("combat_exp",200000 + random(100000));
		robber->fight_ob(me);
		me->fight_ob(robber);
		robber->set_leader(me);
	}
	
	if (environment(this_object())->query("bandit_out")) me->set_temp("meet_poor",1);
	
	if (!random(8))
	{
		message_vision(HIR"突然，几个劫匪从暗处跳了出来，阴笑道：“货和人命都留下来吧！。”\n\n"NOR,this_player()); 
		for (i=0;i<=random(5)+1;i++)
		{
			robber=new(__DIR__"robber");
			robber->move(room);
			robber->set("combat_exp",exp + random(100000));
			robber->kill_ob(me);
			me->kill_ob(robber);
			robber->set_leader(me);
		}
	}
	me->start_busy(2);
	return;
}
