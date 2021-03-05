#include <ansi.h>
#include <combat.h>
inherit WALL;

string heal();
void create()
{
	set_name("多嘴的大沙袋", ({"sandbag" }) );
	set("race","元素");
	set("long","这是一个大沙袋，被画成无言的样子。
它可以用来测试你的伤害力，还可以揍来出气．．．
主人还可以设置（sandbagset）大沙袋的各种特性。\n");
	set("combat_exp",2000);
//	set_skill("iron-cloth",200);
//	set_skill("steelwall",200);
	set("max_kee",100000);	// 100k,1% = 1khp
	set("max_gin",100000);
	set("max_sen",100000);
	set("practice_dummy",1);
	set_temp("cant_dodge",1);
	set_temp("cant_parry",1);
	set_temp("count",1);
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: heal() :),
    }) );
	set("item_type","t");
	set("size",1);
	set("tax",20);
	set("score_tax",1);
	setup();
}

void init()
{
 	add_action("do_look","look");
 	add_action("do_set","sandbagset");
   	add_action("do_dismantle","dismantle");
}

int do_look(string arg){
	
	string str;
	object ob;
	
	ob = this_object();
	if (!arg || arg!= "sandbag")	return 0;
	
	str = "
这是一个大沙袋，被画成无言的样子。它可以用来测试你的伤害力，
还可以揍来出气．．．主人可以设置（sandbagset）大沙袋的各种特性。\n";

	str+= "特性：等级：" + F_LEVEL->get_level(ob->query("combat_exp")) + "\n";
	
	if (ob->query_temp("apply/armor")) 
		str += "护甲（"+ob->query_temp("apply/armor")+"）\n";
	
	if (ob->query_skill("iron-cloth",1)) 
		str += "有效硬功（"+(ob->query_skill("iron-cloth",1)/2+1)+"）\n";
		
	if (ob->query_skill("dodge",1))
		str += "有效闪避（"+ ob->query_skill("dodge")+"）\n";
		
	if (ob->query_skill("parry",1))
		str += "有效招架（"+ ob->query_skill("parry")+"）\n";	

	if (ob->query_skill("perception",1))
		str += "有效鬼谷之道（"+ ob->query_skill("perception")+"）\n";	

	if (ob->query_temp("count"))
		str += "攻击回合（"+ob->query_temp("count")+"）\n";
	write(str);
	return 1;
}

