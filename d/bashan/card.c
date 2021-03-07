// #pragma optimize all

#include <ansi.h>
#include <dbase.h>

#define INIT_ATMAN 7
#define INIT_FORCE 10
#define INIT_MANA 7
#define INIT_ATMAN_SOURCE 1
#define INIT_FORCE_SOURCE 2
#define INIT_MANA_SOURCE 1
#define INIT_KEE 20
#define INIT_EFF_KEE 40
#define MAX_CARDS 7

int show_hp(object me);
int show_cards(object me,int i);
string get_stat(object who,string idx);
int init_stat(object who,string idx);
string get_card_name(int i);
int use_card(object me,string who,string arg);

int do_cardhp();

string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□";
int now_player = 0;

/*
type:
1: Source
2: Def/Heal
3: Attack
4: Special
5: Enchantment
*/

mapping *cardlist = ({
	([
		"index":		1,
		"chance":		90,
		"name":			"鬼斧神工",
		"type":			3,
		"desc":			"消耗内力5点，对敌人造成5～10点伤害。",
		"desc2":		"结果造成了%i1点伤害",
		"bas_1":		1,
		"bas_1_min":	5,
		"bas_1_max":	10,
		"cost_force":	3,
    ]),
	([
		"index":		2,
		"chance":		10,
		"name":			"酒气破霄",
		"type":			3,
		"desc":			"消耗内力8点，对敌人造成10～20点伤害。",
		"desc2":		"结果造成了%i1点伤害",
		"bas_1":		1,
		"bas_1_min":	10,
		"bas_1_max":	20,
		"cost_force":	8,
    ]),
});

mapping query_card()
{
	int i,j,k=0,l;
	i = sizeof(cardlist);
	for (j=0;j<i ; j++)
		k+=cardlist[j]["chance"];

	l = random(k)+1;
	k = 1;

	for (j=0;j<i; j++)
	{
		if (l - cardlist[j]["chance"] > 0)
			l -= cardlist[j]["chance"];
		else
		{
			k=j;
			break;
		}
	}

	return cardlist[k];
}

string get_card_name(int i)
{
	mapping card;
	string str;
	string *color= ({
	WHT,HIG,YEL,MAG,CYN,
	});
	card = cardlist[i-1];
//	str = "◎";
	str = "";
	str += color[card["type"]];
	str += card["name"];
	str += NOR;
	return str;
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return WHT;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return CYN;
	if( percent >= 30 ) return MAG;
	if( percent >= 10 ) return YEL;
	return RED;
}

string triba_graph(int val, int max, string color)
{
        if (max == 0) max = 1;
        return color + bar_string[0..(val*25/max)*2-1]
                + ((max > val) ? blank_string[(val*25/max)*2..(max*25/max)*2-1] : "") + NOR;
}

int init_stat(object who,string idx)
{
	int i;
	mapping card;
	set(idx+"/atman",INIT_ATMAN);
	set(idx+"/force",INIT_FORCE);
	set(idx+"/mana",INIT_MANA);
	set(idx+"/atman_source",INIT_ATMAN_SOURCE);
	set(idx+"/force_source",INIT_FORCE_SOURCE);
	set(idx+"/mana_source",INIT_MANA_SOURCE);
	set(idx+"/kee",INIT_KEE);
	set(idx+"/eff_kee",INIT_EFF_KEE);

	for (i=1; i< MAX_CARDS+1; i++)
	{
		card=query_card();
		set(idx+"/card_"+i,card["index"]);
//		tell_object(this_player(),idx+"/card_"+i+":"+card["index"]);

	}

	return 1;
}

string get_stat(object who,string idx)
{

	string str;

	int i;

	str = who->name();
	str += "("+who->query("id")+")";
	str += "\n";

	str += "气血： " + triba_graph(query(idx+"/kee"), 100, status_color(query(idx+"/kee"), 100)) + "\n";
	str += "硬功： " + triba_graph(query(idx+"/eff_kee"), 100, status_color(query(idx+"/eff_kee"), 100)) + "\n";

	str += "法力： ";
	str += query(idx+"/atman");
	str += "\t神通： ";
	str += query(idx+"/atman_source");
	str += "\n";
	str += "灵力： ";
	str += query(idx+"/mana");
	str += "\t咒术： ";
	str += query(idx+"/mana_source");
	str += "\n";
	str += "内力： ";
	str += query(idx+"/force");
	str += "\t内功： ";
	str += query(idx+"/force_source");
	str += "\n";

	return str;
}

