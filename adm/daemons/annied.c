// annied.c
// annie 07.2003
// dancing_faery@hotmail.com

// 處理各種buff的監測輿實行,提供list,提供debuff能力

	/* struct mapping buff:
	object caster,
	object who,
	string type,	---- BUFF的种类，这是用来检验的关键参数。

	提升攻防性能的参数：

	powerup(dodge/atk)		dodgeup		atkup
	powerup2(damageup/armorup)	damageup	armorup
	parryup

	defdown(-parry/dodge)
	powerdown(-dodge/atk)
	pseudo-busy (具有被busy的parry*2/5,dodge*2/5 同时atk*2/3特点,但是仍然可以出招,给攻击性门派)

	提升自身属性的参数：
	moveup			ironup (金刚类）
	strup			cpsup

	haste			slow		berserk		counter(反击)
	evade			criticalup

	特种功能的参数：
	feat（41特有）	damageshield	prtshield	vampiric
	fastrecover 	forcefeat
	lockup(no pfm etc)		freeze		blocked		no_abs	mermorize
	blind		lowresist	lockfield   	damagecurse 	cursedflesh
	ic-curse
	stoneskin (block kee damage)
	skillup (某样特殊技能系数提高的标识)
	soft_damage	Target的普通攻击不伤害最大值

	提升精气神等的参数		gks	kee

	提升ＦＭＡ等的参数		fma

	天机的五大神功：Quest_atk, quest_dmg, quest_atk, quest_parry, quest_kee

		string type2,	--- powerup 包括了dodgeup,所以powerup的pfm应该使用type2定义dodgeup.
		string att,		--- BUFF 的大致分类（Bless 或是 Curse)
		string name,	--- BUFF 的名字，一般武功名+特殊功能名，如 混沌功·斗寒诀

		stribg buff0,	--- 增加一个参数，不受special_func限制，可以用来定义一些mark
		int buff0_c,
		string buff1,	--- 具体的buff内容，最多可以有三个参数
		int buff1_c,			当special_fuct定义为1时，buff1,buff2,buff3只能定义为kee/gin/sen
		string buff2,
		int buff2_c,
		string buff3,
		int buff3_c,

		string shield_type,	---用于 SHIELD类的BUFF
		int shield_amount,
		string shield_desc,

		string buffup_name,
		string buffup_type,
		int buffup_ratio,
		string buffup_msg,
		string disable_type,
		string env_type		--- 加一个env的setup, for invisibility
		int	env_type_c

		int time,			--- 持续时间
		string buff_msg,	--- BUFF时看到的信息。
		string warn_msg,	--- BUFF即将消失时的提示信息（可缺省）
		string disa_msg,	--- BUFF消失时的提示信息（可缺省）
		int disa_type,		--- BUFF消失时的提示方式	0: tell 1: message_vision

		function finish_fuction,	// disa_type == 2: exec this function when buffup interrupted and tell, 3 exec w.b.i and m_v.
		int special_func			// special_func: 1 - kee/gks buffup. 2 - evasion/parry  3 - FMA buffup.
*/


// #pragma optimize all

#include <ansi.h>
inherit F_DBASE;

#define LOTTO "/data/lotto"
mapping read_text(string file);
int lotto_money;
int countnum,roundnum;
int roll_round;
string roll_result;
mapping lotto_lst;
string *lottoo=({"朝廷","丐帮","金钱帮","少林寺","大昭寺","兴国寺","武当","华山","狼山","帝王谷","快活林","白云城","魔教","天枫十四","三清宫","神水宫","皓月宫","万梅山庄","铁雪山庄","神剑山庄","富贵山庄","落花神殿",});

void create() {
    	seteuid(getuid());
    	set("name", "异常状态精灵（兼职中）");
    	set("id", "npc");
	set("channel_id", "素馨");
	set("index",1);
	lotto_lst = read_text(LOTTO);
}

int list_buffs(){
	printf("%O",query("list"));
	return 1;
}

