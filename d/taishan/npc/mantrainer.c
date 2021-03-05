// Tie@fy
#include <ansi.h>
#define GOLD_COST 500
#define SCORE_COST 200
inherit NPC;
void create()
{
        set_name("一个黑影", ({ "shadowwoman" }) );
        set("gender", "女性" );
	set("title","～～～～");
        set("age", 332);
        set("long","黑袍，就象是浮现在空中的黑袍．．．\n");
        set("combat_exp", 3000000);
	set("max_force",10000);
	set("arrive_msg","象黑色的浓雾般飘了过来．．．");
	set("leave_msg","逐渐暗淡消逝了．．．");	
	set("force",10000);
	set("force_factor",200);
	set("atman",1000);
	set("max_atman",1000);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();

}

/*
void init()
{	
//        add_action("do_yaoye", "yaoye");
}

int do_yaoye(string arg)
{
	object me,ob,gold;
	int cost;
	string attr,what,prop;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
	if(!arg) return notify_fail("指令格式：yaoye <name> <attribute>\n");
	if(sscanf(arg,"%s %s",what,attr) !=2)
	return notify_fail("指令格式：yaoye <name> <attribute>\n");
	ob = present(what,me);
	if(!objectp(ob)) return notify_fail("你身上没有"+what+"\n");
	if(!ob->query("max_enchant")  )
	return notify_fail(ob->name()+"已经没有办法再妖制冶炼了．\n");
//okey we identified the target, now the cost:
        gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("你身上没有"+chinese_number(GOLD_COST)+"两金子。\n");
        if((int)me->query("score") < SCORE_COST)
        return notify_fail("你的评价不够"+chinese_number(SCORE_COST)+"点。\n");
	if(ob->query("equipped"))
	ob->unequip();
	if(ob->query("weapon_prop")) prop="weapon_prop/";
	else prop="armor_prop/";
	switch (attr){
	case "才智" :
	case "caizhi" :
			ob->add(prop+"intelligence",1);
			break;
        case "体质" :
        case "tizhi" :
			ob->add(prop+"constitution",1);
                        break;
        case "灵性" :
        case "lingxing" :
                        ob->add(prop+"spirituality",1);
                        break;
        case "魅力" :
        case "meili" :
                        ob->add(prop+"personality",1);
                        break;
        case "勇气" :
        case "yongqi" :
                        ob->add(prop+"courage",1);
                        break;
        case "力量" :
        case "liliang" :
                        ob->add(prop+"strength",1);
                        break;
        case "耐力" :
        case "naili" :
                        ob->add(prop+"durability",1);
                        break;
        case "韧性" :
        case "renxing" :
			ob->add(prop+"flexibility",1);
                        break;
        case "速度" :
        case "sudu" :
                        ob->add(prop+"agility",1);
                        break;
        case "气量" :
        case "qiliang" :
                        ob->add(prop+"tolerance",1);
                        break;
        case "运气" :
        case "yunqi" :
                        ob->add(prop+"karma",1);
                        break;
        case "定力" :
        case "dingli" :
                        ob->add(prop+"composure",1);
                        break;
        default :
			return notify_fail("没有办法将"+attr+"妖制冶炼入"+ob->name()+"\n");

	}
	ob->add("max_enchant",-1);
	ob->save();
	gold->add_amount(-GOLD_COST);
	me->add("score",-SCORE_COST);
	message_vision("$N向$n微微点了点头．．．\n",this_object(),me);
	return 1;
}

void unconcious()
{
	int gin,kee,sen;
	gin =(int)query("max_gin");
	kee =(int)query("max_kee");
	sen =(int)query("max_sen");
	set("eff_kee",kee);set("kee",kee);
	set("eff_gin",gin);set("gin",gin);
	set("eff_sen",sen);set("sen",sen);
	return ;

}

void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

*/