int show_hp(object me)
{
	string str;
	object p1,p2;
	p1 = query("player_1");
	p2 = query("player_2");
	str = "-----------------------------------------------------------\n";
	str += get_stat(p1,"p1");
	str += "----------------------------------------------------------\n";
	str += get_stat(p2,"p2");
	str += "----------------------------------------------------------\n";
	tell_object(me,str);
	return 1;
}

int show_cards(object me,int i)
{
	string str,tmp;
	int j;

	str = "";

	for (j=1; j<99; j++)
	{
		tmp="p"+i+"/card_"+j;
//		message_vision(tmp,me);
		if (!query(tmp))
			break;
		str += j+".";
		str += get_card_name(query(tmp));
		str += " ";
		if (j%5 == 0)
			str += "\n";
	}
	str += "\n";
	tell_object(me,str);

	return 1;
}

int do_cardhp()
{
	object me = this_player();
	if (!query("player_1") || !query("player_2"))
		return 0;

	show_hp(me);
	if (me == query("player_1"))
		show_cards(me,1);
	else if (me == query("player_2"))
		show_cards(me,2);
	return 1;
}

int do_cardstart()
{
	object me = this_player();
	if (query("player_1") && query("player_2"))
		return notify_fail("已经有人在玩了耶。\n");
	if (me == query("player_1"))
		return notify_fail("你不能挑战自己．．．\n");
	if (!query("player_1"))
	{
		set("player_1",me);
		init_stat(me,"p1");
	}
	else
	{
		set("player_2",me);
		init_stat(me,"p2");
	}
	message_vision(CYN"$N在桌子前坐了下来。\n"NOR,me);
	return 1;
}