int remove_buffup(object who,int index_num,int flag)
{
	mapping buff;
	object caster;
	string type,name;
	string buff1,buff2,buff3, buff0;
	int buff1_c,buff2_c,buff3_c, buff0_c;
	int time,warn_time;
	string buff_msg,warn_msg,disa_msg;
	string shield_type,shield_desc;
	string buffup_name,buffup_type,buffup_msg;
	int buffup_ratio;
	int shield_amount;
	string disable_type, env_type,condition_type;
	function finish_function;
	int special_func;

	if (!who)
		return 0;
	if (!index_num)
		return 0;

	buff = who->query_temp("buff/"+index_num);
	if (!mapp(buff))
		return 0;

	buffup_name=buff["buffup_name"];
	buffup_type=buff["buffup_type"];
	buffup_ratio=buff["buffup_ratio"];
	buffup_msg=buff["buffup_msg"];

	if (buffup_name && buffup_name != "")
	{
		who->delete_temp("buffup/"+buffup_name);
		who->delete_temp("buffup/"+buffup_name+"_msg");
		who->add_temp("buffup/"+buffup_name+"_amount",-buffup_ratio);
	}

	disable_type = buff["disable_type"];
	if (disable_type && disable_type != "")
		who->delete("disable_type");

	env_type = buff["env_type"];
	if (env_type && env_type != "")
		who->delete("env/"+ env_type);

	buff0 = buff["buff0"];
	buff0_c = buff["buff0_c"];
	buff1=buff["buff1"];
	buff1_c=buff["buff1_c"];
	buff2=buff["buff2"];
	buff2_c=buff["buff2_c"];
	buff3=buff["buff3"];
	buff3_c=buff["buff3_c"];


	if (buff0 && buff0 != "" && (buff0 != "block_msg/all" || who->query_temp("block_msg/all")>=1 )
							 && (buff0 != "disable_inputs"|| who->query_temp("disable_inputs")>=1 )
							 && (buff0 != "is_unconcious" || who->query_temp("is_unconcious")>=1 ) )
		who->add_temp(buff0,-buff0_c);

	special_func = buff["special_func"];

	if (special_func && special_func != 0)
	{
		if (special_func == 1)
		{
			if (buff1 && buff1 != "")
			{
				who->add("max_"+buff1,-buff1_c);
				if (who->query("eff_"+buff1) > who->query("max_"+buff1))
					who->set("eff_"+buff1, who->query("max_"+buff1));
				if (who->query(buff1) > who->query("max_"+buff1))
					who->set(buff1, who->query("max_"+buff1));
			}

			if (buff2 && buff2 != "")
			{
				who->add("max_"+buff2,-buff2_c);
				if (who->query("eff_"+buff2) > who->query("max_"+buff2))
					who->set("eff_"+buff2, who->query("max_"+buff2));
				if (who->query(buff2) > who->query("max_"+buff2))
					who->set(buff2, who->query("max_"+buff2));
			}

			if (buff3 && buff3 != "")
			{
				who->add("max_"+buff3,-buff3_c);
				if (who->query("eff_"+buff3) > who->query("max_"+buff3))
					who->set("eff_"+buff3, who->query("max_"+buff3));
				if (who->query(buff3) > who->query("max_"+buff3))
					who->set(buff3, who->query("max_"+buff3));
			}
		}

		if (special_func == 2 && who->query_temp("buffup/evade_amount") < 0)
			who->set_temp("buffup/evade_amount",0);

		if (special_func == 2 && who->query_temp("buffup/parry_amount") < 0)
			who->set_temp("buffup/parry_amount",0);

		if (special_func == 3)
		{
			if (buff1 && buff1 != "")
			{
				who->add("max_"+buff1,-buff1_c);
				if (who->query(buff1) > who->query("max_"+buff1)*2)
					who->set(buff1, who->query("max_"+buff1)*2);
			}

			if (buff2 && buff2 != "")
			{
				who->add("max_"+buff2,-buff2_c);
				if (who->query(buff2) > who->query("max_"+buff2)*2)
					who->set(buff2, who->query("max_"+buff2)*2);
			}

			if (buff3 && buff3 != "")
			{
				who->add("max_"+buff3,-buff3_c);
				if (who->query(buff3) > who->query("max_"+buff3)*2)
					who->set(buff3, who->query("max_"+buff3)*2);
			}
		}
	}


	else
	{

	// annie * prevent the block-msg bug.
		if (buff1 && buff1 != "" && (buff1 != "block_msg/all" || who->query_temp("block_msg/all")>=1 )
								 && (buff1 != "disable_inputs" || who->query_temp("disable_inputs")>=1 )
								 && (buff1 != "is_unconcious" || who->query_temp("is_unconcious")>=1 ) )
		{
			who->add_temp(buff1,-buff1_c);
			if (who->query_temp(buff1) == 0)	who->delete_temp(buff1);		// Added to clear those unnecessary xx:0 which causes problems
		}
		if (buff2 && buff2 != "" && (buff2 != "block_msg/all" || who->query_temp("block_msg/all")>=1 )
								 && (buff2 != "disable_inputs"|| who->query_temp("disable_inputs")>=1 )
								 && (buff2 != "is_unconcious" || who->query_temp("is_unconcious")>=1 ) )
		{
			who->add_temp(buff2,-buff2_c);
			if (who->query_temp(buff2) == 0)	who->delete_temp(buff2);
		}

		if (buff3 && buff3 != "" && (buff3 != "block_msg/all" || who->query_temp("block_msg/all")>=1 )
								 && (buff3 != "disable_inputs" || who->query_temp("disable_inputs")>=1)
								 && (buff3 != "is_unconcious" || who->query_temp("is_unconcious")>=1 ))
		{
			who->add_temp(buff3,-buff3_c);
			if (who->query_temp(buff3) == 0)	who->delete_temp(buff3);
		}
	}

	// 这个处理不太好，两个condition buff会出现显示错误的
	condition_type = buff["condition_type"];
	if (stringp(condition_type) && condition_type!="") {
		if (who->query_temp("marks/condition_type"))
			who->set_temp("condition_type", who->query_temp("marks/condition_type"));
		else
			who->delete_temp("condition_type");
	}

	shield_type = buff["shield_type"];
	shield_amount = buff["shield_amount"];
	shield_desc = buff["shield_desc"];

	if (shield_type && shield_type != "")
	{
		// damage shield
		if (buff["type"] == "damageshield" && (shield_type == "kee" || shield_type == "gin" || shield_type == "sen"))
			who->delete_temp("damage_shield");
		// heal shield
		else if (buff["type"] == "healshield" && (shield_type == "kee" || shield_type == "gin" || shield_type == "sen"))
			who->delete_temp("heal_shield");
		// atman/force/mana absorption shield
		else if (buff["type"] == "afm-absshield"
			&& (shield_type == "atman" || shield_type = "force" || shield_type == "mana"))
			who->delete_temp("afm_abs_shield");
		// force shield
		else
			who->delete_temp("shield_force");
	}

	finish_function=buff["finish_function"];

	if(functionp(finish_function))
		if ((flag && buff["disa_type"] >= 2) || !flag)	// 非正常中断，则disa_type 2|3时才执行此程式段。
			evaluate(finish_function,who,buff["caster"]);

	disa_msg = buff["disa_msg"];
	name = buff["name"];

	if (disa_msg && disa_msg == "none") {}
	else if (disa_msg && disa_msg != "")
	{
		if (buff["disa_type"] == 1 || buff["disa_type"] == 3)
			message_vision(disa_msg,who);
		else
			tell_object(who,disa_msg);
	}
	else
		tell_object(who,YEL"你所受到的"WHT+name+YEL"的效用消失了。\n"NOR);

	who->delete_temp("buff_name/"+index_num);
	who->set_temp("buff_type/"+buff["type"],0);
	if (buff["type2"])
		who->set_temp("buff_type/"+buff["type2"],0);
	who->delete_temp("buff/"+index_num);
	who->delete_temp("buff_time/"+index_num);

	delete("list/"+ index_num);

	return 1;
}