int do_set(string arg){
	
		object ob,me = this_player();
		int armor;
		
		ob = this_object();
		if (!environment(me)->is_owner(me->query("id")))
			return notify_fail("大沙袋的特性只有主人才能设置。\n");
		if (me->is_fighting() || me->is_busy()) {
			tell_object(me,"你现在正忙着呢。\n");
	   		return 1;
	   	}
	
		if (arg) {
		if (arg == "-reset") {
			ob->delete_temp("apply/armor");
			ob->delete_skill("iron-cloth");
			ob->delete_skill("dodge");
			ob->delete_skill("perception");
			ob->delete_skill("parry");
			ob->delete_skill("jin-gang");
			ob->set("combat_exp",2000);
			ob->set_temp("cant_parry",1);
			ob->set_temp("cant_dodge",1);
			ob->set_temp("cant_percept",1);
			ob->set_temp("is_unconcious",1);
			message_vision(WHT"大沙袋说：复原完毕，恢复到出厂状态。\n"NOR, ob);
			return 1;
		}
	
		if (sscanf(arg,"-armor %d",armor)==1){
			if (armor>0 && armor <= 200) {
				ob->set_temp("apply/armor",armor);
				message_vision(WHT"大沙袋嘟嘟叫了几声，袋子周围出现了一层透明的护甲（+"+armor+"）\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"护甲范围只能在1-200之间。\n");
				return 1;
			}
		}

		if (sscanf(arg,"-iron-cloth %d",armor)==1){
			if (armor>0 && armor <= 400) {
				ob->set_skill("iron-cloth",armor*2-2);
				ob->set_skill("jin-gang",1);
				ob->map_skill("iron-cloth","jin-gang");
				message_vision(WHT"大沙袋嘟嘟叫了几声，袋子上渗出一层坚韧的蝉丝（+"+armor+"）\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"有效硬功范围只能在1-400之间。\n");
				return 1;
			}
		}
		
		if (sscanf(arg, "-dodge %d", armor) == 1) {
			if (armor>0 && armor <= 600) {
				ob->set_skill("dodge",armor*2);
				ob->delete_temp("cant_dodge");
				ob->delete_temp("is_unconcious",1);
				message_vision(WHT"大沙袋嘟嘟叫了几声，飞速旋转起来，令你眼花缭乱（+"+armor+"）\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"有效闪避范围只能在1-600之间。\n");
				return 1;
			}
		}
	
	
		if (sscanf(arg, "-parry %d", armor) == 1) {
			if (armor>0 && armor <= 600) {
				ob->set_skill("parry",armor*2);
				ob->delete_temp("cant_parry");
				ob->delete_temp("is_unconcious");
				message_vision(WHT"大沙袋嘟嘟叫了几声，长出两个弹簧手搓了搓。（+"+armor+"）\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"有效招架范围只能在1-600之间。\n");
				return 1;
			}
		}
		
		if (sscanf(arg, "-perception %d", armor) == 1) {
			if (armor>0 && armor <= 300) {
				ob->set_skill("perception",armor);
				ob->delete_temp("cant_percept");
				message_vision(WHT"大沙袋嘟嘟叫了几声，头上冒出一个闪亮的光环。（+"+armor+"）\n"NOR,ob);
				return 1;
			} else {
				tell_object(me,"鬼谷之术范围只能在1-300之间。\n");
				return 1;
			}
		}

		if (sscanf(arg, "-level %d", armor) == 1) {
			if (armor>=1 && armor <= 150) {
				
				if (ob->query("combat_exp") > F_LEVEL->level_to_exp(armor,0))
					message_vision(WHT"大沙袋嘟嘟叫了几声，忽然瘪下去了几分。（+"+armor+"）\n"NOR,ob);
				else
					message_vision(WHT"大沙袋嘟嘟叫了几声，忽然长大了几分。（+"+armor+"）\n"NOR,ob);
				ob->set("combat_exp", F_LEVEL->level_to_exp(armor,0));
				ob->delete_temp("is_unconcious");
				return 1;
			} else {
				tell_object(me,"大沙袋的体积只能在1和150之间。\n");
				return 1;
			}
		}
		
		if (sscanf(arg,"-turn %d", armor) == 1) {
			if (armor>=1 && armor <=6){
				message_vision(WHT"大沙袋嘟嘟叫了几声，显示出一个大大的"HIR+chinese_number(armor)+NOR+WHT"字\n"NOR,ob);
				set_temp("count",armor);
				return 1;
			}
			else {
				tell_object(me,"大沙袋计算伤害的轮数只能在1-6。\n");
				return 1;
			}
		}
	}
		write (WHT"多嘴的大沙袋说明书	2006 v.1.17"NOR"
=========================================================		
1.功用：测试你的杀伤力和攻击能力：

2.命令：
sandbagset -level num: 设置大沙袋的经验等级为第num级
sandbagset -armor num: 设置大沙袋的护甲(1-200);
sandbagset -iron-cloth num: 设置大沙袋的有效铁布衫（1-400）
sandbagset -dodge num: 设置大沙袋的有效闪避(1-600)
sandbagset -parry num: 设置大沙袋的有效招架(1-600)
sandbagset -perception num: 设置大沙袋的鬼谷之术（1-300）
sandbagset -turn num:	设置大沙袋计算伤害的轮数(1-6)
sandbagset -reset: 大沙袋恢复到原始状态
	
3.说明：在原始状况下，大沙袋总是会被击中的，但是当你设置
它的经验等级、闪避、招架时，大沙袋会做出相应的逃避。

4.已知问题：由于本产品受系统时钟控制，在回合计算时可能有
正负一轮的波动，此问题将在v.5.81中得到解决。
=========================================================\n\n");		
		return 1;
}


string heal()
{
	int sen,gin,kee;
	
	add_temp("amount",1);
	if (query_temp("count")>query_temp("amount")){
		message_vision(CYN"大沙袋晃了晃，摆回原来的位置------"HIR+"第"
			+chinese_number(query_temp("amount"))+"招！\n"NOR,this_object());
		return "";
	}
	delete_temp("annie/damaged_by_mingyue");
	set_temp("amount",0);
	kee = 100000 - query("kee");
	gin = 100000 - query("gin");
	sen = 100000 - query("sen");
	message_vision(CYN"多嘴的的大沙袋晃了晃，摆回原来的位置------"HIR+CYN"最后一招！\n"NOR,this_object());
	message_vision(CYN+name()+"嘟嘟地说：精力损伤"+gin+"点，气血损伤"+kee+"点，心神损伤"+sen+"点。。。复原完毕！\n"NOR,this_object());
	remove_all_killer();
	remove_all_enemy();
	this_object()->full_me();
}


int reset_item_list(object dest);

int do_dismantle(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	object *inv;
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	if (!env)
		return notify_fail("错误#13106。\n");	// 天知道是什么意思...ppl report的时候当search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("家庭用品只能由屋子的主人拆除。\n");
	if (!present("dismantle statue",me))
		return notify_fail("你没有合适的工具以进行拆除。\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("错误#13108。\n");	// 天知道是什么意思...ppl report的时候当search index
	message_vision(CYN"$N一提气，扬起毁灭石像向"+name()+"上砸去，不两下就把"+name()+"砸得稀烂。\n\n"NOR,me);
//	env->add("item_index",-1);	
	inv = all_inventory(ob);
	while (sizeof(inv))
	{
		inv = all_inventory(ob);
		destruct(inv[0]);
	}
	ob->reset_item_list(ob);

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = env->query("item_list/"+lists[i]);
		if (mitem == base_name(ob))
			env->delete("item_list/"+lists[i]);
	}
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));

	env->add("tax",-query("tax")*7);
	env->add("score_tax",-query("score_tax")*100);

	if (env->query("tax")<0)
		env->set("tax",0);	// 防bug
	if (env->query("score_tax")<0)
		env->set("score_tax",0);	// 防bug

	env->save();
	destruct(present("dismantle statue",me));
	destruct(ob);
	return 1;	
}


varargs int receive_damage(string type, int damage, object who)
{
    	int val, fate, amount;
    	int reduction,r_damage, h_damage;

    	
//  if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    	if (damage <0) damage =0;
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

		if ((query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") && who && !query_temp("annie/backfire_damage"))
		{
			who->set_temp("annie/backfire_damage",1);
			set_temp("annie/backfire_msg",1);
			who->receive_damage(type,damage * query_temp("buffup/backfire_amount")/ 100,this_object());
			who->delete_temp("annie/backfire_damage");
			message_vision(query_temp("buffup/backfire_msg"),this_object(),who);
		}
		// annie 07.24.2003

    	if (query("resistance/"+type) || query_temp("resistance/"+type)){
			reduction=query("resistance/"+type) + query_temp("resistance/"+type);
			if (reduction >= 100)	reduction = 100;
			damage = damage - damage * reduction / 100;
		}

    	if( objectp(who) ) set_temp("last_damage_from", who);
    	val = (int)query(type) - damage;
	
//	这个是用来记录NPC的HATE_LIST。	
	if (objectp(who))
	if (!userp(this_object())) {
		h_damage = damage;
		add_hate(who, h_damage);
	}

    // here add for the usage of lifesave potion
    	if ( val < query("max_"+type)/5 && val>0 && is_fighting())
    	if( (time()- query("timer/lifesave"))< 3600 )//最多一个小时
    	{
       		fate = 20 + query("pfm/chunquye_pw");
	    	if( fate + 100 > random(100))
	    	{
			message_vision(RED"\n$N"NOR+RED"强运一口真气，脸上泛出一丝红光，伤势竟然好了大半。\n\n"NOR,
					this_object());
				amount = 4000 + F_ABILITY->check_ability(this_object(),"chunquye_amt")* 300;
				receive_fulling("gin", amount);
				receive_fulling("sen", amount);
				receive_fulling("kee", amount);
	       	    	status_msg("all");   	
	        	delete("timer/lifesave");
	        	tell_object(this_object(),WHT"『落花流水春去也』将你从死亡边缘唤回。\n"NOR);
			return (damage> amount)? (damage- amount): 0 ;
		}
	}
	
	set(type, val);
    	
    	status_msg(type);
    	if (objectp(who))	dmg_msg(type, who);
    	    	
    	set_heart_beat(1);

	if(query_temp("mesmerize")) {		// testing 4.1 new pfm: mesmerize.
		this_object()->stop_busy();
		delete_temp("mesmerize");
		delete_temp("condition_type");
		tell_object(this_object(), YEL"你身上一痛，从迷迷糊糊中清醒了过来。\n"NOR);
	}
	if (who)
		ANNIE_D->debuff(this_object(),"manatwist");

    	return damage;
}

varargs int receive_wound(string type, int damage, object who)
{
    	int val,reduction, fate;
	int r_damage, h_damage, amount;

//  if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
    	if (damage <0) damage =0;
    	if( type!="gin" && type!="kee" && type!="sen" )
        	error("F_DAMAGE: 伤害种类错误( 只能是 gin, kee, sen 其中之一 )。\n");

		if ((query_temp("buffup/backfire") == type || query_temp("buffup/backfire") == "all") && who && !query_temp("annie/backfire_damage"))
		{
			who->set_temp("annie/backfire_damage",1);
			who->receive_wound(type,damage * query_temp("buffup/backfire_amount")/ 100,this_object());
			who->delete_temp("annie/backfire_damage");
			if (!query_temp("annie/backfire_msg"))
				message_vision(query_temp("buffup/backfire_msg"),this_object(),who);
			else
				delete_temp("annie/backfire_msg");
		}

		if (query("resistance/"+type) || query_temp("resistance/"+type)){
			reduction=query("resistance/"+type) + query_temp("resistance/"+type);
			if (reduction >= 100)	reduction = 100;
			damage=damage - damage * reduction / 100;
		}

    	if( objectp(who) ) set_temp("last_damage_from", who);
    	val = (int)query("eff_" + type) - damage;
    
        // here add for the usage of lifesave potion
    	if ( val < query("max_"+type)/5 && val > 0 && is_fighting())
    	if( (time()- query("timer/lifesave"))< 3600 )//最多一个小时
    	{
       		fate = 20 + query("pfm/chunquye_pw");
	    	if( fate + 100 > random(100))
	    	{
				message_vision(RED"\n$N"NOR+RED"强运一口真气，脸上泛出一丝红光，伤势竟然好了大半。\n\n"NOR,
						this_object());
				amount = 4000 + F_ABILITY->check_ability(this_object(),"chunquye_amt")* 300;
				receive_fulling("gin", amount);
				receive_fulling("sen", amount);
				receive_fulling("kee", amount);
		       	status_msg("all");   	
		        delete("timer/lifesave");
		        tell_object(this_object(),WHT"『落花流水春去也』将你从死亡边缘唤回。\n"NOR);
				return (damage> amount)? (damage- amount): 0 ;
			}
		}
        
        //  这个是用来记录NPC的HATE_LIST。	
	if (objectp(who))
	if (!userp(this_object())) {
		h_damage = damage;
		add_hate(who, h_damage);
	}
        
    	set("eff_" + type, val);
    	if( (int)query(type) > val ) set(type, val);
    	
    	status_msg(type);
    	if (objectp(who))	dmg_msg(type, who);
    	
    	set_heart_beat(1);

	if(query_temp("mesmerize")) {		// testing 4.1 new pfm: mesmerize.
		this_object()->stop_busy();
		delete_temp("mesmerize");
		delete_temp("condition_type");
		tell_object(this_object(), YEL"你身上一痛，从迷迷糊糊中清醒了过来。\n"NOR);
	}
	if (who)
		ANNIE_D->debuff(this_object(),"manatwist");
	
    	return damage;
}


void die(){
	
	return;	
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

