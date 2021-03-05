#include <ansi.h>
inherit NPC;
void use_poison();

void create()
{
    	set_name(MAG"小蛇"NOR, ({ "snake", "little snake" }) );
    	set("race", "蛇类");
    	set("age", 1);
    	set("gender", "雄性");
    	set("long", "一条全身紫红色的小蛇，三角形的脑袋上有几道黑色的斑纹。
看来如果想抓它可要小心些。（ｃａｔｃｈ）\n");
    	set("attitude","peaceful");
    
	set("weight", 300);
	set("combat_exp", random(100000));
    	set("chat_chance_combat", 10);
    	set("chat_msg_combat", ({
    		(: use_poison :),
    	}));
    	setup();
}


void init() {
    	::init();
	add_action("do_catch", "catch");
	if(this_player() == environment()){
		add_action("do_insert", "insert");
	}
}

void use_poison()
{
    	object *enemy, ob;
    	string msg;

    	enemy = query_enemy();
    	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	message_vision(MAG"只见一道紫光飞起，冲向$N。\n"NOR, ob);
    	tell_object(ob,"你只觉得腿上一麻，一阵寒气顺着经脉流走全身。\n");
    	ob->receive_wound("kee",50,this_object());
    	ob->apply_condition("canxia", 
    		(int)this_player()->query_condition("canxia")+ random(3)+3);
}


int do_insert(string arg){
	object obj, me, cont;
	string Sitem, Titem;
	me = this_player();
	
	if(!arg) {
		return notify_fail("你要把小蛇放进哪里？（ｉｎｓｅｒｔ　ｓｎａｋｅ　ｉｎ　ｘｘｘ）\n");
	} 
	if(sscanf(arg, "%s in %s", Sitem, Titem) == 2);
	else {
		return notify_fail("你要把小蛇放进哪里？\n");
	}
	if(Sitem != "snake") {
		return 0;
	}	
	if( Titem != "zhutong" && Titem != "zhu tong") {
		message("vision", me->name() + "拿着小蛇犹豫了一下，又放了回去。\n", environment(me), me);
		return notify_fail("这似乎不是一个很好的主意吧？\n");
	} else {
		if(obj = present("zhu tong", me)){
			if(obj->query("have_snake")){
				return notify_fail("里面已经有蛇了。\n");
			} else if(obj->query("is_open")){
				message_vision(MAG"\n$N把小蛇对准竹筒，只见一道紫光窜入竹筒。$N仔细的把竹筒拧上。\n"NOR, this_player());
			} else {
				message_vision(MAG"$N把竹筒拧开，把小蛇对准竹筒，只见一道紫光窜入竹筒。$N仔细的把竹筒拧上。\n"NOR, me);
			}
			obj->set("is_open", 0);
			obj->set("have_snake", 1);
			obj->set("long", "一个黄绿色的小竹筒，里面有一条小蛇。\n");
			obj->set("train_needed", random(10));
			obj->add_action("do_train", "train");
			destruct(this_object());
		} else {	
			return notify_fail("你没有这样东西吧？\n");
		}
	}
	return 1;
}

int do_catch(string arg) {
	object me, obj;
	
	me = this_player();
	obj = present("little snake", environment(me));
	if(!arg || (arg != "snake" && arg != "小蛇")) {
		return 0;
	}
	if(!present("little snake", environment(me))){
		return 0;
	}
	message_vision("\n$N伸出手去想捉住小蛇，只见小蛇的背拱起，像箭一样冲向$N。\n", me);
	if(!random(3) && me->query("agi")>= 36){
		message_vision(YEL"$N飞快的出手准确的捏在小蛇的三寸之上。\n"NOR, me);
		message_vision(WHT"刹那间，小蛇的身体软了下来，$N仔细的把小蛇收起。\n"NOR, me);
		tell_object(me, "最好想想把小蛇放在那里。（ｉｎｓｅｒｔ　ｓｎａｋｅ　ｉｎ　ｘｘｘ）\n");
		obj->move(me);
		call_out("Wake", 30);
	} else {
		tell_object(me, WHT"你感觉到手上突然传来麻痛的感觉，一阵寒气顺着经脉流走全身。\n"NOR);
		message_vision("小蛇从$N身边掠过，消失不见了。\n", me);
		me->apply_condition("canxia", 10);
		environment(me)->set("have_snake", 1);
		destruct(obj);
	}
	return 1;
}

void Wake() {
    	object container;
    
    	container = environment(this_object());
    	if(container->name() != "竹筒" && userp(environment(this_object()))) {
		tell_object(environment(this_object()), WHT"你突然感到一阵麻痛，只觉得寒气顺着经脉流走全身。\n"NOR);
		environment(this_object())->apply_condition("canxia", 10);
    	destruct(this_object());
    }
}