int warn(object who,int index_num,int warn_time)
{
	mapping buff;
	string warn_msg,name;
	if (!who)
		return 0;
	if (!index_num)
		return 0;

	buff = who->query_temp("buff/"+index_num);
	if (!mapp(buff))
		return 0;
	warn_msg = buff["warn_msg"];
	name = buff["name"];

	if (warn_msg && warn_msg == "none"){

	}
	else if (warn_msg && warn_msg != "")
		tell_object(who,warn_msg);
	else
		tell_object(who,YEL"你所受到的"WHT+name+YEL"的效用快要消失了。\n"NOR);

	call_out("remove_buffup",warn_time,who,index_num);
	return 1;
}

/*
	buff =
		([
			"caster":me,
			"who": me,
			"type":"cpsup",
			"att":"bless",
			"name":"急风三十六式·流云步",
			"buff1": "apply/composure",
			"buff1_c":cps_skill,
			"time":  180,
			"buff_msg":BGRN + WHT"$N身形一晃滑出丈余，立时又回到了原地，如行云流水，一气呵成。\n"NOR,
		]);
*/

int buffup(mapping buff)
{
	object caster,who;
	string type,type2,name;
	int index_num;
	string buff1,buff2,buff3,buff0;
	int buff1_c,buff2_c,buff3_c, buff0_c;
	int time,warn_time;
	string buff_msg,warn_msg,disa_msg;
	string shield_type,shield_desc;
	int shield_amount;
	string buffup_name,buffup_type,buffup_msg;
	int buffup_ratio;
	string disable_type, env_type, condition_type;
	int env_type_c;
	int special_func;


	if (!mapp(buff))
		return 0;

	caster = buff["caster"];
	who=buff["who"];

	if (!who || !caster)
		return 0;

	index_num = query("index");	// get buffup index
	set("list/"+ index_num, buff["who"]->query("id") + ":  " + buff["name"]);
	add("index",1);

	who->set_temp("buff/"+index_num,buff);
	who->set_temp("buff_type/"+buff["type"],index_num);
	if (buff["type2"])
		who->set_temp("buff_type/"+buff["type2"],index_num);
	who->set_temp("buff_name/"+index_num,buff["name"]);
	who->set_temp("buff_time/"+index_num,time());

	buff_msg = buff["buff_msg"];
	if (caster != who)
		message_vision(buff_msg,who,caster);	// BUFFMSG 所有人都可见
	else
		message_vision(buff_msg,caster);	// BUFFMSG 所有人都可见

	buff0= buff["buff0"];
	buff0_c = buff["buff0_c"];
	buff1=buff["buff1"];
	buff1_c=buff["buff1_c"];
	buff2=buff["buff2"];
	buff2_c=buff["buff2_c"];
	buff3=buff["buff3"];
	buff3_c=buff["buff3_c"];


	if (buff0 && buff0 != "")
		who->add_temp(buff0,buff0_c);

	special_func = buff["special_func"];

	if (special_func && special_func != 0)
	{
		if (special_func == 1)
		{
			if (buff1 && buff1 != "")
			{
				who->add("max_"+buff1,buff1_c);
				who->add("eff_"+buff1,buff1_c);

				if (who->query("eff_" + buff1) < who->query(buff1))
					who->set(buff1,who->query("eff_" + buff1));
			}

			if (buff2 && buff2 != "")
			{
				who->add("max_"+buff2,buff2_c);
				who->add("eff_"+buff2,buff2_c);

				if (who->query("eff_" + buff2) < who->query(buff2))
					who->set(buff2,who->query("eff_" + buff2));
			}

			if (buff3 && buff3 != "")
			{
				who->add("max_"+buff3,buff3_c);
				who->add("eff_"+buff3,buff3_c);

				if (who->query("eff_" + buff3) < who->query(buff3))
					who->set(buff3,who->query("eff_" + buff3));
			}
		}


		if (special_func == 3)
		{
			if (buff1 && buff1 != "")
			{
				who->add("max_"+buff1,buff1_c);
			if (who->query(buff1) > who->query("max_"+buff1)*2)
				who->set(buff1, who->query("max_"+buff1)*2);
			}

			if (buff2 && buff2 != "")
			{
				who->add("max_"+buff2,buff2_c);
			if (who->query(buff2) > who->query("max_"+buff2)*2)
				who->set(buff2, who->query("max_"+buff2)*2);
			}

			if (buff3 && buff3 != "")
			{
				who->add("max_"+buff3,buff3_c);
			if (who->query(buff3) > who->query("max_"+buff3)*2)
				who->set(buff3, who->query("max_"+buff3)*2);
			}
		}

	}
	else
	{
		if (buff1 && buff1 != "")
			who->add_temp(buff1,buff1_c);

		if (buff2 && buff2 != "")
			who->add_temp(buff2,buff2_c);

		if (buff3 && buff3 != "")
			who->add_temp(buff3,buff3_c);
	}

	disable_type = buff["disable_type"];
	if (disable_type && disable_type != "")
		who->set("disable_type",disable_type);

	env_type = buff["env_type"];
	if (env_type && env_type != "")
		who->set("env/"+ env_type, buff["env_type_c"]);

	condition_type = buff["condition_type"];
	if (stringp(condition_type) && condition_type!="") {
		if (who->query_temp("condition_type"))
			who->set_temp("marks/condition_type", who->query_temp("condition_type"));
		who->set_temp("condition_type",buff["condition_type"]);
	}

	shield_type = buff["shield_type"];
	shield_amount = buff["shield_amount"];
	shield_desc = buff["shield_desc"];

	if (shield_type && shield_type != "")
	{
		// damage shield
		if (buff["type"]== "damageshield" && (shield_type == "kee" || shield_type == "gin" || shield_type == "sen"))
		{
			who->set_temp("damage_shield/type",shield_type);
			who->set_temp("damage_shield/amount",shield_amount);
			who->set_temp("damage_shield/msg",shield_desc);
		}
		// heal shield
		else if ( buff["type"]== "healshield" && (shield_type == "kee" || shield_type = "gin" || shield_type == "sen"))
		{
			who->set_temp("heal_shield/type",shield_type);
			who->set_temp("heal_shield/amount",shield_amount);
			who->set_temp("heal_shield/msg",shield_desc);
		}
		// atman/force/mana absorption shield
		else if (buff["type"] == "afm-absshield"
			&& (shield_type == "atman" || shield_type = "force" || shield_type == "mana"))
		{
			who->set_temp("afm_abs_shield/type",shield_type);
			who->set_temp("afm_abs_shield/ratio",shield_amount);
			who->set_temp("afm_abs_shield/msg",shield_desc);
		}
		// protection shield
		else {
			who->set_temp("shield_force/type",shield_type);
			who->set_temp("shield_force/ratio",shield_amount);
			who->set_temp("shield_force/msg",shield_desc);
		}
	}

	buffup_name=buff["buffup_name"];
	buffup_type=buff["buffup_type"];
	buffup_ratio=buff["buffup_ratio"];
	buffup_msg=buff["buffup_msg"];

	if (buffup_name && buffup_name != "")
	{
		who->set_temp("buffup/"+buffup_name,buffup_type);
		who->set_temp("buffup/"+buffup_name+"_msg",buffup_msg);
		who->add_temp("buffup/"+buffup_name+"_amount",buffup_ratio);
	}


	time = buff["time"];
	warn_time = time / 40;
	if (warn_time < 15)
		warn_time = 15;
	if (warn_time > time)
		warn_time = 3;	// 3秒内消失的buff?...应该没有bah?


	call_out("warn",time - warn_time,who,index_num,warn_time);
	return 1;
}

