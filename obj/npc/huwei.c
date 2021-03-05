#include <ansi.h>

inherit NPC;
void huwei_perform();

//void backattack();
void create()
{

	set_name("侍卫", ({ "huwei"}) );
	set("long", "撼山易，撼岳家军难，这些个血战沙场的精兵儿郎，俱是精忠 
报国，慷慨赴死之辈。。\n");
	
	set("attitude", "friendly");
	set("title",HIY"岳家军"NOR);
	set("nickname",HIG"精忠报国"NOR);
	set("class", "official");
	set("no_fly",1);
	set("no_arrest",1);
	set("no_bounce",1);
	set("max_atman", 300);
	set("atman", 300);
	set("max_mana", 300);
	set("mana", 300);
	
	set("combat_exp", 100000);
	
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("move", 70);
	set_skill("fall-steps", 70);
	set_skill("spear", 70);
	set_skill("hammer", 70);
	set_skill("yue-spear", 70);
	set_skill("liuxing-hammer", 70);
	set_skill("unarmed", 70);
	set_skill("changquan", 70);
	set_skill("force", 150);
	set_skill("manjianghong", 80);
	
	map_skill("force", "manjianghong");
	map_skill("unarmed", "changquan");
	map_skill("hammer", "liuxing-hammer");
	map_skill("spear", "yue-spear");
	map_skill("dodge", "fall-steps");
	map_skill("move", "fall-steps");

	setup();
	carry_object("/obj/armor/armor")->wear();
}

void leave()
{
	object owner, *pros;
	if( environment() ) {
		message("vision",name() + "闪了闪就消失不见了。\n" , environment(), this_object());
	}
	if( objectp(owner=this_object()->query("possessed")) ) {
		owner->add_temp("guard_count", -1);
	  pros = owner->query_temp("protectors");
		pros -= ({ this_object() });
		owner->set_temp("protectors", pros);
	}
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	destruct(this_object());
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_kill","kill");
	add_action("do_dismiss","dismiss");
}

int do_dismiss(string arg)
{
	object who,obj;
	
	if( !arg ) {
		return 0;
	}
	if( !(obj=present(arg, environment())) ) {
		return 0;
	}
	if( obj != this_object() ) {
		return 0;
	}
	who = this_player();
	if( who != query("possessed") ) {
		return 0;
	}
	if( obj->query_temp("weapon") ) {
		tell_object(who, "你不能解散携带着武器的士兵。\n");
		return 1;
	}
	
	if( obj->is_fighting() ) {
    	tell_object(who,"该士兵正在战斗中，无法解散。\n");	
    	return 1;
    }	
	
    if( query("is_leaving") ) {
    	tell_object(who,"该护卫已经被解散了。\n");
    	return 1;
    }
		
	if( who->query("sen") < 200 ) {
		tell_object(who,"你的心神不够，无法对兵士下命令。\n");
		return 1;
	}
	who->receive_damage("sen", 200);
	
	message_vision("$N对$n说道：你竟然连兵器都丢了，还留在这里做甚么，下去吧！\n", who, obj);
	obj->ccommand("inn "+who->query("id"));
	set("is_leaving", 1);
	remove_call_out("leave");
	call_out("leave", 1);
	return 1;
}

void heart_beat()
{
	object leader;
	::heart_beat();

    if( !this_object() ) {
		return;	
	}
	if( !environment() ) {
		return;
	}
	if( query_temp("is_unconcious") || is_busy() ) {
		return ;
	}
	if( query("possessed") ) {
		leader = query("possessed");
		if( environment(leader) != environment() && (!leader->is_ghost()) ) {
			message_vision("$N匆匆离去。\n", this_object());
			this_object()->move(environment(leader));
			message_vision("$N走了过来。\n", this_object());
			delete("leave_room");
		}
	} else {
		if( !query("leave_room") ) {
			set("leave_room", 1);
		} else {
			add("leave_room", 1);
		}
		if( query("leave_room") == 5 ) {
			leave();
		}
	}
}


int do_kill(string arg)
{
	object victim, who;
	
	who = this_player();
	if( !arg ) {
		return 0;
	}
	if( environment()->query("no_fight") ) {
		return 0;
	}
	victim = present(arg,environment());
	if( !victim ) {
		return 0;
	}
	if( !victim->is_character() || victim->is_corpse() ) {
		return 0;
	}
	if( victim == who) {
		return 0;
	}
	if( query("possessed") ) {
		if( !COMBAT_D->legitimate_kill(query("possessed"), victim) ) {
			return 0;
		}
	}
	if( victim->query("possessed") == who && victim->query("id") == "huwei" ) {
		tell_object(who,"你不能杀自己的护卫，否则部下会离心离德的。\n");
		return 1;
	}
	if( victim == query("possessed") && victim->query("possessed") == query("possessed") ) {
		if( who->query("vendetta_mark") != "authority" ) {
			message_vision("$N喝道：“大胆匪徒，竟然敢加害朝廷命官！！”\n", this_object());
			kill_ob(who);
		}
	}
	if( who == query("possessed") && victim->query("vendetta_mark") != "authority" ) {
		message_vision("$N对"+victim->query("name")+"喝道：“大胆匪徒，还不速速束手就擒？”\n",this_object());
		kill_ob(victim);
	}
	return 0;
}

string *lname = ({"张小宪","杨小兴","陆小龙","严小方","何小庆","狄小雷",
    });


// input amount = strategy+ leadership = 500 cap

void invocation(object who, int level)
{
	int i, exp, sen, kee, gin, str, base, add, chance;
	object *enemy, *pros;
		
	i = random(sizeof(lname));
	set_name(lname[i], ({ "huwei" }));
	set("combat_exp", 100000 + who->query("combat_exp")*3/4);
	set("level", F_LEVEL->get_level(query("combat_exp")));	// around 110 cap
	
	if( F_ABILITY->check_ability(who,"3_huwei_lvl",3) ) {
		add = query("level")+ F_ABILITY->check_ability(who,"3_huwei_lvl",3);
		set("combat_exp",F_LEVEL->level_to_exp(add,0));
	}
		
	"/feature/nada"->reset_npc(this_object());

	sen = 200 + (who->query("max_sen")*3/5) + who->query("max_sen")*F_ABILITY->check_ability(who, "huwei_add")/100;
	kee = 300 + (who->query("max_kee")*3/5) + who->query("max_kee")*F_ABILITY->check_ability(who, "huwei_add")/100;
	gin = 200 + (who->query("max_gin")*3/5) + who->query("max_gin")*F_ABILITY->check_ability(who, "huwei_add")/100;
	set("max_sen", sen);
	set("max_kee", kee);
	set("max_gin", gin);
	
	set("str", who->query_str()/2);
	set("force_factor", who->query("force_factor")/2);
	
	base = level/4;	
	set_skill("sword", 30 + base);
	set_skill("parry", 30 + base);
	set_skill("dodge", 30 + base);
	set_skill("move",  30 + base);
	set_skill("unarmed", 30 + base);
	set_skill("fall-steps", who->query_skill("puti-steps",1));
	set_skill("changquan",5 + who->query_skill("changquan",1));
	
	if( random(2) ) {
		set("skill", "spear");
		set("class", "official");
		set_skill("spear", 30+base);
		set_skill("yue-spear", 5+who->query_skill("yue-spear",1)*3/4);
		set_skill("manjianghong", 5+who->query_skill("manjianghong",1));
		map_skill("parry", "yue-spear");
		delete_skill("hammer");
		delete_skill("liuxing-hammer");
		carry_object("/obj/npc/obj/steel_spear")->wield();
	} else {
		set("class", "shaolin");
		set("skill", "hammer");
		set_skill("hammer", 30+base);
		set_skill("liuxing-hammer", 5+who->query_skill("yue-spear",1)*4/5);
		delete_skill("spear");
		delete_skill("yue-spear");
		map_skill("parry","liuxing-hammer");
		carry_object("/obj/npc/obj/steel_hammer")->wield();
	}
	full_me();
	chance = F_ABILITY->check_ability(who, "3_huwei_pfm", 3);
	if( chance ) {
		set("chat_chance_combat", chance);
		set("chat_msg_combat", ({
		(: huwei_perform() :),
      }) );
	}
		
	set("possessed", who);
	pros = who->query_temp("protectors");
	if( sizeof(pros) ) {
		pros += ({ this_object() });
	} else {
		pros = ({ this_object() });
	}
	who->set_temp("protectors",pros);
}


void huwei_perform() {
	if( !query_temp("weapon") ) {
		return;
	}
	if( query("class")== "official" ) {
		ccommand("perform zonghengtianxia");
	} else if( query("class") == "shaolin" ) {
		ccommand("perform fanbei");
	}
//	ccommand("say i am here");
	stop_busy();
}

void unconcious() {
	die();
}

void die()
{
	object owner, *pros, *enemy;
	if( objectp(owner=this_object()->query("possessed")) ) {
		owner->add_temp("guard_count", -1);
		pros = owner->query_temp("protectors");
		pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}
	message_vision("\n$N惨叫一声，倒在地上断气了。\n\n", this_object());
	destruct(this_object());
}

int attack()
{
	object opponent, owner;
	int exp, extra;       
	  
	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		owner = query("possessed");
		if( objectp(owner) ) {
			if( opponent == owner ) {
				this_object()->ccommand("ah");
				message_vision("$N对$n说道：“不知是大人，小将刚才多多冒犯了，还请大人恕罪。”\n", this_object(), owner);
				this_object()->ccommand("escape");
				leave();
				return 1;
			}
		}
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else {
		return 0;
	}
}

/*
int hit_ob(object me, object target, int m) {
		
		if (target->query("combat_exp")> me->query("combat_exp"))
			add("exp_count",1);
			ccommand("say "+ query("exp_count"));
			return 0;
}
*/