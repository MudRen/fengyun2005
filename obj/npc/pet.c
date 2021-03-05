#include <ansi.h>
#include <combat.h>
inherit NPC;
void create()
{
	set_name("宠物", ({ "pet" }) );
	set("race", "野兽");
	set("age", 3);
	set("str",5);
	set("cor",5);
	set("int",5);
	set("spi",0);
	set("cps",5);
	set("per",5);
	set("con",5);
	set("agi",5);
	set("dur",5);
	set("fle",5);
	set("tol",5);
	set("no_fly",1);
	set("no_arrest",1);
	set("long", "一只小小小小宠物。\n");
	set("owner","R");
	set("limbs", ({ "头部", "身体", "前心", "後背", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("obedience",2);
	set("combat_exp",100);
	set("deathstamp",1);
        setup();
}
string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+".pet");
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{	
        int i;
        object owner, *enemy;
	int gin,kee,sen,exp;
	set("deathstamp",time());
	exp = (int) query("combat_exp");
	gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
	if(!environment()->query("no_death_penalty"))
		set("combat_exp",exp/10 * 9);
	set("eff_kee",kee);
	set("eff_gin",gin);
	set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);
        if(objectp(owner=query("possessed")))
        {
                enemy = query_enemy();
        	i = sizeof(enemy);
        	while(i--) {
                	if( enemy[i] && living(enemy[i]) ) {
                        	owner->kill_ob(enemy[i]);
                        	enemy[i]->kill_ob(owner);
                }
        }

        }

	save();	
	::die();
}

int heal_up()
{
        if(!objectp(this_object()->query("possessed")))
	{
		save();
		message_vision("$N一闪就不见了。\n",this_object());
	        destruct(this_object());
		return 1;
	}
	set_heart_beat(1);
        return ::heal_up() ;
}

void init()
{
	if(this_player() == query("possessed"))
	{
		add_action("do_order","order");
		add_action("do_modify","modify");
		add_action("do_gongji","gongji");
		add_action("do_teach","teach");
		add_action("do_shape","shape");
	}

}
int do_order(string arg)
{
	int obedience;
	object me = this_player();
	me->add("sen",-5);
	obedience = query("obedience") + me->query_skill("animal-talk", 1)/2;
	set_heart_beat(1);
	if(random(100) < obedience )
		command( "emote " + arg);
	else
		command("emote 很不情愿地哼了一声。");
	return 1;
}
int do_modify(string arg)
{
	string item, msg;
        object me = this_player();
	if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
	return notify_fail("SYNTAX: modify 款项 内容\n");
	if(item == "flee")
	{
		set("env/wimpy", atoi(msg));
                write("ＯＫ\n");
		save();
		return 1;
	}

		
                if(CHINESE_D->check_control(msg))
                return notify_fail("描述不可有控制符！\n");
                if(!CHINESE_D->check_chinese(msg))
                return notify_fail("描述必需是中文！\n");
                if(CHINESE_D->check_space(msg))
                return notify_fail("描述必需不含空格！\n");
                if(CHINESE_D->check_return(msg))
                return notify_fail("描述必需不含回车键！\n");
	me->add("sen",-10);
	switch(item)
	{
	case "desc":
		if(CHINESE_D->check_length(msg) > 100)
		return notify_fail("描述太长！\n"); 
		set("long",msg+"\n");
		write("ＯＫ\n");
		save();
		return 1;
	case "nickname" :
		if(CHINESE_D->check_length(msg) > 20)
                return notify_fail("描述太长！\n");
		set("nickname",msg);
		write("ＯＫ\n");
		save();
                return 1;
	case "title" :
                if(CHINESE_D->check_length(msg) > 10)
                return notify_fail("描述太长！\n");
                set("title",msg);
                write("ＯＫ\n");
		save();
                return 1;
	case "arrive_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("描述太长！\n");
                set("arrive_msg",msg);
                write("ＯＫ\n");
		save();
                return 1;
        case "leave_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("描述太长！\n");
                set("leave_msg",msg);
                write("ＯＫ\n");
		save();
                return 1;

	}
	return notify_fail("你要修改什么？\n");

}


int do_gongji(string arg)
{
	object me,obj;
	me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准战斗。\n");

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
	message_vision(
	sprintf("$N对$n一指，对%s命令道：＂上！＂\n",this_object()->name()),me,obj);
        me->add("sen",-5);
	add("sen",-10);
        if(random(100) > query("obedience")+ me->query_skill("animal-talk", 1)/2 )
        command("emote 很不情愿地哼了一声。");
	else {
		kill_ob(obj);
	}
	return 1;
	
}

int do_teach(string arg)
{
	object me;
	int gin_cost,amount;
        int myskill, itskill;
    	set_heart_beat(1);
	me = this_player();
	if(!myskill = me->query_skill(arg,1))
		return notify_fail("这项技能你好象还不会呢！\n");
	if(arg != "unarmed" && arg != "move" && arg != "dodge")
		return notify_fail("它学不会这项技能的！\n");
	itskill = query_skill(arg,1);
	if(myskill <= itskill)
		return notify_fail(name()+"以嘲笑的目光望着你。\n");
	if((int)me->query("potential")-(int)me->query("learned_points") < 1)
		return notify_fail("你的潜能不够！\n");
	gin_cost = 100/ (int) query_int();
	if((int)me->query("gin") < gin_cost)
		return notify_fail("你显然太累了没有办法教！\n");
	me->receive_damage("gin",gin_cost);
	me->add("potential",-1);
	amount = (int)me->query_int() * (int) query_int()/50;
	if (amount<1)	amount = 1;
	message_vision(sprintf("$N不厌其烦地教$n「%s」。\n",to_chinese(arg)),me,this_object());
        if(random(100) > query("obedience") + me->query_skill("animal-talk", 1)/4)
        command("emote 很不情愿地哼了一声。");
	else 
	{
	        improve_skill(arg,amount);
		message_vision(sprintf("$N似乎真的学会了一些「%s」！\n",to_chinese(arg)),this_object());
	}
	return 1;

}
string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}



int do_shape(string arg)
{	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
	object owner;
	my = query_entire_dbase();
	owner=query("possessed");
	if (owner)
		printf("\n\t\t%s的%s  %s\n\n",owner->name(),my["title"],my["name"]);
	
	printf("精：%s%3d/ %3d %s(%3d%%)\t"NOR"气：%s%3d/ %3d %s(%3d%%)\t"NOR"神：%s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"]
	);		
	printf("主人： %s\t\t经验： %d\t\t杀气： %d\n",
		my["owner"], my["combat_exp"],my["bellicosity"]
		);
        printf("才智： %d\t\t体质： %d\t\t速度： %d\n",
        	query_int(), query_con(),query_agi()
        	);
        printf("凶性： %d\t\t力量： %d\t\t耐力： %d\n",
        	query_cor(), query_str(),query_dur()
        	);        
	at_pt=COMBAT_D->skill_power(this_object(), SKILL_USAGE_ATTACK);
	pa_pt=COMBAT_D->skill_power(this_object(), SKILL_USAGE_PARRY);
	do_pt=COMBAT_D->skill_power(this_object(), SKILL_USAGE_DODGE);
        printf("攻击力： %d\t\t\t\t防御力： %d\n",
        	at_pt+1, pa_pt/2+do_pt/2+1
        	);
        printf("听话程度：%d\n\n",my["obedience"]
        	+((objectp(owner))?owner->query_skill("animal-talk")/2: 0));
	printf("/cmds/usr/skills"->pet_skill(this_object()));
	return 1;
}



void unconcious()
{
die();
}