int check_buff(object who,string what)	// 是否已有类似BUFF?
{
	if (who->query_temp("buff_type/"+what))
		return who->query_temp("buff_type/"+what);

	if (what == "kee")	// DWG KEE BUFFUP/??? ALL BUFFUP
		if (who->query_temp("buff_type/gks"))
			return who->query_temp("buff_type/gks");

	if (what == "gks")	// DWG KEE BUFFUP/??? ALL BUFFUP
		if (who->query_temp("buff_type/kee"))
			return who->query_temp("buff_type/kee");

	if (who->query_temp("buff_type/blocked") && what != "blocked")	// 不動之界：禁止一切buff.
		return -1;

	return 0;
}

int get_buff_caster(object who,string what)
{
	mapping buff;
	int idx;
	idx = check_buff(who,what);
	if (idx < 1)
		return 0;
	buff = who->query_temp("buff/"+idx);
	return buff["caster"];
}

int debuff(object me,string type,int attr)
{
	// attr = 1: bless
	// attr = -1: curse
	mapping buff_list,buff;
	string *lists;
	int i,flag=0,flag2=0;
	int idx;
	buff_list = me->query_temp("buff");

	if( !mapp(buff_list) || !sizeof(buff_list) )
		return 0;

	lists = keys(buff_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		buff = me->query_temp("buff/"+lists[i]);
		if (buff["type"] != type && buff["type2"] != type && type != "all")	// 清散咒土:dispel all buffup.
			continue;
		if (attr == 1 && buff["att"] != "bless")
			continue;
		if (attr == -1 && buff["att"] != "curse")
			continue;
		sscanf(lists[i], "%d", flag);
		remove_buffup(me,flag,1);	// interrupt_buff flag
		if (type == "all")
			flag2++;
	}
	if (type == "all")
		return flag2;
	else
		return flag;
}

