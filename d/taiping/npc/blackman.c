#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void goaway();

void create()
{

		set_name("黑衣庄丁",({"blacksuit guard","guard"}));
    	set("title",WHT"李家庄"NOR);
    	set("long", "追巡在庄内的黑衣大汉，衣衫之上鲜血斑驳，他们的眼瞳亦仿如噬血。\n");
		
		set("group","li_guard");
		set("age",40);
		set("combat_exp", 8000000);
        
        set("chat_chance", 50);
        set("chat_msg", ({
			(: goaway :),	
        }) );
        	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
				
		setup();
		carry_object("obj/armor/cloth",
						([	"name": "李家庄庄服",
    						"long": "一件黑色的庄服。\n",
    					 ]))->wear();
}


void goaway()
{
	object ob,me;
	object *inv;
	int i;
	
	if (!environment())	return;
		
	inv = all_inventory(environment());
	
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("sanye")){
    			kill_ob(inv[i]);
    			inv[i]->kill_ob(this_object());
    	}
    }
    
    if (objectp(me= query("mission_target"))) {
    	if (environment(me)== environment()) {
    		kill_ob(me);
    		me->kill_ob(this_object());
		}
	}
	
	if (is_fighting())	return;
	
	environment()->delete("in_mission");		
	message_vision(YEL"$N说：来敌已被击退，大胜大胜！！！$N跳入庄中消失了\n"NOR,this_object());
	
	if (objectp(me)) 
		tell_object(me,HIR"攻打李家庄的行动失败了！！！\n"NOR);
	
	
		
	destruct(this_object());
}


void die(){
	
	object me, middle, young;
	int count;
	object *inv;
	int i;
	
	if (!environment())	return;
		
	inv = all_inventory(environment());
	
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]== this_object())	continue;
		if (inv[i]->query("group")=="li_guard"){
    			::die();			// have a friend alive.
    			return;
    	}
    }
        
	if (!objectp (me = query("mission_target"))) {
		command("say 嘿嘿，正角儿都溜了，某家虽死犹荣！");
		::die();
		return;
	}
	
	if (! (count = query("count")))	{
		command("say bugged no count");
		::die();
		return;
	}
	
	count++;
	
	if (count< 4) {
		command("say 来人、来人。。。顶不住了！");
		message_vision(BLU"\n只听嗖嗖几声，庄内又跳出了几个庄丁。\n"NOR, this_object());
		message_vision(BLU"黑衣庄丁叫道：哪里来的狂徒，欺我李家庄无人么！\n"NOR, this_object());
		environment()->init_mission(count, query("combat_exp"), me);
		::die();
		return;
	}
	
	if (young = present("young man")) {
		message_vision(CYN"\n白衣青年人收起兵刃，冷冷地笑了一声，一闪就跃入了庄中。\n"NOR, young);
		destruct(young);
	}
	
	if (middle = present("middle age man")){
		message_vision(CYN"\n$N说：你速去"NOR+YEL"回报"CYN"三爷，这儿就留给在下了，说罢便跳入了李家庄中。\n"NOR, middle);
		destruct(middle);
	}
				
	if (objectp(me)) {
		if (REWARD_D->riddle_check(me,"喋血鹦鹉")==11)
			REWARD_D->riddle_set(me,"喋血鹦鹉",12);
		if (me->query("marks/quest/李家庄"))
			me->set("marks/quest/李家庄",2);
		environment()->delete("in_mission");		
		tell_object(me,HIR"\n攻打李家庄的计划大获成功，你可速速"NOR+YEL"回报"HIR"武三爷！"NOR);
	}
		
	::die();
}
	