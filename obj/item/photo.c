// ; annie 07.2003
// dancing_faery@hotmail.com

// 

inherit ITEM;
#include <ansi.h>


string *female_weight_desc = ({
	MAG "看来有点弱不禁风" NOR,
	BLU "显得纤弱无力" NOR,
	CYN "体态轻盈" NOR,
	CYN "身材苗条" NOR,
    HIG "曲线窈窕，玲珑有致" NOR,
	HIG "身材恰到好处" NOR,
	NOR "不胖不瘦" NOR,
	YEL "体态微丰" NOR,
	YEL "身材丰满" NOR,
	WHT "心宽体胖" NOR,
	HIR "似乎该减肥了" NOR
});
string *male_strength_desc = ({
	BLU "看来弱不禁风" NOR,
	HIB "好像手无缚鸡之力" NOR,
	CYN "让人微觉瘦弱" NOR,
	CYN "让人觉得气质文弱" NOR,
	HIG "体格刚健英武" NOR,
	NOR "长的不胖不瘦" NOR,
	YEL "行动间孔武有力" NOR,
	YEL "魁梧彪悍" NOR,
	WHT "心宽体胖" NOR,
	HIR "似乎该减肥了" NOR
});



void create() {
	set_name("阿水的照片", ({ "photo" }) );
	set("long", "这是一张阿水的照片。\n");
	set("unit", "张" );
}

string getfigure(object me) {	
	int str, ruler, level, exp, agi;
	exp =(int) me->query("combat_exp");
	str = me->query("str");
	agi = me->query("agi");
	if (me->query("gender")=="女性") {
	    str = str>50 ? 25 + str/2 : str;
	    str = str >25 ? str*10/(agi+1) + 20 : str;
	    ruler = sizeof(female_weight_desc)-1;
	    level = str >120 ? ruler : ( str/5 - str*str/1440) ;
	    level = level > ruler ? ruler : level; 
	    return female_weight_desc[level];
	}
	else {
	    str = str>60 ? 30 + str/3 : str;
	    str = str >30 ? str*10/(agi+1) + 20 : str;
	    ruler = sizeof(male_strength_desc)-1;
	    level = str >120 ? ruler : ( str/6 - str*str/1440) ;
	    level = level > ruler ? ruler : level; 
	    return male_strength_desc[level];
	}
}

string getper(object me, object obj) {
	int per;
	int spi;

	int weight, score;
	string str;

	per = obj->query_per();
	score = (int) obj->query("score");
	
	if((string)obj->query("gender") == "女性") {
		if(per >= 45) {
			str = HIG"的美已经难以用笔墨形容，相见之下令人不由魂失神夺！\n"NOR;
		} else if(per >= 40) {
			str = score > 1000 ? 
				 "美奂美仑，堪称人间仙子！\n" 
				:"妖艳绝伦，美目流动间让人神魂颠倒！\n" ;
		} else if(per >= 33) {
			str = score > 1000 ?  
				 "娇丽如花，令人情不自禁心生爱怜。\n"
				:"柔媚娇艳，浑身上下散发着无穷的诱惑。\n";
		} else if(per >= 29) {
			str = "有沉鱼落雁之容，避月羞花之貌。\n";
		} else if(per >= 24) { 
			str = score > 1000 ?  
				 "俏丽可人，一颦一笑间，总是让人怦然心动。\n"
				:"天生丽质，一双眼睛很会勾人。\n";
		} else if(per >= 18) {
			str = "风情万种，楚楚动人。\n"; 
		} else if(per >= 14) {
			str = "玲珑可爱，娇俏喜人。\n"; 
		} else if(per >= 10) {
			str = "相貌平平，还看得过去。\n";
		} else {
			str = "的相貌嘛...马马虎虎吧。\n";
		}
	} else {
		if (per >= 35) {
			str = "非常漂亮可爱。\n";
		} else if(per >= 30) { 
			str = "还算赏心悦目。\n";
		} else if(per >= 26) {
			str = "看来挺机灵的。\n";
		} else if(per >= 15) {
			str = "看来呆头呆脑的。\n";
		} else {
			str = "怪模怪样,挺吓人的。\n";
		}
	}
	
	return str;
}

string inventory_look(object obj, int flag) {
	string str, desc;
	object me, left, right;

	str = obj->short();
	if(obj->query("equipped")) {
		if(!desc = obj->query("armor_worn")) {
			if(!desc=obj->query("weapon_wielded")) {
				desc = "√";
			} else {
				me = environment(obj);
				left = me->query_temp("left_hand");
				right = me->query_temp("right_hand");
				if(obj == left && obj == right) {
					desc = "双手" + desc + "着";
				} else if(obj == right) {
					desc = "右手" + desc + "着";
				} else {
					desc = "左手" + desc + "着";
				}
			}
		}
		str = desc + str;
	} else if(!flag) {
		str = (environment(obj)->is_character() && !environment(obj)->is_corpse() ? 
				"怀藏" : "  ") + str;
	} else {
		return 0;
	}
	
	return str;
}

void blink(object me)
{
	string str,pro,*desc;
	object *inv,obj;
	desc = // 这里需要sinny添加;
	({
		"的面貌模糊，重影叠成一团。",
		"面如土色，浑身发抖。",
		"的嘴里鼓鼓囊囊的，似乎塞着什么东西。",
		"的瞳孔通红，看起来凶恶可怖。",
	});
	obj = me;	// lazy blanche..
	pro = me->query("gender") == "女性"?"她":"他";
	set("name",me->query("name")+"的照片");
	str = "这是一张"+me->query("name")+"的照片。\n";
	str += me->long();
	str += pro+"看起来象"+chinese_number(me->query("age") / 10 * 10)+"多岁的"+me->query("national")+"人。\n";
	str += pro + getper(me,me);
	str += pro + getfigure(me) +"。\n";
	str += pro + COMBAT_D->eff_status_msg((int)me->query("eff_kee") * 100 
				/ (int)me->query("max_kee")) + "\n";
	str += pro + (obj->is_naked() ? "赤身裸体。\n" : "");
	inv = all_inventory(obj);
	if(sizeof(inv))
	{
		inv = map_array(inv, "inventory_look", this_object(), ("无言"=="虹") ? 0 : 1 );
		inv -= ({ 0 });
		if(sizeof(inv))
			str += sprintf("%s\n", implode(inv, "\n  "));
	}
	// tatoo print
	if (obj->query_temp("body_print") ) str += obj->query_temp("body_print")+ "\n";
	str += pro;
	str += desc[random(sizeof(desc))];
	str += "\n";
	if (!random(10))
		str = "这张照片照的是：黑夜里乌鸦在飞。\n";
	set("long",str);
}


void init()
{
	blink(this_player());
}