int get_buff_num(object me,int attr)
{
	mapping buff_list,buff;
	string *lists;
	int i,time,warn_time,idx,flag1=0,flag2=0;
	buff_list = me->query_temp("buff");
	if( !mapp(buff_list) || !sizeof(buff_list) )
		return 0;

	lists = keys(buff_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		buff = me->query_temp("buff/"+lists[i]);
		if (buff["att"] == "bless")
			flag1++;
		if (buff["att"] == "curse")
			flag2++;
	}
	if (attr == 1)
		return flag1;
	else if (attr == -1)
		return flag2;
	else
		return flag1+flag2;
}

mapping read_text(string file)
{
	string *line,lines;
	string ski,num;
	int i;
	mapping data;
	data = ([]);
	lines =  read_file(file);

	if(lines)
	{
		line = explode(lines,"\n");
		sscanf(line[0],"stock_gold=%d",lotto_money);
		sscanf(line[1],"round=%d",roundnum);
		sscanf(line[2],"roll_round=%d",roll_round);
		sscanf(line[3],"roll_result=%s",roll_result);
		sscanf(line[4],"count=%d",countnum);
		for(i=5;i<sizeof(line);i++)
		{
			sscanf(line[i],"%s:%s",ski,num);
			data[ski] = num;
 		}
	}

	if (roundnum == 0)
		roundnum=1;

	return data;
}

string write_list()
{
	int i;
	string outp;
	string *mterm;
	rm(LOTTO);
	write_file(LOTTO,"stock_gold="+lotto_money+"\n",0);
	write_file(LOTTO,"round="+roundnum+"\n",0);
	write_file(LOTTO,"roll_round="+roll_round+"\n",0);
	write_file(LOTTO,"roll_result="+roll_result+"\n",0);
	write_file(LOTTO,"count="+countnum+"\n",0);
   	set_eval_limit(1);
	if(mapp(lotto_lst) && sizeof(lotto_lst))
	{
		mterm = keys(lotto_lst);
		for(i=0;i<sizeof(mterm);i++) {
	    	reset_eval_cost();
			outp=mterm[i]+":"+lotto_lst[mterm[i]]+"\n";
			write_file(LOTTO,outp,0);
		}
	}
}


int lotto_prog()
{
	write_list();
}

mapping lotto_get_player_data(string arg)
{
	mapping data;

//  2:ROUND3~月(mingyue).3-1-2-3-5-4

	string pplname,pplid;
	int pplround,ppl1,ppl2,ppl3,ppl4,ppl5,ppl6;
	sscanf(arg,"ROUND%d~%s(%s).%d-%d-%d-%d-%d-%d",pplround,pplname,pplid,ppl1,ppl2,ppl3,ppl4,ppl5,ppl6);
	data =
	([
		"name":pplname,
		"id":pplid,
		"round":pplround,
		"num1":ppl1,
		"num2":ppl2,
		"num3":ppl3,
		"num4":ppl4,
		"num5":ppl5,
//		"num6":ppl6,
	]);
	return data;

}

