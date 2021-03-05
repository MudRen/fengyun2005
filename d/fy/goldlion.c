inherit ROOM;

void create()
{
    set("short", "金狮镖局大院");
    set("long", @LONG
这里几十年来几乎没有什么变化，[33m黑石[32m铺地，大院右边零乱的放着一些大小不
一的[37m石锁[32m，想必是镖局中的趟子手用来练臂力的。左侧则是碗口粗细一人多高的[37m梅
花桩[32m。总镖头查猛是少林俗家弟子出身，虽然教出的徒弟不怎么样，但是他的轻功
和掌法都已经炉火纯青了。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ecloud3",
	"east"  : __DIR__"ghall", 
	"northwest" : __DIR__"gcang",
	"southwest" : __DIR__"gkitchen",
      ]));
    set("objects", ([
	__DIR__"npc/biaoshi" : 1,
	__DIR__"npc/biaoshi1": 1,
      ]) );
    set("outdoors", "fengyun");

    set("coor/x",160);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init(){
    add_action("do_look","look");
    add_action("do_lift","lift");
    add_action("do_lian","lian");
}


int do_lift(string arg)
{
    object me;
    int	s, amount, da;

    if(!arg) 
	return notify_fail("你想举什么？\n");

    if (arg != "石锁" && arg != "stonehammer") 
	return notify_fail("你没法举这个。\n");

    me = this_player();
    if( me->is_fighting() )
		return notify_fail("在战斗中练习，想找死吗！\n");
    if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成，不能练习。\n");
    
    me->start_busy(2);
    s = (int)me->query_skill("unarmed", 1);
    
    if(random(30) && me->query("kar")>10 && s>= 10) {
		if(s >= 40) {
		    message_vision("\n$N拿起一个最大最重的石锁，也不见费了什么劲就把它扔到了几尺高。\n", me);
		    tell_object(me, "这些石锁对你来说已经太轻了。\n");
	
		    if (QUESTS_D->verify_quest(me,"金狮石锁")) {
				if (!me->query_temp("marks/js_lift_start")) {
				    me->set_temp("marks/js_lift_start",1);
				    me->delete_temp("marks/js_lift");
				}
				me->add_temp("marks/js_lift",1);
				if (me->query_temp("marks/js_lift")>=10) {
				    QUESTS_D->special_reward(me,"金狮石锁");
				    me->delete_temp("marks/js_lift");
				    me->set_temp("marks/js_lift_start",1);
				}
		    }
	
		    return 1;
		} 
		if(s >= 20) 
		    message_vision("\n$N嘿的一声，站步蹲桩，把个五十斤的石锁舞的像个车轮子似的。\n", me);
		else 
		    message_vision("\n$N咬紧牙关，小脸涨得通红，颤颤巍巍地把个二十斤的石锁举过头顶。\n", me);
	
		tell_object(me, "你的搏斗之技好象长进了一些。\n");
		amount =  me->query("int") + me->query("str") + me->query_skill("unarmed",1)*25;;
		
		if(amount < 1) amount = 1;
		me->improve_skill("unarmed", amount);
		
		da = 20;
		me->set_temp("last_damage_from","练举重不小心被石锁掉下来砸死了。");
		me->receive_damage("kee", da);
	
		if (QUESTS_D->verify_quest(me,"金狮石锁")) {
		    if (!me->query_temp("marks/js_lift_start")) {
			me->set_temp("marks/js_lift_start",1);
			me->delete_temp("marks/js_lift");
		    }
		    me->add_temp("marks/js_lift",1);
		    if (me->query_temp("marks/js_lift")>=10) {
			QUESTS_D->special_reward(me,"金狮石锁");
			me->delete_temp("marks/js_lift");
			me->delete_temp("marks/js_lift_start");
		    }
		}

    } else {
		message_vision("\n$N嘿的一声，一咬牙举起石锁，\n", me);
		message_vision("\n还没到半腰高，$N手一软石锁掉下来正砸在自己脚背上，真痛！\n", me);
		da = 100;
		me->set_temp("last_damage_from","练举重不小心被石锁掉下来砸死了。");
		me->receive_damage("kee", da);


		if (QUESTS_D->verify_quest(me,"金狮石锁")) {
			if (!me->query_temp("marks/js_lift_start")) {
			    me->set_temp("marks/js_lift_start",1);
			    me->delete_temp("marks/js_lift");
			}
			me->add_temp("marks/js_lift",1);
			if (me->query_temp("marks/js_lift")>=10) {
			    QUESTS_D->special_reward(me,"金狮石锁");
			    me->delete_temp("marks/js_lift");
			    me->set_temp("marks/js_lift_start",1);
			}
	    }

    }
    return 1;
}

int do_lian(string arg)
{
    object me;
    int	s, amount, da;

    if(!arg) 
	return notify_fail("你想练什么？\n");

    if (arg != "梅花桩" && arg!= "zhuang") 
	return notify_fail("你没法练这个。\n");


    me = this_player();
    if( me->is_fighting() )
	return notify_fail("在战斗中练习，想找死吗！\n");
    if( me->is_busy() )
	return notify_fail("你上一个动作还没有完成，不能练习。\n");
    me->start_busy(2);
    s = (int)me->query_skill("move", 1);
    if(random(30) && me->query("kar")>10 && s>=10) {
	if(s >= 40) {
	    message_vision("\n$N拔身而起，飞快地在梅花桩上走了一圈，又潇洒地跳了下来。\n", me);
	    tell_object(me, "你的轻功好象没有什么长进。\n");

	    if (QUESTS_D->verify_quest(me,"金狮梅花桩")) {
		if (!me->query_temp("marks/js_lian_start")) {
		    me->set_temp("marks/js_lian_start",1);
		    me->delete_temp("marks/js_lian");
		}
		me->add_temp("marks/js_lian",1);
		if (me->query_temp("marks/js_lian")>=10) {
		    QUESTS_D->special_reward(me,"金狮梅花桩");
		    me->delete_temp("marks/js_lian");
		    me->delete_temp("marks/js_lian_start");
		}
	    }
	    return 1;
	} 
	if(s >= 20) {
	    message_vision("\n$N拔身而起，飞快地在梅花桩上走了一圈，又潇洒地跳了下来。\n", me);	
	}
	else 
	    message_vision("\n$N小心地跳上了梅花桩，胆战心惊地走了一圈，赶快又跳了下来。\n", me);

	tell_object(me, "你的轻功好象长进了一些。\n");
	amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*25;
	if(amount < 1) amount = 1;
	me->improve_skill("move", amount);
	me->set_temp("last_damage_from","苦练梅花桩，不小心掉下来摔死了。");
	da = 20;
	me->receive_damage("kee", da);

	if (QUESTS_D->verify_quest(me,"金狮梅花桩")) {
	    if (!me->query_temp("marks/js_lian_start")) {
		me->set_temp("marks/js_lian_start",1);
		me->delete_temp("marks/js_lian");
	    }
	    me->add_temp("marks/js_lian",1);
	    if (me->query_temp("marks/js_lian")>=10) {
		QUESTS_D->special_reward(me,"金狮梅花桩");
		me->delete_temp("marks/js_lian");
		me->delete_temp("marks/js_lian_start");
	    }
	}

    } else {
		message_vision("\n$N拔身而起，潇洒地在梅花桩上走了一圈。\n", me);
		message_vision("\n$N哎呀一声从梅花桩上掉了下来。\n", me);
		da = 100;
		me->set_temp("last_damage_from","苦练梅花桩，不小心掉下来摔死了。");
		me->receive_damage("kee", da);

		    if (QUESTS_D->verify_quest(me,"金狮梅花桩")) {
		if (!me->query_temp("marks/js_lian_start")) {
		    me->set_temp("marks/js_lian_start",1);
		    me->delete_temp("marks/js_lian");
		}
		me->add_temp("marks/js_lian",1);
		if (me->query_temp("marks/js_lian")>=10) {
		    QUESTS_D->special_reward(me,"金狮梅花桩");
		    me->delete_temp("marks/js_lian");
		    me->delete_temp("marks/js_lian_start");
		}
	    }

    }
    return 1;
}


int do_look(string arg){
    object me;

    me = this_player();

    if (arg == "石锁") {
	tell_object(me, "大大小小的石锁是用来锻炼臂力的，你可以试着举举看（lift 石锁）。
不过，要想有所得益，要有点搏击的基础（10），运气也不能太坏（11）。\n");
	return 1;
    }

    if (arg == "梅花桩") {
	tell_object(me, "碗口粗细一人多高的梅花桩，是用来练习轻功的（lian 梅花桩）。
不过，要想有所得益，要有点轻功的基础（10），运气也不能太坏（11）。\n");
	return 1;
    }

    if (arg == "黑石") {
	if (this_player()->query_temp("marks/js_cook_mice") < 2) {
	    tell_object(this_player(),"院子的地面是用黑石铺成的。\n");
	    return 1;
	}
	tell_object(this_player(),"院子的地面是用黑石铺成的，上面零零落落掉着些米粒，一直通向大厅。\n");
	this_player()->set_temp("marks/js_cook_mice",3);
	return 1;
    }

    return 0;
}
