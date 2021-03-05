inherit ROOM;
void create()
{
        set("short", "武场");
        set("long", @LONG
这是武场北端，虽然不大，可是各种练武的设施一应俱全，最多的是四尺高的
梅花桩，沿着东墙一溜排开。另有砖石，沙包，可练硬功，地上脚窝深陷，可见众
弟子平时必是极为刻苦，无论是轻功还是硬功都不同寻常。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"wuchang1",
	]));

   	set("item_desc", ([
      		"梅花桩": "
梅花桩由五根离地四尺的木桩组成，呈梅花状分布，是用来练习轻功的（lian）。
不过，要想有所得益，要有点轻功的基础（60），运气也不能太坏（12）。\n",
		"砖石"	: "几块青石大砖，厚约寸徐，是用来练习硬功的（lian）。
不过，不知道你有没有这点能耐。。。。\n",			
   	]));
   	set("outdoors","qingping");
	set("coor/x",-60);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	
}

void init()
{
   	add_action("do_lian", "lian"); 	
}


int do_lian(string arg)
{
   	object me;
   	int	s, amount, da;
  
   	me = this_player();
   	
   	if(!arg) 
   		return notify_fail("你想练什么？\n");
   	
   	if (arg == "砖石") {
	   	if( me->is_fighting() )
	      		return notify_fail("在战斗中练习，想找死吗！\n");
	   	if( me->is_busy() )
	      		return notify_fail("你上一个动作还没有完成，不能练习。\n");

   		message_vision("$N拿起青砖，大喝一声，向自己脑门上砸了上去。\n",me);
   		message_vision("只听砰地一声．．．．．．\n",me);
   		me->unconcious();	
 		return 1;   		
   	}
   	
   	if (arg == "梅花桩" || arg == "zhuang") {  		 	
	   	
	   	if( me->is_fighting() )
	      		return notify_fail("在战斗中练习，想找死吗！\n");
	   	if( me->is_busy() )
	      		return notify_fail("你上一个动作还没有完成，不能练习。\n");
	   	me->start_busy(2);
	   	s = (int)me->query_skill("move", 1);
	   	if(random(30) && me->query("kar")>11) {
		      	if(s >= 75) {
		        	message_vision("\n$N拔身而起，飞快地在梅花桩上走了一圈，又潇洒地跳了下来。\n", me);
		         	tell_object(me, "你的轻功好象没有什么长进。\n");
		        
			        if (QUESTS_D->verify_quest(me,"清平梅花桩")) {
			      		if (!me->query_temp("marks/qp_lian_start")) {
			      			me->set_temp("marks/qp_lian_start",1);
			      			me->delete_temp("marks/qp_lian");
			      		}
			      		me->add_temp("marks/qp_lian",1);
			      		if (me->query_temp("marks/qp_lian")>=10) {
			      			QUESTS_D->special_reward(me,"清平梅花桩");
			      			me->delete_temp("marks/qp_lian");
			      			me->delete_temp("marks/qp_lian_start");
			      		}
			      	}
		         	return 1;
		      	} 
		      	if(s >= 60) 
		               	message_vision("\n$N拔身而起，飞快地在梅花桩上走了一圈，又潇洒地跳了下来。\n", me);
		        	
		      	else 
		         	message_vision("\n$N小心地跳上了梅花桩，胆战心惊地走了一圈，赶快又跳了下来。\n", me);
		      
		      	da = 20;
		      	me->set_temp("last_damage_from","苦练梅花桩，不小心掉下来摔死了。");
		      	me->receive_damage("kee", da);
		      	
		      	if (s>=60)
		      	{
		      		tell_object(me, "你的轻功好象长进了一些。\n");
		      		amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*25;
		      		if(amount < 1) amount = 1;
		      		me->improve_skill("move", amount);
			}
		      	if (QUESTS_D->verify_quest(me,"清平梅花桩")) {
		      		if (!me->query_temp("marks/qp_lian_start")) {
		      			me->set_temp("marks/qp_lian_start",1);
		      			me->delete_temp("marks/qp_lian");
		      		}
		      		me->add_temp("marks/qp_lian",1);
		      		if (me->query_temp("marks/qp_lian")>=10) {
		      			QUESTS_D->special_reward(me,"清平梅花桩");
		      			me->delete_temp("marks/qp_lian");
		      			me->delete_temp("marks/qp_lian_start");
		      		}
			}
		      	
		      	
	   	} else {
	      		message_vision("\n$N拔身而起，潇洒地在梅花桩上走了一圈。\n", me);
	      		message_vision("\n$N哎呀一声从梅花桩上掉了下来。\n", me);
	      		da = 100;
	      		me->set_temp("last_damage_from","苦练梅花桩，不小心掉下来摔死了。");
	      		me->receive_damage("kee", da);

						        
			        if (QUESTS_D->verify_quest(me,"清平梅花桩")) {
			      		if (!me->query_temp("marks/qp_lian_start")) {
			      			me->set_temp("marks/qp_lian_start",1);
			      			me->delete_temp("marks/qp_lian");
			      		}
			      		me->add_temp("marks/qp_lian",1);
			      		if (me->query_temp("marks/qp_lian")>=10) {
			      			QUESTS_D->special_reward(me,"清平梅花桩");
			      			me->delete_temp("marks/qp_lian");
			      			me->delete_temp("marks/qp_lian_start");
			      		}
			      	}

	        }
	   	return 1;
	}
	return notify_fail("你没法练这个。\n");
}