mapping lotto_checkout(string id)
{
	int i;
	string outp;
	string *mterm;
	mapping player_data;
	mapping data = ([ ]);

	int r1,r2,r3,r4,r5;
	int i1,i2,i3,i4,i5,i0;
	int c,c0;
	if (!roll_result)
	{
		data =
		([
			"id":id,
			"r1":r1,
			"r2":r2,
			"r3":r3,
			"r4":r4,
			"r5":r5,
		]);
		return data;
	}
	sscanf(roll_result,"%d-%d-%d-%d-%d:%d",i1,i2,i3,i4,i5,i0);
	r1=0;r2=0;r3=0;r4=0;r5=0;

   	set_eval_limit(1);
	if(mapp(lotto_lst) && sizeof(lotto_lst))
	{
		mterm = keys(lotto_lst);
		for(i=0;i<sizeof(mterm);i++)
		{
	    	reset_eval_cost();
			outp=lotto_lst[mterm[i]];
			player_data=lotto_get_player_data(outp);
			c=0;c0=0;
			if (player_data["id"] == id && player_data["round"] == roll_round)
			{
				if (player_data["num1"] == i1 || player_data["num2"] == i1 || player_data["num3"] == i1 || player_data["num4"] == i1 || player_data["num5"] == i1 || player_data["num6"] == i1)
					c++;
				if (player_data["num1"] == i2 || player_data["num2"] == i2 || player_data["num3"] == i2 || player_data["num4"] == i2 || player_data["num5"] == i2 || player_data["num6"] == i2)
					c++;
				if (player_data["num1"] == i3 || player_data["num2"] == i3 || player_data["num3"] == i3 || player_data["num4"] == i3 || player_data["num5"] == i3 || player_data["num6"] == i3)
					c++;
				if (player_data["num1"] == i4 || player_data["num2"] == i4 || player_data["num3"] == i4 || player_data["num4"] == i4 || player_data["num5"] == i4 || player_data["num6"] == i4)
					c++;
				if (player_data["num1"] == i5 || player_data["num2"] == i5 || player_data["num3"] == i5 || player_data["num4"] == i5 || player_data["num5"] == i5 || player_data["num6"] == i5)
					c++;

				if (player_data["num1"] == i0 || player_data["num2"] == i0 || player_data["num3"] == i0 || player_data["num4"] == i0 || player_data["num5"] == i0 || player_data["num6"] == i0)
					c0=1;

				if (c == 5)
					r1++;
				else if (c == 4 && c0 == 1)
					r2++;
				else if (c == 4)
					r3++;
				else if (c == 3 && c0 == 1)
					r4++;
				else if (c == 3)
					r5++;
				map_delete(lotto_lst,mterm[i]);
			}

		}
	}
	data =
	([
		"id":id,
		"r1":r1,
		"r2":r2,
		"r3":r3,
		"r4":r4,
		"r5":r5,
	]);

	lotto_prog();

	return data;
}

mapping lotto_getlist(string id)
{
	int i;
	string outp;
	string *mterm;
	mapping player_data;
	mapping data = ([ ]);

   	set_eval_limit(1);
	if(mapp(lotto_lst) && sizeof(lotto_lst))
	{
		mterm = keys(lotto_lst);
		for(i=0;i<sizeof(mterm);i++)
		{
	    	reset_eval_cost();
			outp=lotto_lst[mterm[i]];
			player_data=lotto_get_player_data(outp);
			if (player_data["id"] == id)
//				return lotto_lst;
				data[mterm[i]]=outp;
		}
	}
	return data;
}

int lotto_get_roll_round()
{
	return roll_round;
}

string lotto_get_roll_result()
{
	int i1,i2,i3,i4,i5,i0;
	string arg;
	if (!roll_result || roll_result == "0" || roll_result == 0)
		return "的彩券并没有发行";
	sscanf(roll_result,"%d-%d-%d-%d-%d:%d",i1,i2,i3,i4,i5,i0);
	arg = "排在前五位的门派分别是"+lottoo[i1-1]+"－"+lottoo[i2-1]+"－"+lottoo[i3-1]+"－"+lottoo[i4-1]+"－"+lottoo[i5-1]+"，孙山门派是"+lottoo[i0-1];
	return arg;
}

