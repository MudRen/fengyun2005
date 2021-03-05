// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
	string bangname,bangrank,tmpstr;
	string setname;
	int exp;
	exp = (int) ob->query("combat_exp");
	if( ob->is_ghost() ) return HIB "【  鬼  魂  】" NOR;
	if( (int) ob->query("title_race") == -1 )
	{
		if( strlen((string) ob->query("env/title_race")) ==2){
		setname = ob->query("env/title_race");
		return HIR "【风云第一"+ setname +"】" NOR;}
		else return HIR "【 风云第一 】" NOR;
	}
        if( (int) ob->query("title_race") == -2 )
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "【风云第二"+ setname +"】" NOR;}
                else return HIR "【 风云第二 】" NOR;
	}
        if( (int) ob->query("title_race") == -3)
        {
                if( strlen((string) ob->query("env/title_race")) ==2){
                setname = ob->query("env/title_race");
                return HIR "【风云第三"+ setname +"】" NOR;}
                else return HIR "【 风云第三 】" NOR;
	}
	bangname = ob->query("marks/帮派");
	if (bangname!=0) {
		tmpstr = "marks/" + bangname;
		bangrank = ob->query(tmpstr);
		return HIB"【 "+bangname+bangrank+"】" NOR;
	}
                        if (exp >= 1000000)
                                return HIW "【 风云天骄 】" NOR;
                        else if (exp >= 800000)
                                return HIC "【 风云泰斗 】" NOR;
                        else if ( exp >= 600000)
                                return HIC "【 风云宗师 】" NOR;
                        else if (exp>= 400000)
                                return HIM "【 风云奇侠 】" NOR;
                        else if (exp>= 100000)
                                return HIM "【 风云大侠 】" NOR;
                        else if (exp>= 50000)
                                return HIB "【 风云少侠 】" NOR;
			else if (exp>= 25000)
                                return HIB "【 风云小侠 】" NOR;
                        else if (exp>= 10000)
                                return HIG "【 风云高手 】" NOR;
                        else if (exp >= 5000)
                                return HIG "【 风云新秀 】" NOR;

	switch(ob->query("gender")) {
	case "女性":
		switch(wizhood(ob)) {
			case "(admin)":			return HIR "【  女  神  】" NOR;
			case "(arch)":			return HIY "【  大魔女  】" NOR;
			case "(wizard)":		return HIG "【  魔  女  】" NOR;
			case "(apprentice)":	return HIC "【  小魔女  】" NOR;
			case "(immortal)":		return HIC "【  仙  女  】" NOR;
			default:
				if( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					return "【  杀人魔  】";
				if( (int)ob->query("thief") > 50 ) return "【  惯  窃  】";
				switch(ob->query("class")) {
					case "bonze":		return "【  尼  姑  】";
					case "taoist":		return "【  女  冠  】";
					case "ghost":		return "【  幽  灵  】";
					case "bandit":		return "【  女飞贼  】";
					case "dancer":		return "【  舞  仙  】";
                                        case "legend":          return "【  侠  女  】";
					case "scholar":		return "【  才  女  】";
                    case "official":    return "【  女  官  】";
					case "fighter":		return "【  女武者  】";
					case "traveller" :	return "【  浪  子  】";
					case "lishi" :      	return "【  女武者  】";
					case "swordsman":	return "【  女剑士  】";
					case "assassin":	return "【  杀  士  】";
					case "ninemoon":        return "【  邪  女  】";
					case "shaman":		return "【  巫  医  】";
					case "lama":		return "【  藏  尼  】";
					case "yinshi":          return "【  隐  士  】";
					case "beggar":		return "【  叫化子  】";
					default:			return "【  平  民  】";
			}
		}
	default:
		switch(wizhood(ob)) {
			case "(admin)":			return HIR "【  天  神  】" NOR;
			case "(arch)":			return HIY "【  大巫师  】" NOR;
			case "(wizard)":		return HIG "【  巫  师  】" NOR;
			case "(apprentice)":		return HIC "【 巫师学徒 】" NOR;
			case "(immortal)":		return HIC "【  仙  人  】" NOR;
			default:
				if( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					return "【  杀人魔  】";
				if( (int)ob->query("thief") > 10 ) return "【  惯  窃  】";
				switch(ob->query("class")) {
					case "bonze":		return "【  僧  人  】";
					case "taoist":		return "【  道  士  】";
					case "ghost":		return "【  幽  灵  】";
					case "bandit":		return "【  盗  贼  】";
					case "scholar":		return "【  书  生  】";
                                        case "legend":          return "【  游  侠  】";
                    case "official":    return "【  官  差  】";
					case "fighter":		return "【  武  者  】";
					case "lishi":		return "【  武  者  】";
					case "swordsman":	return "【  剑  士  】";
					case "traveller" :      return "【  浪  子  】";
					case "assassin":	return "【  杀  士  】";
					case "shaman":		return "【  巫  医  】";
					case "yinshi":          return "【  隐  士  】";
                                        case "lama":        	return "【  藏  僧  】";
					case "beggar":		return "【  叫化子  】";
					default:			return "【  平  民  】";
			}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师太";
				else return "师太";
				break;
			case "taoist":
				if( age < 18 ) return "小仙姑";
				else return "仙姑";
				break;
			default:
				if( age < 18 ) return "小姑娘";
				else if( age < 50 ) return "姑娘";
				else return "婆婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师父";
				else return "大师";
				break;
			case "taoist":
				if( age < 18 ) return "道兄";
				else return "道长";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "小老弟";
				else if( age < 50 ) return "壮士";
				else return "老前辈";
				break;
			default:
				if( age < 20 ) return "小兄弟";
				else if( age < 50 ) return "壮士";
				else return "老爷子";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				return "贼尼";
				break;
			case "taoist":
				return "妖女";
				break;
			default:
				if( age < 30 ) return "小贱人";
				else return "死老太婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "死秃驴";
				else return "老秃驴";
				break;
			case "taoist":
				return "死牛鼻子";
				break;
			default:
				if( age < 20 ) return "小王八蛋";
				if( age < 50 ) return "臭贼";
				else return "老匹夫";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
			case "lama":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			case "official":

			default:
				if( age < 50 ) return "小女子";
				else return "妾身";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
			case "shaolin":
			case "lama":
				if( age < 50 ) return "贫僧";
				else return "老衲";
				break;
			case "taoist":
				return "贫道";
				break;
			case "official":
				return "下官";
			default:
				if( age < 50 ) return "在下";
				else return "老头子";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			case "taoist":
				return "本仙姑";
			default:
				if( age < 50 ) return "本小姐";
				else return "本姑娘";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
			case "shaolin":
				if( age < 50 ) return "大和尚我";
				else return "老和尚我";
				break;
			case "lama":
				if(age<40) return "大喇嘛我";
					return "本佛爷我";
				break;
			case "official":
				if(age<50) return "本官爷我";
					return "太爷我";
				break;
			case "taoist":
				return "本山人";
				break;
			default:
				if( age < 50 ) return "大爷我";
				else return "老子";
				break;
			}
	}
}

string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = ob->query("age"))
                        a1 = this_player()->query("age");
                else {
                        a1 = this_player()->query("mud_age");
                        a2 = ob->query("mud_age");
                }
        } else {
                a1 = this_player()->query("age");
                a2 = 0;
        }



        switch (ob->query("gender")) {
                case "女性" :
                case "雌性" :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry/id"))
                                return "娘子";
                        if (a2 - a1 >= 20) return "姑姑";
                        if (a1 - a2 >= 20) return "侄女";
                        if (a1 > a2) return "贤妹";
                        return "姐姐";
                        break;
                default :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry/id"))
                                return "相公";
                        if (a2 - a1 >= 20) return "叔叔";
                        if (a1 - a2 >= 20) return "侄子";
                        if (a1 > a2) return "贤弟";
                        return "哥哥";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = ob->query("age"))
                        a1 = this_player()->query("age");
                else {
                        a1 = this_player()->query("mud_age");
                        a2 = ob->query("mud_age");
                }
        } else {
                a1 = this_player()->query("age");
                a2 = 0;
        }


        switch (this_player()->query("gender")) {
                case "女性" :
                case "雌性" :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry"))
                                return "妾身我";
                        if (a1 - a2 >= 20) return "姑姑我";
                        if (a2 - a1 >= 20) return "侄女我";
                        if (a1 > a2) return "姐姐我";
                        return "小妹我";
                        break;
                default :
                        if (userp(ob) && ob->query("id") == this_player()->query("marry"))
                                return "愚夫我";
                        if (a1 - a2 >= 20) return "叔叔我";
                        if (a2 - a1 >= 20) return "小侄我";
                        if (a1 > a2) return "愚兄我";
                        return "小弟我";
        }
}
