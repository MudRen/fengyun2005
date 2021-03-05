#include <ansi.h>

inherit NPC;

string player_env(string name, object me);
string *tour_room = ({  "view/d/huashan/fupi",
						"view/d/huashan/lianhua",
						"猎鹰向东飞去。\n",
						"view/d/huashan/shanlu2",
						"view/d/huashan/lianhua",
						"猎鹰向南飞去。\n",
						"view/d/huashan/zhenyue",
						"view/d/huashan/lianhua",
						"猎鹰向西飞去。\n",
						"view/d/huashan/sheshen",
						"猎鹰收起翅膀，像块石头般向舍身崖下坠落，将近山脚时，又突然飞了起来。\n",
						"view/d/chenxiang/chenxiang3",
						"view/d/chenxiang/cx2",
						"猎鹰向西飞去，越飞越远。\n",
						"view/d/chenxiang/cxcenter",
						"view/d/chenxiang/cxs3",
						"猎鹰向西飞去，越飞越远。\n",
						"view/d/wolfmount/bigstage",
						"view/d/guanwai/shudao2",
						"view/d/guanwai/shudao2",
						"view/d/guanwai/shudao1",
						"猎鹰向西飞去，越飞越远。\n",
						"view/d/guanwai/hutiao",
						"view/d/guanwai/yuema",
						"view/d/guanwai/yuema",
						"猎鹰时高时低，沿着江面盘旋。\n",
						"view/d/guanwai/river",
						"猎鹰似乎被一双无形的手拉住，忽然向下一沉。\n",
						"view/d/guanwai/river",
						"猎鹰拍打着翅膀，挣扎着向上飞高了几尺。\n",
						"view/d/guanwai/river",
					});

void create()
{
    	set_name(HIC"苍鹰"NOR, ({ "hawk" }) );
    	set("race", "飞禽");
    	set("age", 1);
    	set("gender", "雄性");
    	set("long","
一只勾嘴利爪的苍鹰。它一双凶猛锐利的眼睛正盯着你看，毫无半分退缩
之意，如果你有驯兽之术，可以试着训练它（train），然后便可以用它来
观察周围的地形（spy）\n");
    	
    	set("attitude","peaceful");
    	set("weight", 3000);
		set("agi", 40);
		set("per",30);
		
		set("resistance/kee",100);
		set("resistance/gin",100);
		set("resistance/sen",100);
		
		set("no_drop",1);
		set("combat_exp", 70000);
  
		setup();
}


void init() 
{
	::init();
	if (userp(environment()))
		add_action("do_train","train");
		add_action("do_spy","spy");
		add_action("do_drop","drop");
}

int do_drop(string arg)
{
	object me,hawk;
	hawk = this_object();
	me = this_player();
	
	if (arg != "hawk" && arg !="苍鹰" && arg!="trained hawk"
		&& arg!= "猎鹰")
	{
		return 0;
	}
	
	message_vision("苍鹰腾身而起，在空中盘旋几圈，转瞬飞去。\n",me);
	destruct(hawk);
	return 1;
}

int do_train(string arg)
{
	object me,hawk;
	hawk = this_object();
	me = this_player();

	if (!arg)
		return notify_fail("你要训练什么？\n");
		
	if (arg != "hawk" && arg != "苍鹰")
	{
		return notify_fail("你不能训练这个东西。\n");
	}
	
	if (hawk->query("marks/trained"))
		return notify_fail("苍鹰已经被驯服了。\n");
			
	if (me->query_skill("animal-training",1) < 200)
	{
		message_vision("
$N开始训练$n，
$N解开$n脚上的铁链，
$n振翅向天空盘旋了几圈，消失的无影无踪。\n\n",me,hawk);
		tell_object(me, "看来你的驯兽术等级还太差（需200级）\n");
		return 1;
	}
	message_vision("\n$N耐心的训练$n,$n朝$N点点头，似乎听懂了$N的话，
$N解开$n脚上的铁链，$n振翅向天空盘旋了几圈又落在了$N的肩上。\n\n",me,hawk);

	set("marks/trained",1);
	set_name(HIC"猎鹰"NOR, ({ "hawk" }) );
    	set("long","一只听话的猎鹰，它可以帮你侦察（SPY）情况。");
	add_action("do_spy","spy");
	return 1;
}


int do_spy()
{
	object hawk,me,target;
	hawk = this_object();
	me = this_player();
	
	if (!hawk->query("marks/trained"))
		return notify_fail("苍鹰还未被驯服，放了就飞跑了。\n");

	if (!environment(me)->query("release_hawk"))
		return notify_fail("猎鹰刚被驯服，最好是到它熟悉的环境中去放飞。\n");
	
	if (environment(me)->query("release_hawk")==2)
		return notify_fail("这个，偷了猎鹰还回到这里来，好像胆子也太大了些吧。\n");
			
	hawk->move(VOID_OB);		
	message_vision(CYN"$N解开猎鹰脚上的铁链，猎鹰振翅向天空中飞去。。。
	
	
山谷间白雾缭绕，

猎鹰时而疾速地斜着翅膀降落下去，

时而又一动不动，随着气流平展着宽阔的两翼在空中翱翔，

	\n\n"NOR, me);
	
	call_out("do_tour",1, me, 0);
	return 1;
}



void do_tour(object me, int count)
{
	object ob;
	ob=this_object();
	if (!me)
		return;
	
	if (tour_room[count][0..3] == "view")
		tell_object(me, player_env(tour_room[count][4..sizeof(tour_room[count])-1],me)+"\n");
	else
		tell_object(me, CYN"\n"+tour_room[count]+"\n"NOR);
	
	if(++count==sizeof(tour_room))
	{
		message_vision(CYN"猎鹰挣扎片刻，悲鸣一声，终于向旋涡中心坠下，
		
		
		 。。。。。。。\n\n"NOR,me);	
		
		REWARD_D->riddle_done(me,"驯鹰华山", 50, 1);
		REWARD_D->riddle_set( me, "生死怒江", 1);
		
		destruct(this_object());
		return;
	}
	else call_out("do_tour",2,me,count);
	return ;
}


string player_env(string room_name, object me) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	if (!(env = find_object(room_name)))
		env = load_object(room_name);
	
	if (!env)	{
		tell_object(me, " BUG, report to wizard please\n");
		return "";
	}
	
	str = "";
	
	str += sprintf("%s \n",env->query("short"));
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),

	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	
	return str;
}

