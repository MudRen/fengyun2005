#include <ansi.h>
inherit __DIR__"annieitem";

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



void create()
{
	set_name("雕像", ({ "statue"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "
一个还没有刻上脸庞的雕像，你可以把它刻成你喜欢人的样子（mimic）
你可以从家具店购买挂件来装饰它 （decorate），有了挂件的雕像就会
具有灵气，触摸后会有意想不到的效果（blessing statue）， 不过，
一个雕像上最多只能放三次挂件。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","m");
	set("lore_item",1);
	set("size",1);
	set("value", 500000);
	set("tax",5);
	set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player()) {
	   	add_action("do_mimic","mimic");
	   	add_action("do_decorate","decorate");
	   	add_action("do_touch", "blessing");
	}
}

int do_touch(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	mapping buff;
	string type,name;
	int amount,n;
	string *list = ({ "apply/karma","apply/armor","apply/damage","apply/composure","apply/agility","apply/strength" });
	int  *list_m = ({ 1, 10, 10, 1, 1, 1 });
	string *list_c = ( {"运气","护甲","伤害力","定力","速度","力量" });
				
	if (!arg) 
		return 0;
	
	if (present(arg,env) != ob)
		return 0;
	
	if (!env->is_owner(me->query("id"))) {
		tell_object(me,"屋子里的物件只有主人才能使用。\n");
		return 1;
	}

	if (me->is_fighting() || me->is_busy()) {
		tell_object(me,"你现在正忙，过一会儿吧。\n");
		return 1;
	}
	
	message_vision("$N小心翼翼的用手碰了一下"+name()+"。\n", me);

	if (!query("text3") || query("text3")>3 || query("text3")<1 ){
		tell_object(me,"触手冰冷，但什么也没发生。（要有了挂件才会有灵效）\n");
		return 1;
	}
	
	if (me->query("timer/house_statue") + 901 > time()) {
		tell_object(me,"你最近才被祝福过，等一会儿再来吧。（每次间隔１５分钟）\n");
		return 1;
	}
	
	if (!ANNIE_D->check_buff(me,"statue"))
	{
		n = random(sizeof(list));
		type = list[n];
		amount = list_m[n] * query("text3");
		name = list_c[n];
		
		
		if (!random(8000)) {		// 8000 *15 = 2000 hour to get 20mins +3 int chance, just for fun :D
			type = "apply/intelligence";
			amount = query("text3");
			name = "才智";
		}
		
		buff =
		([
			"caster":ob,
			"who":me,
			"type":"statue",
			"att":"bless",
			"name":"夕颜家居·"+name,
			"buff1": type,
			"buff1_c":amount,
			"time":900,
			"buff_msg":CYN"$N"CYN"只觉一道寒气慢慢流过身体．．．\n"NOR,
		]);
		ANNIE_D->buffup(buff);
		me->set("timer/house_statue",time());
		tell_object(me,WHT"（你的"+ name + "提高了"+ amount + "点）\n"NOR);
		
	}else
		tell_object(me,"触手冰冷，但什么也没发生。（你已经有了类似的功效了）\n");

	return 1;
}


int do_decorate(string arg){
	
	object env, item, me;
	string deco;
	me = this_player();
	
	if (!arg)
		return notify_fail("你想用哪一件挂件来装饰？\n");
		
	if (arg != "statue pendant")
		return notify_fail("你只能用家具店出售的雕像挂件来装饰。\n");
	
	item = present(arg, me);
	if (!item)
		return notify_fail("你身上没有这件物品。\n");
		
	if (item->query("item_type")!= "xx")
		return notify_fail("你只能用家具店出售的雕像挂件来装饰。\n");
	
	env = environment();
	
	if (query("text3") && query("text3")>= 3)
		return notify_fail("雕像上已经不能再放挂件了。\n");
	
	message_vision("$N将"+item->name()+"小心翼翼地放在"+name()+"的手上。\n", me);
	
	add("text3", 1);
	
	if (query("text3")==1) deco = HIG"翡翠雕龙"NOR;
		else if (query("text3")==2) deco = HIG"珊瑚东君"NOR;
		else deco = WHT"象牙湘妃"NOR;
	set("desc","这是一尊"+name()+"，你举目看去，只见：\n"+query("text")+"  颈上挂着一个小小的"+ deco+"。\n");
	
	destruct(item);
	reset_item_list(environment());
	return 1;
	
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
	
	if((string)obj->query("gender") == "女性")
	{
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
	}
	else if((string)obj->query("gender") == "男性") {
		if (per >= 35) {
			str = "相貌出众,百里挑一。\n";
		} else if(per >= 30) { 
			str = "风度翩翩，如玉树临风。\n";
		} else if(per >= 25) { 
			str = "英俊潇洒，貌似潘安。\n";
		} else if(per >= 20) {
			str = "长身玉立，面如冠玉。\n";
		} else if(per >= 15) {
			str = "五官端正。\n";
		} else if(per >= 10) {
			str = "的尊容实在无法恭维。\n";
			//str = "虎头虎脑，很机灵的样子。\n";
		} else {
			str = "相貌平平。\n";
		}
	}
	else {
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

string blink(object obj)
{
	string str,pro,*desc;
	object *inv,me=obj;
	if (me->query("gender") == "女性")
		pro = "她";
	else if (me->query("gender") == "男性")
		pro = "他";
	else
		pro = "它";
	str = "";
	str += pro+"看起来是"+chinese_number(me->query("age") / 10 * 10)+"多岁的样子。\n";
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
	return str;
}

int do_mimic(string arg)
{
	object target;
	object me = this_player(),env=environment(me),ob=this_object();
	string sheet, deco;

	if (!arg)
		return notify_fail("指令格式：mimic <目标>\n");
	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (query("text"))
		return notify_fail("这尊雕像已经刻了一个人了。\n");
	target = find_player(arg);
	if( !target ) target = find_living(arg);
	if (!target)
		return notify_fail("你想了半天，还是想不起你要雕刻的人是什么样子。\n");
	sheet = blink(target);
	message_vision(CYN"$N挥舞斧凿，三两下将雕像刻成"+target->name()+CYN"的样子。\n"NOR,me);
	set("text",sheet);
	set("text2",target->name());
	set("name",query("text2")+"的雕像");
	if (!query("text3"))
		set("desc", "这是一尊"+name()+"，你举目看去，只见：\n"+query("text")+"\n");
	else {
		if (query("text3")==1) deco = HIG"翡翠雕龙"NOR;
		else if (query("text3")==2) deco = HIG"珊瑚东君"NOR;
		else deco = WHT"象牙湘妃"NOR;
		set("desc","这是一尊"+name()+"，你举目看去，只见：\n"+query("text")+"  颈上挂着一个小小的"+ deco+"。\n");
	}
		
	reset_item_list(env);
	return 1;
}

int restore_item()
{
	object item, env;
	mapping item_list,mitem;
	string *lists,str, deco;
	int i,idx;

	env = environment();
	item_list = environment()->query("stock_"+query("item_type"));
	
	if (environment()->query("stock_"+query("item_type")+"/text3")){
		set("text3",environment()->query("stock_"+query("item_type")+"/text3"));
		if (query("text3")==1) deco = HIG"翡翠雕龙"NOR;
		else if (query("text3")==2) deco = HIG"珊瑚东君"NOR;
		else deco = WHT"象牙湘妃"NOR;
	}
	
	// 没有任何文字。
	if (!environment()->query("stock_"+query("item_type")+"/text")
		||!environment()->query("stock_"+query("item_type")+"/text2") ) {
		if (!query("text3"))	return 1;
		else 
			set("desc","一个还没有刻上脸庞的雕像，你可以把它刻成你喜欢人的样子（mimic）
  颈上挂着一个小小的"+ deco+"。\n");		
		return 1;
	}
	
	set("text",environment()->query("stock_"+query("item_type")+"/text"));
	set("text2",environment()->query("stock_"+query("item_type")+"/text2"));
	set("name",query("text2")+"的雕像");

	if (!query("text3"))
		set("desc", "这是一尊"+name()+"，你举目看去，只见：\n"+query("text")+"\n");
	else {
		set("desc","这是一尊"+name()+"，你举目看去，只见：\n"+query("text")+"  颈上挂着一个小小的"+ deco+"。\n");
	}	
	return 1;
}

int reset_item_list(object dest)
{
	environment()->set("stock_"+query("item_type")+"/text",query("text"));
	environment()->set("stock_"+query("item_type")+"/text2",query("text2"));
	environment()->set("stock_"+query("item_type")+"/text3",query("text3"));
	environment()->save();
	return 1;
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