int lotto_roll(object me)
{
	int i;
	int i1,i2,i3,i4,i5,i6,i0;
	int r1,r2,r3,r4,r5,r6;
	int c,c0;
	int range=22;
	int reward;
	string outp;
	string *mterm;
	mapping player_data;

	// Remove Old Data.

   	set_eval_limit(1);
	if(mapp(lotto_lst) && sizeof(lotto_lst))
	{
		mterm = keys(lotto_lst);
		for(i=0;i<sizeof(mterm);i++)
		{
	    	reset_eval_cost();
			outp=lotto_lst[mterm[i]];
			player_data=lotto_get_player_data(outp);
			if (player_data["round"] < roundnum)
				map_delete(lotto_lst,mterm[i]);
		}
	}

	// Generalt Result.

	roll_round++;

	i1=random(range)+1;
	i2 = random(range)+1;
	i3 = random(range)+1;
	i4 = random(range)+1;
	i5 = random(range)+1;
//	i6 = random(range)+1;
	i0 = random(range)+1;
	while (i1 == i2)
		i2 = random(range)+1;
	while (i1 == i3 || i2 == i3)
		i3 = random(range)+1;
	while (i1 == i4 || i2 == i4 || i3 == i4)
		i4 = random(range)+1;
	while (i1 == i5 || i2 == i5 || i3 == i5 || i4 == i5)
		i5 = random(range)+1;
//	while (i1 == i6 || i2 == i6 || i3 == i6 || i4 == i6 || i5 == i6)
//		i6 = random(range)+1;

	while (i1 == i0 || i2 == i0 || i3 == i0 || i4 == i0 || i5 == i0/* || i6 == i0*/)
		i0 = random(range)+1;

	roll_result=i1+"-"+i2+"-"+i3+"-"+i4+"-"+i5+/*"-"+i6+*/":"+i0;

	// Calc. reward

	r1=0;r2=0;r3=0;r4=0;r5=0;r6=0;

   	set_eval_limit(1);
	if(mapp(lotto_lst) && sizeof(lotto_lst))
	{
		mterm = keys(lotto_lst);
		for(i=0;i<sizeof(mterm);i++)
		{
    	reset_eval_cost();
			c=0;c0=0;
			outp=lotto_lst[mterm[i]];
			player_data=lotto_get_player_data(outp);
			if (player_data["round"] == roll_round)
			{
				if (player_data["num1"] == i1 || player_data["num2"] == i1 || player_data["num3"] == i1 || player_data["num4"] == i1 || player_data["num5"] == i1 || player_data["num6"] == i1)
					c++;
				if (player_data["num1"] == i2 || player_data["num2"] == i2 || player_data["num3"] == i2 || player_data["num4"] == i2 || player_data["num5"] == i2 || player_data["num6"] == i2)
					c++;
				if (player_data["num1"] == i3 || player_data["num2"] == i3 || player_data["num3"] == i3 || player_data["num4"] == i3 || player_data["num5"] == i3 || player_data["num6"] == i3)
					c++;
				if (player_data["num1"] == i4 || player_data["num2"] == i4 || player_data["num3"] == i4 || player_data["num4"] == i4 || player_data["num5"] == i4 || player_data["num6"] == i4)
					c++;
				if (player_data["num1"] == i5 || player_data["num2"] == i5 || player_data["num3"] == i5 || player_data["num4"] == i5 || player_data["num5"] == i5 || player_data["num6"] == i5)
					c++;
//				if (player_data["num1"] == i6 || player_data["num2"] == i6 || player_data["num3"] == i6 || player_data["num4"] == i6 || player_data["num5"] == i6 || player_data["num6"] == i6)
//					c++;

				if (player_data["num1"] == i0 || player_data["num2"] == i0 || player_data["num3"] == i0 || player_data["num4"] == i0 || player_data["num5"] == i0 || player_data["num6"] == i0)
					c0=1;
			}

			if (c == 5)
				r1++;
			else if (c == 4 && c0 == 1)
				r2++;
			else if (c == 4)
				r3++;
			else if (c == 3 && c0 == 1)
				r4++;
			else if (c == 3)
				r5++;
//			else if (c == 2 && c0 == 1)
//				r6++;
		}
/*
		me->add("r1",r1);
		me->add("r2",r2);
		me->add("r3",r3);
		me->add("r4",r4);
		me->add("r5",r5);
		me->add("r6",r6);
*/

	}
        CHANNEL_D->do_channel( this_object(), "announce",
		sprintf(HIW"本期%s\n产生了特等奖%d注，一等奖%d注，二等奖%d注，三等奖%d注，安慰奖%d注！"NOR,lotto_get_roll_result(),r1,r2,r3,r4,r5));

	// Next Round Start.

	roundnum++;

	lotto_prog();
}

int lotto_pay_money(int b)
{
	lotto_money-=b;
	return 1;
}

int lotto_add(object me,string arg)
{
//  2:ROUND3~月(mingyue).3-1-2-3-5-4

	lotto_money++;

	countnum++;
	lotto_lst[countnum] = "ROUND"+roundnum+"~"+me->query("name")+"("+me->query("id")+")."+arg;
	lotto_prog();
}


int lotto_swarm_add(object me,string arg)
{
//  2:ROUND3~月(mingyue).3-1-2-3-5-4
	lotto_money++;
	countnum++;
	lotto_lst[countnum] = "ROUND"+roundnum+"~"+me->query("name")+"("+me->query("id")+")."+arg;
}