int use_card(object me,string who,string arg)
{
	int i,j,damage,flag;
	string tmp,str,tmp2;
	mapping card;
	string target;

	if (who == "p1")
		target="p2";
	else
		target="p1";


	if (!arg)
	{
		tell_object(me,"你要使用什么？\n");
		return 1;
	}

	tmp = who+"/card_"+arg;
	if (!query(tmp))
	{
		tell_object(me,"你没有这样技能。\n");
		return 1;
	}

	card = cardlist[query(tmp)-1];

	// check cost
	if (query(who+"/kee") < card["cost_kee"] || query(who+"/eff_kee") < card["cost_eff_kee"] || query(who+"/mana") < card["cost_mana"])
	{
		tell_object(me,"你现在无力使用这样技能。\n");
		return 1;
	}
	if (query(who+"/mana_source") < card["cost_mana_source"] || query(who+"/force_source") < card["cost_force_source"] || query(who+"/atman_source") < card["cost_atman_source"])
	{
		tell_object(me,"你现在无力使用这样技能。\n");
		return 1;
	}
	if (query(who+"/force") < card["cost_force"] || query(who+"/atman") < card["cost_atman"])
	{
		tell_object(me,"你现在无力使用这样技能。\n");
		return 1;
	}

	if (query(target+"/eff_kee") && card["bas_1"] == 4)	// 有此特殊作用的，将其放在位置1。
	{
		tell_object(me,get_card_name(query(tmp2))+"现在不能使用！\n");
		return 1;
	}

	add(who+"/kee",-card["cost_kee"]);
	add(who+"/eff_kee",-card["cost_eff_kee"]);
	add(who+"/mana",-card["cost_mana"]);
	add(who+"/mana_source",-card["cost_mana_source"]);
	add(who+"/force",-card["cost_force"]);
	add(who+"/force_source",-card["cost_force_source"]);
	add(who+"/atman",-card["cost_atman"]);
	add(who+"/atman_source",-card["cost_atman_source"]);

	tmp2=tmp;

	// dealt damage
	tmp=card["desc2"];

	if (card["type"] == 3)	// attack skill
	{
		if (flag)
			tmp = "，"+tmp;

		for (i=1; i<5; i++)
		{
			if (!card["bas_"+i])
				break;
			damage = card["bas_"+i+"_min"]+random(card["bas_"+i+"_max"]+1-card["bas_"+i+"_min"]);
			switch (card["bas_"+i])
			{
				case 1:
					str=target+"/eff_kee";
					if (query(str) >= damage)
					{
						add(str,-damage);
					}
					else
					{
						add(target+"/kee",query(str)-damage);
						set(str,0);
					}
					break;
				case 2:
					str=target+"/eff_kee";
					if (query(str) >= damage)
						add(str,-damage);
					else
						set(str,0);
					break;
				case 3:
					str=target+"/kee";
					if (query(str) >= damage)
						add(str,-damage);
					else
						set(str,0);
					break;
				case 4:
					str=target+"/kee";
					if (query(str) >= damage)
						add(str,-damage);
					else
						set(str,0);
					break;

			}
			str="%i"+i;
			tmp=replace_string(tmp,str,(""+damage));
		}

		flag=1;
	}

	message_vision("$N使用了"+get_card_name(query(tmp2))+"。\n",me);
	message_vision(tmp+"！\n",me);

	// win/lose check
	if (query(who+"/kee") < 0)
	{
		message_vision("$N输了。\n",me);
		return 1;
	}
	if (query(target+"/kee") < 0)
	{
		message_vision("$N获得了最后的胜利．．．\n",me);
		return 1;
	}

	// resort cards
	for (j=atoi(arg); j<99; j++)
	{
		tmp=who+"/card_"+j;
		if (!query(tmp))
			break;
		set(tmp,query(who+"/card_"+(j+1)));
	}

	// opponent draw a new card
	for (j=1; j<99; j++)
	{
		tmp=target+"/card_"+j;
		if (!query(tmp))
			break;
	}
	if (j < MAX_CARDS+1)
	{
		card=query_card();
		set(target+"/card_"+j,card["index"]);
	}

	// opponent recovery mana pool
	add(target+"/atman",query(target+"/atman_source"));
	add(target+"/mana",query(target+"/mana_source"));
	add(target+"/force",query(target+"/force_source"));


	// this turn end
	now_player = 1 - now_player;

	return 1;
}

int do_use(string arg)
{
	object me = this_player();
	if (!query("player_1") || !query("player_2"))
		return 0;

	if (!arg)
		return 0;

	if (me == query("player_1") && now_player == 0)
		use_card(me,"p1",arg);
	else if (me == query("player_2") && now_player == 1)
		use_card(me,"p2",arg);
	else
		return notify_fail("现在不是你行动的时机。\n");

	return 1;

}

int skip_turn(object me,string who)
{
	string target,tmp;
	int j;
	mapping card;

	if (who == "p1")
		target="p2";
	else
		target="p1";

	message_vision("$N决定略过这个回合。\n",me);

	// opponent draw a new card
	for (j=1; j<99; j++)
	{
		tmp=target+"/card_"+j;
		if (!query(tmp))
			break;
	}
	if (j < MAX_CARDS+1)
	{
		card=query_card();
		set(target+"/card_"+j,card["index"]);
	}

	// opponent recovery mana pool
	add(target+"/atman",query(target+"/atman_source"));
	add(target+"/mana",query(target+"/mana_source"));
	add(target+"/force",query(target+"/force_source"));


	// this turn end
	now_player = 1 - now_player;


	return 1;

}

int do_skip(string arg)
{
	object me = this_player();
	if (!query("player_1") || !query("player_2"))
		return 0;

	if (me == query("player_1") && now_player == 0)
		skip_turn(me,"p1");
	else if (me == query("player_2") && now_player == 1)
		skip_turn(me,"p2");
	else
		return notify_fail("现在不是你行动的时机。\n");

	return 1;

}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
