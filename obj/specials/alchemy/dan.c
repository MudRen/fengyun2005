#include <ansi.h>
inherit ITEM;
void generate_name();
void create()
{
	generate_name();
	set_weight(1);
	set("unit", "丸");
	set("long", "一丸微现宝光的仙丹，有急救延命的神效。\n");
	set("value", 100000+ random(1000000));
	set("no_get", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_burn", 1);
	
	set_temp("to_cure", "none");
	set_temp("cure", 5);		
	::init_item();
}

void init(){
	add_action("do_use", "use");
}

int do_use(string arg){
	object me;
	int cure, gin, kee, sen, eff_gin, eff_kee, eff_sen, dan_number;
	string to_cure;
	me = this_player();
	dan_number= (int )me->query_temp("dan_number");
	if(!arg || (arg != "pill" && arg != "dan")){
		return notify_fail("你要用什么？\n");;
	}

	cure = (int) query_temp("cure");
	to_cure = (string) query_temp("to_cure");
	if (!cure) cure =2;
	
	gin = (int) me->query("max_gin");
        kee = (int) me->query("max_kee");
        sen = (int) me->query("max_sen");
	eff_gin = (int) me->query("eff_gin");
        eff_kee = (int) me->query("eff_kee");
        eff_sen = (int) me->query("eff_sen");
	
	
	message_vision( HIG"$N急忙取出一丸$n"HIG"吞入口中，稍时，有微微宝光透出$N体外！！\n" NOR, me, this_object());
   
        
        if (to_cure == "all" ||to_cure == "gin") {
        	if (eff_gin < gin - ((10-cure)*(gin-eff_gin))/10 ) {
        		eff_gin = gin - ((10-cure)*(gin-eff_gin))/10;
        	}
        	me->set("eff_gin",eff_gin);
        	me->set("gin", eff_gin);
        	
        }
        if (to_cure == "all" ||to_cure == "kee") {
        	if (eff_kee < kee - ((10-cure)*(kee-eff_kee))/10 ) {
        		eff_kee = kee - ((10-cure)*(kee-eff_kee))/10;
        	}
        	me->set("kee",eff_kee);
        	me->set("eff_kee",eff_kee);
        }
        if (to_cure == "all" ||to_cure == "sen") {
        	if (eff_sen < sen - ((10-cure)*(sen-eff_sen))/10 ) {
        		eff_sen = sen - ((10-cure)*(sen-eff_sen))/10;
        	}

        	me->set("sen", eff_sen);
        	me->set("eff_sen", eff_sen);
        }

	if (dan_number>0) 
		me->add_temp("dan_number", -1);
	destruct(this_object());
	return 1;
}

void generate_name(){
	string *color = ({HIC, HIG, HIW, HIY, HIR, MAG});
	string *number = ({"三", "七", "四", "九", "六", "元", "五"});
	string *part = ({"灵", "宝", "神","重", "道"});
	string *race = ({"护心", "镇魄","服气", "餐霞", "延年", "驱邪", "安命"});
	set_name( (color[random(sizeof(color))])+(number[random(sizeof(number))]) 
		   + (part[random(sizeof(part))])
		   + (race[random(sizeof(race))])
		   + "丹"NOR, ({ "pill" , "dan"}) );
	
}