/*
		set("drop/fixed_amount",n);
		set("drop/fixed_drop", ({"xx", "xx", "xx" });
		set("drop/bg",20);
		set("drop/common",100);
		set("drop/rare",0);
		set("drop/amount",2);
		set("drop/common_drop",({ "aa", "bb", "cc",	}) );
		set("drop/rare_drop",({ "aa1", "bb1", "cc1"	}) );

	drop generating process.
	1) fixed drop, It will always drop, and randomly picked from a list
	2) subjected to a zero drop "drop/bg"
	3) common_drop generated with chance
	4) rate_drop generated with chance

*/


void generate_drop_item(object me,object who)
{
		mapping drop;
		int fd,cd,rd,bg,amount,i,seed;
		string *list, name, announce_name,title;
		object item, *team, killer,gold;


		if (objectp(killer = who->query("possessed")))
			who = killer;

		// 确认杀人者
		if (mapp(team=who->query_team()) && sizeof(team)) {
			if (!stringp(name = who->query_temp("team_name")))
				name = "无名帮";
		} else
			name = who->query("name");

		// Gold reward
/*		if (me->query("gold")) {
			gold = new("/obj/money/gold");
			gold ->set_amount(me->query("gold"));
			if (gold)
				gold ->move(me);
		}*/

		// People involved
		if (sizeof(team)) {
			announce_name = "";
			for (i=0;i<sizeof(team);i++){
				if (objectp(team[i]))
					announce_name += team[i]->name(1) + "（" + team[i]->query("id")+"）";
			}
		}else
			announce_name = who->name(1) + "（" + who->query("id") + "）";
		title=me->query("title");
                if(!title){title="";}
                if(title){title=" "+replace_string(title,NOR,HIY)+" ";}

		// announce vitory
		if (me->query("real_ph") || me->query("real_boss")) {
			CHANNEL_D->do_sys_channel("info",sprintf("武林快讯：%s在%s中杀死了%s%s(%s) ！！！",
							sizeof(team)? who->query_temp("team_name"): announce_name,
							environment(me)->query("short"),title,
							me->query("name"),me->query("id")));
			if (sizeof(team))
				CHANNEL_D->do_sys_channel("info",sprintf(NOR WHT"%s成员："CYN"%s"HIY, who->query_temp("team_name"),announce_name));
		}


		// Drop generated

		drop = me->query("drop");
		if (!drop || !mapp(drop))
			return;

		fd = drop["fixed_amount"];
		cd = drop["common"];
		rd = drop["rare"];
		bg = drop["bg"];
		amount = drop["amount"];
		amount = random(random(amount)+1)+1;

		seed = random(100)+1;

		me->revive(1);

		if (fd) {
			for (i=0;i<fd;i++) {
				list = drop["fixed_drop"];
				item = new(list[random(sizeof(list))]);
				if (item)	item->move(me);
//				me->ccommand("say 我有一"+item->query("unit")+item->name()+"。");
				if (item)	CHANNEL_D->do_sys_channel(
					"info", sprintf(NOR YEL"得到了一%s%s",item->query("unit"),item->query("name")));
			}
		}

/*
		if (seed <= bg)							// BG
		{
			me->ccommand("say RPWT lah。");
			CHANNEL_D->do_sys_channel(
				"sys", sprintf("%s在%s中杀死了%s(%s)，结果什么都没得到．．．恭喜！请下次再来。\n",
						sizeof(team)? who->query_temp("team_name"): announce_name,
						environment(me)->query("short"),me->query("name"),me->query("id")));
			return;
		}
*/

		for (i=0; i<amount; i++)
		{
			seed = random(cd+rd)+1;
			if (seed > rd)						// Common drop
			{
				list = drop["common_drop"];
				cd = random(sizeof(list));
	//			ccommand("say 我有一"+list[cd]+"。");
				item = new(list[cd]);
				if (item)	item->move(me);
	//			me->ccommand("say 我有一"+item->query("unit")+item->name()+"。");
			}
			if (seed <= rd)						// Rare Drop
			{
				list = drop["rare_drop"];
				cd = random(sizeof(list));
	//			ccommand("say 我有一"+list[cd]+"。");
				item = new(list[cd]);
	//			me->ccommand("say "+HIY+"我有一"+item->query("unit")+item->name()+HIY+"。"+NOR);
				if (item)	item->move(me);
			}

			if (item)
			if (me->query("real_ph") || me->query("real_boss"))
			{
				CHANNEL_D->do_sys_channel(
					"info", sprintf(NOR YEL"得到了一%s%s",	item->query("unit"), item->query("name")));

				log_file("riddle/annie_log", sprintf("[%s] %s 在%s中杀死了%s(%s)，得到了%s。\n",
					ctime(time()), announce_name,
					environment(me)->query("short"),
					me->query("name"),me->query("id"),
					item->query("name")));
			}
		}

}

int query_count_number(){
	return countnum;
}

int query_lottto_num(){
	if (mapp(lotto_lst))
		return sizeof(lotto_lst);
	return 0;
}


/*

               (\~~~/)
               ( ．．)

               (_____)~．

　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

//
