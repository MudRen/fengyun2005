// Disabled by Silencer@fy2005 workgroup

#include <ansi.h>
inherit ITEM;
int Gone();
void create()
{
	set_name("竹筒", ({ "zhu tong", "bamboo" }) );
	set_weight(200);
	set_max_encumbrance(1000);
	set("prep","in");
	set("is_open", 0);
	set("have_snake", 0);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个半旧的小竹筒，竹筒的一头带着淡淡的紫红色。\n");
	    set("value", 1);
	}
	::init_item();
}

/*
int is_container() { return 1; }

void init(){
	if(this_player() == environment()){
		add_action("do_use", "use");	
		add_action("do_open", "open");
		add_action("do_close", "close");
		add_action("do_train", "train");
	}
}

int Gone(){
	set("have_snake", 0);
	delete("owner");
	delete("trained");
	set_name("竹筒", ({ "zhu tong", "bamboo" }) );
	set("long", "一个黄绿色的小竹筒，可以从一头打开。\n");
	return 1;
}

int do_train(string arg){
    	object me, obj;
    	obj = this_object();
    	me = this_player();
    	if (!present(obj,me) || !query("have_snake")){
            return 0;
    	}
    	
    	if (arg != "snake" && arg != "小蛇"){
            return 0;
    	}
    	
    	if (query("trained"))
    		return notify_fail("小蛇已经训练好了。\n");
    		
    	if (me->query_skill("animal-training",1) < 150){
            	return notify_fail("你的训兽术还不够高！\n");
    	}
    	if(query("train_needed") > 0) {
    		message_vision("$N小心的打开竹筒耐心的训练小蛇,小蛇似乎听懂了$N的话。\n",me);
    		add("train_needed", -1);
    	} else {
	    	tell_object(me, "小蛇似乎听懂了你的话，身体蜷了起来，随时准备冲出来。\n");
	    	set("trained",1);
	    	set("owner", me->name()); 
	    	
			REWARD_D->riddle_done( me, "巧做蛇竹筒", 20, 1);
			
    		set_name(MAG"蛇竹筒"NOR, ({ "shetong" }) );
		set("long","一个装有小蛇的竹筒，你可以用它（ａｔｔａｃｋ）。\n");
    		add_action("do_attack", "attack");
    	}
    return 1;
}

int do_attack(string arg){
	object me, obj, target;
	int lvl;
	obj = this_object();
	me = this_player();
	lvl = (int)me->query_skill("animal-training");

	if(!query("trained")){
		return notify_fail("小蛇懒洋洋地没有反应。\n");
	}
	if(!arg) {
		return notify_fail("你要攻击谁？\n");
	}
	
	
	target = find_living(arg);
	if(!target || environment(target) != environment(me)) {
		return notify_fail("这里没有这个人。\n");
	}
	
	if(query("owner") != me->name() ) {
		message_vision(MAG"$N小心的拧开竹筒，只见一道紫光飞出，刹那间不见了踪影。\n"NOR, me);
		Gone();
		return 1;
	}
	
	if (me->is_busy())
		return notify_fail("你现在正忙，没空打开竹筒。\n");
	
	if (target==me)
		return notify_fail("想自杀？\n");
	
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, target)) {
		if (stringp(target->query("NO_KILL")))
			return notify_fail(target->query("NO_KILL"));
		if (stringp(target->query("NO_PK")))
			return notify_fail(target->query("NO_PK"));	
		else 
			return notify_fail("你无法攻击此人。\n");
	}
			
	if(time() - query("time-used") < 3420) {
		return notify_fail("小蛇看起来有些萎靡，过段时间再用吧。\n");
	}
	if(!random(lvl/20)){
		message_vision(MAG"$N拿出一个竹筒，只见一道紫光飞出，刹那间不见了踪影。\n"NOR, me);
		Gone();	
	} else {
		message_vision(MAG"$N悄悄拿出一个竹筒对准"+"$n" +MAG"，只见一道紫光飞向"+"$n" 
+ MAG"，眨眼间又飞了回来。\n"NOR, me, target);
		tell_object(target, HIM"你只觉得身上一麻。\n"NOR);
		if (userp(target)) target->apply_condition("canxia", 10);
			else target->apply_condition("canxia", 30);
		set("time-used", time());
	}
	me->start_busy(3);
	return 1;
}	

int do_close(string arg)
{
        object          me, ob;

        me = this_player();
        ob = this_object();
        if( !arg || (arg != "zhutong" && arg != "zhu tong")) {
                return notify_fail("你要关上什么？\n");
        }
        
        if(query("is_open")){
        	message_vision("$N把$n盖拧紧。\n", me, ob);
        	ob->set("is_open", 0);
        } else {
        	return notify_fail("竹筒是关着的。\n");
        }
        return 1;
}

int do_open(string arg)
{
    	object me, ob;
    
    	if( !arg || (arg != "zhutong" && arg != "zhu tong")) {
    		return notify_fail("你要打开什么？\n");
    	}
    	me = this_player();
    	ob = this_object();
	if(query("have_snake")){
		message("vision", me->name() + "拿着竹筒看看，犹豫了一下又放了回去。\n", 
				environment(me), me);
		tell_object(me, "要是蛇跑了可不好，还是不要开了吧。\n");
		return 1;
	}
	if(query("is_open")) {
		return notify_fail("竹筒已经是打开的。\n");
	} else {
    	message_vision("$N把竹筒打开。\n", me, ob);
    	ob->set("is_open", 1);
    }
    return 1;
}

*/